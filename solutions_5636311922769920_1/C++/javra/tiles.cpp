#include <cstring>
#include <cmath>
#include <climits>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
using namespace std;
typedef long long int llint;
typedef unsigned long long ullint;

#define debug(s) cout << "*** " << (s) << " ***\n"


ullint ipow(ullint b, ullint e)
{
    if(b == 0)
        return 1;

    int r = 1;
    while(e > 0)
    {
        if(e % 2 == 1)
            r *= b;
        e /= 2;
        b *= b;
    }
    return r;
}


void solve()
{
    int K,C,S;
    cin >> K >> C >> S;

    if(K == 1)
    {
        cout << 1;
        return;
    }
    if(C == 1)
    {
        if(S < K)
        {
            cout << "IMPOSSIBLE";
            return;
        }
        for(int i = 1; i <= K; i++)
        {
            cout << i;
            if(i != K)
                cout << " ";
        }
        return;
    }

    vector<ullint> answers;

    ullint answer = 0;
    int position = 0;
    for(int digit = 0; digit < K; digit++)
    {
        answer += digit;
        position += 1;
        if(position >= C || digit == K - 1)
        {
            answers.push_back(answer + 1);
            answer = 0;
            position = 0;
        }
        else
        {
            answer *= K;
        }
    }
    if(answers.size() > S)
    {
        cout << "IMPOSSIBLE";
        return;
    }
    for(int i = 0; i < answers.size(); i++)
    {
        cout << answers[i];
        if(i < answers.size() + 1)
            cout << " ";
    }
}

int main()
{
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++)
    {
        cout << "Case #" << t << ": ";
        solve();
        cout << endl;
    }
    return 0;
}

