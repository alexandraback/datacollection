#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define verify(x) if (!(x)) { cerr << "VERIFY FAIL" << endl; exit(1); }

long long reverse(long long value)
{
    string sv = to_string(value);
    ostringstream out;
    out << string(sv.rbegin(), sv.rend());
    long long result = stoll(out.str());
    return result;
}

vector<long long> precalc()
{
    const int N = (int)1e+6;
    vector<long long> res(N + 1, 0);
    res[1] = 1;
    vector<int> Q = {1};
    Q.reserve(N);
    for (int i = 0; i < Q.size(); ++i)
    {
        int cur = Q[i];
        if (cur <= N && res[cur + 1] == 0)
        {
            res[cur + 1] = res[cur] + 1;
            Q.push_back(cur + 1);
        }
        int ruc = reverse(cur);
        if (ruc <= N && res[ruc] == 0)
        {
            //cerr << cur << " -> " << ruc << endl;
            res[ruc] = res[cur] + 1;
            Q.push_back(ruc);
        }
    }
    return res;
}

long long simpleSolve(long long N)
{
    static vector<long long> answers = precalc();
    verify(N < answers.size());
    return answers[N];
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int testId = 1; testId <= T; ++testId)
    {
        long long N;
        cin >> N;
        cout << "Case #" << testId << ": " << simpleSolve(N) << endl;
    }

    return 0;
}
