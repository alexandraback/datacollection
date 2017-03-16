#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <math.h>
#include <iostream>

using namespace std;

#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define piii pair<pair<int,int>,int>
#define pii pair<int,int>
#define pdd pair<double,double>

int N;
string str;

void Debug()
{
}

void Read()
{
    cin >> N >> str;
}

void Solve()
{
    int out =0, cnt = 0;
    for(int i=0; i<=N; ++i)
    {
        if(cnt < i)
        {
            out += i-cnt;
            cnt = i;
        }
        cnt += (str[i]-'0');
    }
    cout << out << "\n";
}

int main()
{
    int t;
    cin >> t;
    for(int i=1; i<=t; ++i)
    {
        Read();
        printf("Case #%d: ", i);
        Solve();
        Debug();
    }
    return 0;
}
