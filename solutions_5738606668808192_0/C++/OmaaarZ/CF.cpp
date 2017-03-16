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
//#define mod 1000000009
#define INF 1e9
#define mod 11
using namespace std;
//int dp[32][mod][mod][mod][mod][mod];
int arr[]={2,3,5,7,11,13};
vector<string >ans;
int dp[33][2][3][5][7][11][13];
int powe(int base ,int p ,int mode)
{
    if(p == 0)
        return 1;
    if( p & 1)
        return (base * powe(base,p-1,mode) %mode);
    int x = powe(base,p/2,mode);
    x*=x;
    x%=mode;
    return x;
}
bool check(string s)
{
    for(int j = 2;j<=10;j++)
    {
        bool ch = false;
        for(int k = 0 ;k  <6 ;k++)
        {
            int temp =0;
            for(int i = 0 ;i  <16;i++)
            {

                temp*=j;
                temp+=(s[i]=='1');
                temp%=arr[k];
            }
            ch = ch ||(temp ==0);
        }
        if(!ch)
            return false;
    }
    return true;
}

int solve(int n , int rem1,int rem2,int rem3 ,int rem4,int rem5,int rem6,string s)
{
    if(n ==0)
    {
        return (rem1*rem2*rem3*rem4*rem5*rem6 ==0)  && check(s);
    }
    if(dp[n][rem1][rem2][rem3][rem4][rem5][rem6]!=-1)
        return dp[n][rem1][rem2][rem3][rem4][rem5][rem6];
    if(n ==16)
        return dp[n][rem1][rem2][rem3][rem4][rem5][rem6] = solve(n-1,1,1,1,1,1,1,s+"1");
    if(n==1)
        return dp[n][rem1][rem2][rem3][rem4][rem5][rem6] = solve(n-1,((9*rem1)+1)%2,((9*rem2)+1)%3,((9*rem3)+1)%5,((9*rem4)+1)%7,((9*rem5)+1)%11,((9*rem6)+1)%13,s+'1');
    return dp[n][rem1][rem2][rem3][rem4][rem5][rem6] = solve(n-1,(rem1*9)%2,(rem2*9)%3,(rem3*9)%5,(rem4*9)%7,(rem5*9)%11,(rem6*9)%13,s+"0") + solve(n-1,((9*rem1)+1)%2,((9*rem2)+1)%3,((9*rem3)+1)%5,((9*rem4)+1)%7,((9*rem5)+1)%11,((9*rem6)+1)%13,s+'1');
}
void dfs(int n , int rem1,int rem2,int rem3 ,int rem4,int rem5,int rem6,string s)
{
    if(n==0)
    {
        if(check(s))
            ans.push_back(s);
        return;
    }
    if(ans.size()>50)
        return;
    if(n ==16)
        return dfs(n-1,1,1,1,1,1,1,s+"1");
    if(n==1)
        return dfs(n-1,((9*rem1)+1)%2,((9*rem2)+1)%3,((9*rem3)+1)%5,((9*rem4)+1)%7,((9*rem5)+1)%11,((9*rem6)+1)%13,s+'1');
    if(dp[n-1][(rem1*9)%2][(rem2*9)%3][(rem3*9)%5][(rem4*9)%7][(rem5*9)%11][(rem6*9)%13]>0)
        dfs(n-1,(rem1*9)%2,(rem2*9)%3,(rem3*9)%5,(rem4*9)%7,(rem5*9)%11,(rem6*9)%13,s+"0");
    if(dp[n][rem1][rem2][rem3][rem4][rem5][rem6] -dp[n-1][(rem1*9)%2][(rem2*9)%3][(rem3*9)%5][(rem4*9)%7][(rem5*9)%11][(rem6*9)%13])
        dfs(n-1,((9*rem1)+1)%2,((9*rem2)+1)%3,((9*rem3)+1)%5,((9*rem4)+1)%7,((9*rem5)+1)%11,((9*rem6)+1)%13,s+'1');


}
int main () {

    freopen ("c.in", "r", stdin);
    freopen ("output.txt","w",stdout);
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.sync_with_stdio(false);
    memset(dp,-1,sizeof dp);
    int t;
    cin >>t;
    cin >> t >>t;
    solve(16,0,0,0,0,0,0,"");
    cout << "Case #1:"<<endl;
    dfs(16,0,0,0,0,0,0,"");
    for(int z =0  ;z  <50;z++)
    {
        cout <<ans[z];
        for(int j = 2;j<=10;j++)
        {
            for(int k = 0 ;k  <6 ;k++)
            {
                int temp =0;
                for(int i = 0 ;i  <16;i++)
                {

                    temp*=j;
                    temp+=(ans[z][i]=='1');
                    temp%=arr[k];
                }
                if(temp==0)
                {
                    cout <<" " << arr[k];
                    break;
                }
            }
        }
        cout <<endl;
    }
    //dfs(14,"");
    //cout <<ans.size() <<endl;
//    int t,tc=1;
//    cin >> t;
//    while(t--)
//    {
//        string s;
//        cin >> s;
//        int counter=0;
//        for(int i =s.size()-1  ;i >= 0;i-- )
//        {
//            if((s[i]=='+'&&counter&1) || (s[i]=='-'&&!(counter&1)))
//                counter++;
//        }
//        cout << "Case #"<<tc++<<": ";
//        cout << counter <<endl;
//
//    }
    return 0;
}

