#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <set>
#include <stack>
#include <vector>
#include <map>
#include <queue>
#include <sstream>
#include <assert.h>
#define mod 1000000009
#define INF 1e9
using namespace std;
int check(int num , long long mul)
{
    int mask=0;
    for(long long i =1;i<=mul;i++ )
    {
        long long res = i * num;
        long long temp = res;
        do{
            mask|=(1<<(temp%10));
            if(mask == (1<<10)-1)
                return i;
            temp/=10;
        }while(temp>0);
    }
    return 0;
}
int main () {

    freopen ("a.in", "r", stdin);
    freopen ("output.txt","w",stdout);
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.sync_with_stdio(false);
    int t,tc=1;
    cin >> t;
    while(t--)
    {
        int n ;
        cin >> n;
        cout << "Case #"<<tc++<<": ";
        if(n ==0)
            cout <<"INSOMNIA"<<endl;
        else
            cout << check(n,80LL)*1LL*n <<endl;
    }
    return 0;
}

