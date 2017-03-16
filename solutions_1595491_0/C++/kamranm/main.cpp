#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <fstream>
#include <set>
#include <map>
#include <cmath>
#pragma comment(linker,"/STACK:16777216")
#define inf 1000000000
#define MP make_pair
#define PI acos(-1.0)
#define eps 1e-9
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
vector<int> SP[31],NS[31];
int T[110],dp[110][110];

bool f(int a,int b,int c){
    return (a<=10&&b<=10&&c<=10);
}

int c(int a,int b,int c){
    return (a+b+c);
}

void init(){
    for(int x=0;x<=10;x++){
        if(f(x,x,x))NS[c(x,x,x)].push_back(x);
        if(f(x,x,x+1))NS[c(x,x,x+1)].push_back(x+1);
        if(f(x,x+1,x+1))NS[c(x,x+1,x+1)].push_back(x+1);
        if(f(x,x,x+2))SP[c(x,x,x+2)].push_back(x+2);
        if(f(x,x+1,x+2))SP[c(x,x+1,x+2)].push_back(x+2);
        if(f(x,x+2,x+2))SP[c(x,x+2,x+2)].push_back(x+2);
    }
}

int main()
{

    init();

    int NT,N,S,P,t;

    ifstream cin("B-small-attempt0.in");
    ofstream cout("output.txt");

    cin>>NT;

    for(int ts=1;ts<=NT;ts++){
        cin>>N>>S>>P;
        for(int i=1;i<=N;i++)cin>>T[i];
        sort(T+1,T+(N+1));

        memset(dp,-1,sizeof(dp));

        dp[0][0]=0;

        for(int i=1;i<=N;i++){
            t=T[i];
            for(int j=0;j<NS[t].size();j++){
                if(dp[i-1][0]!=-1){dp[i][0]=max(dp[i][0],dp[i-1][0]+(NS[t][j]>=P));}
            }
            for(int s=1;s<=i;s++){
                for(int j=0;j<NS[t].size();j++)
                    if(dp[i-1][s]!=-1){dp[i][s]=max(dp[i][s],dp[i-1][s]+(NS[t][j]>=P));}

                for(int j=0;j<SP[t].size();j++)
                    if(dp[i-1][s-1]!=-1){dp[i][s]=max(dp[i][s],dp[i-1][s-1]+(SP[t][j]>=P));}
            }
        }
        cout<<"Case #"<<ts<<": "<<dp[N][S]<<endl;
    }
    cin.close(); cout.close();
    return 0;
}
