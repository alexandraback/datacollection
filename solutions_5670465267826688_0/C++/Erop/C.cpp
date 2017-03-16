#define _CRT_SECURE_NO_WARNINGS

#include <thread>
#include <condition_variable>
#include <mutex>

#include <memory>

#include <vector>
#include <queue>

#include <cstdio>

#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

#pragma comment(linker, "/STACK:167772160")

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 1e9;
const double EPS = 1e-9;
const double PI = acos(-1.);



struct TResult {
    bool ans;
    void PrintToStdout(size_t index) {
        printf("Case #%d: %s\n", index + 1, ans ? "YES" : "NO");
    }
};

const int I = 2;
const int J = 3;
const int K = 4;

int M[5][5] = {
//    0  1  I  J  K 
/*0*/{0, 0, 0, 0, 0},
/*1*/{0, 1, I, J, K},
/*I*/{0, I, -1, K, -J},
/*J*/{0, J, -K, -1, I},
/*K*/{0, K, J, -I, -1},
};

struct TInput {
    int L, X;
    string s;
    void ReadFromStdin() {
        char buff[10100];
        scanf("%d%d%s", &L, &X, &buff);
        s = buff;
    }

    int char2val(char c) {
        switch(c) {
            case 'i':
                return I;
            case 'j':
                return J;
            case 'k':
                return K;
        }
        throw 42;
    }

    int multiply(int a, int b) {
        int f = 1;
        if (a < 0) {
            a = -a;
            f = -f;
        }
        if (b < 0) {
            b = -b;
            f = -f;
        }
        return f*M[a][b];
    }

    void Run(TResult& result) {
        if (X > 10) {
            X = 10 + (X - 10) % 4;
        }
        string sx = s;
        for (int i = 1; i < X; ++i) {
            sx += s;
        }

        int mult = 1;
        int seq[4] = {I, K, -1, 0};
        int pos = 0;
        for (int i = 0; i < sx.length(); ++i) {
            char c = sx[i];
            mult = multiply(mult, char2val(c));
            if (seq[pos] == mult)
                ++pos;
        }
        result.ans = (pos == 3 && mult == -1);
    }
};

typedef shared_ptr<TResult> TResultPtr;
typedef shared_ptr<TInput> TInputPtr;

class TResultQueue {
    struct TResultQueueItem {
        TResultPtr Result;
        size_t Index;

        TResultQueueItem(const TResultPtr& result, size_t index)
            : Result(result)
            , Index(index)
        { 
        }

        bool operator < (const TResultQueueItem& other) const {
            return Index > other.Index;
        }
    };

    size_t NextIndex;
    priority_queue<TResultQueueItem> ResultQueue;
    mutex Sync;

public:
    TResultQueue()
        : NextIndex(0)
    {}

    void Push(TResultPtr result, size_t index) {
        lock_guard<mutex> g(Sync);
        ResultQueue.push(TResultQueueItem(result, index));
        while (ResultQueue.size() > 0 && ResultQueue.top().Index == NextIndex) {
            TResultQueueItem item = ResultQueue.top();
            item.Result->PrintToStdout(item.Index);
            ++NextIndex;
            ResultQueue.pop();
            if ((NextIndex >= 10000 && NextIndex % 100 == 0) || (NextIndex < 10000 && NextIndex >= 1000 && NextIndex % 10 == 0) || (NextIndex < 1000)) {
                cerr << "\r" << NextIndex << "     ";
            }
        }
    }
};

class TJobQueue {
    typedef pair<TInputPtr, size_t> TInputQueueItem;
    queue<TInputQueueItem> InputQueue;
    bool IsRunning;
    size_t JobIndex;

    typedef shared_ptr<thread> TThreadPtr;
    vector<TThreadPtr> Threads;

    mutex Sync;

    TResultQueue ResultQueue;

    void operator() () {
        TInputQueueItem job;
        while (GetNewJob(job)) {
            TResultPtr result(new TResult);
            job.first.get()->Run(*result.get());
            ResultQueue.Push(result, job.second);
        }
    }

    bool GetNewJob(TInputQueueItem& resJob) {
        lock_guard<mutex> g(Sync);
        if (InputQueue.empty())
            return false;
        resJob = InputQueue.front();
        InputQueue.pop();
        return true;
    }

public:
    TJobQueue()
        : IsRunning(false)
        , JobIndex(0)
    {
    }

    void Push(TInputPtr input) {
        _ASSERT(!IsRunning);
        InputQueue.push(make_pair(input, JobIndex));
        ++JobIndex;
    }

    void F(){};

    void Run(size_t numThreads) {
        IsRunning = true;
        if (numThreads == 1) {
            (*this)();
            return;
        }
        for (size_t i = 0; i < numThreads; ++i) {
            Threads.push_back(TThreadPtr(new thread(&TJobQueue::operator(), this)));
        }
        for (const auto& t : Threads) {
            t->join();
        }
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    TJobQueue jobQueue;
    for (int i = 0; i < T; ++i) {
        TInputPtr in(new TInput);
        in->ReadFromStdin();
        jobQueue.Push(in);
    }
    jobQueue.Run(4);
    return 0;
}