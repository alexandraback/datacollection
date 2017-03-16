#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

const long long MOD = 1000000007;

template<class AnswerType>
void PrintAnswerToTestCase(size_t caseNumber, AnswerType ans)
{
    cerr << "Case #" << caseNumber << endl;
    cout << "Case #" << caseNumber << ": " << ans << endl;
}

bool IsValid(const vector<string>& cars, const vector<int>& p) {
    string train;
    for (size_t i = 0; i < cars.size(); i++) {
        train += cars[p[i]];
    }
    vector<bool> finished(26, false);
    vector<bool> started(26, false);
    for (int i = 0; i < train.length(); i++) {
        started[train[i] - 'a'] = true;
        if (i > 0) {
            if (train[i - 1] != train[i]) {
                finished[train[i - 1] - 'a'] = true;
            }
        }
        if (finished[train[i] - 'a']) {
            return false;
        }
    }
    return true;
}

long long Fact(int n) {
    long long ans = 1;
    for (int i = 2; i <= n; i++) {
        ans = (ans * i) % MOD;
    }
    return ans;
}

template <class AnswerType>
AnswerType SolveTestCase() {
    const int alphabetSize = 26;
    int n;
    cin >> n;
    vector<string> cars(n);
    for (int i = 0; i < n; i++) {
        cin >> cars[i];
    }
    
    vector<bool> inside(alphabetSize, false);
    vector<bool> outside(alphabetSize, false);
    for (int i = 0; i < n; i++) {
        outside[cars[i][0] - 'a'] = true;
        outside[cars[i][cars[i].length() - 1] - 'a'] = true;
        int l = 1;
        int r = (int)(cars[i].length()) - 2;
        while (l < cars[i].length() && cars[i][l] == cars[i][l - 1]) {
            l++;
        }
        while (r > -1 && cars[i][r] == cars[i][r + 1]) {
            r--;
        }
        for (int j = l; j <= r; j++) {
            inside[cars[i][j] - 'a'] = true;
        }
        if (l <= r && cars[i][0] == cars[i][cars[i].length() - 1]) {
            return 0;
        }
    }

    for (int i = 0; i < alphabetSize; i++) {
        if (inside[i] && outside[i]) {
            return 0;
        }
    }

    vector< vector<int> > graph(alphabetSize);
    vector<int> freeGroups(alphabetSize, 0);
    vector<int> inDegree(alphabetSize, 0);
    for (int i = 0; i < n; i++) {
        if (cars[i][0] == cars[i][cars[i].length() - 1]) {
            freeGroups[cars[i][0] - 'a']++;
        } else {
            graph[cars[i][0] - 'a'].push_back(cars[i].back() - 'a');
            inDegree[cars[i].back() - 'a']++;
        }
    }
    for (int i = 0; i < graph.size(); i++) {
        if (graph[i].size() > 1 || inDegree[i] > 1) {
            return 0;
        }
    }
    vector<bool> visited(alphabetSize, false);
    int comps = 0;
    for (int i = 0; i < graph.size(); i++) {
        if ((graph[i].size() + freeGroups[i] > 0) && inDegree[i] == 0) {
            comps++;
            visited[i] = true;
            int next = i;
            while (graph[next].size() == 1) {
                next = graph[next][0];
                if (visited[next]) {
                    return 0;
                }
                visited[next] = true;
            }
        }
    }

    for (int i = 0; i < graph.size(); i++) {
        if ((graph[i].size() + freeGroups[i] > 0) && !visited[i]) {
            return 0;
        }
    }

    long long ans = Fact(comps);
    for (int i = 0; i < alphabetSize; i++) {
        ans = (ans * Fact(freeGroups[i])) % MOD;
    }

    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("B-small.in", "r", stdin);
    freopen("B-large.in", "r", stdin);

    freopen("output.txt", "w", stdout);

    int numCases;
    cin >> numCases;

    for (int caseNumber = 1; caseNumber <= numCases; caseNumber++)
        PrintAnswerToTestCase(caseNumber, SolveTestCase<int>());

    return 0;
}