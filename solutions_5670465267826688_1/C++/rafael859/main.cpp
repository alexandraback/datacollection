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
#define MAXN 10010
#define llint long long

string str;
int N, K, top;
//bool a[MAXN];

void Debug()
{
}

void Read()
{
    string in;
    llint k;
    cin >> N >> k;
    K = k%144LL;
    str.clear();
    cin >> in;
    for(int i=1; i<=K; ++i)
        str += in;
    N = N*K;
    top=0;
}

bool Check(int cnt0, int cnt1, bool sign, int want)
{
    bool has0 = (cnt0%2==1);
    bool has1 = (cnt1%2==1);
    if(cnt0%4==2 || cnt0%4==3)
        sign^=true;
    if(cnt1%4==2 || cnt1%4==3)
        sign^=true;

    if(sign)
        return false;
    if(want==0 && has0 && !has1)
        return true;
    if(want==1 && !has0 && has1)
        return true;
    if(want==2 && has0 && has1)
        return true;
    return false;
}

bool Solve()
{
    int cnt0 = 0, cnt1=0;
    bool sign=0, has0=0, has1=0, flag0=0, flag1=0;
    for(int i=0; i<N; ++i)
    {
        if(str[i]=='i')
        {
 //           a[++top] = 0;
            sign^=(cnt1%2==1);
            ++cnt0;
        }
        else if(str[i]=='j')
        {
   //         a[++top] = 1;
            ++cnt1;
        }
        else
        {
     //       a[++top] = 0;
            sign^=(cnt1%2==1);
       //     a[++top] = 1;
            ++cnt0;
            ++cnt1;
        }
        if(flag0 == false && Check(cnt0, cnt1, sign, 0))
        {
            flag0 = true;
            sign = false;
            cnt0=0;
            cnt1=0;
        }
        else if(flag0 == true && flag1 == false && Check(cnt0, cnt1, sign, 1))
        {
            flag1 = true;
            sign = false;
            cnt0=0;
            cnt1=0;
        }
    }

    if(flag0 && flag1 && Check(cnt0, cnt1, sign, 2))
        return true;
    return false;

//    printf("cnt0: %d, cnt1: %d, has0: %d, has1: %d, sign: %d\n", cnt0, cnt1, has0, has1, sign);

/*    if(K%2==0)
    {
        sign=false;
        if(K%4==2)
        {
            sign=true;
        }
        has0=0;
        has1=0;
    }
    else if(K%2==1)
    {
        if(K%4==3)
            sign^=true;
    }*/

    if(has0==0 && has1==0 && sign==true)
        return true;
    return false;
}

int main()
{
    int t;
    cin >> t;
    for(int i=1; i<=t; ++i)
    {
        Read();
        if(Solve())
            printf("Case #%d: YES\n", i);
        else
            printf("Case #%d: NO\n", i);
        Debug();
    }
    return 0;
}
