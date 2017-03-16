#include<bits/stdc++.h>
using namespace std;

typedef long long int lol;
typedef unsigned long long int ull;


#define cin fin
#define cout fout
#define pb push_back
#define mp make_pair


lol dp[1000007];
lol INF=999999999;


lol foo(lol n,lol curr);


int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("A-small-attempt0.in");
    fout.open("output.txt");
    int test_case;
    cin>>test_case;

    for(int h=1;h<=test_case;h++)
    {
        cout<<"Case #"<<h<<": ";
        lol n;
        cin>>n;
        memset(dp,-1,sizeof(dp));
        cout<<foo(n,1)<<"\n";
    }
    return 0;
}



lol foo(lol n,lol curr)
{
    if(curr==n) return 1;
    if(curr>n) return INF;

    if(dp[curr]!=-1) return dp[curr];

    lol num=0;
    lol temp=curr;
    while(temp)
    {
        num=num*10;
        num=num+temp%10;
        temp/=10;
    }
    lol val;
    if(num<=curr) val=1+foo(n,curr+1);
    else val=1+min(foo(n,curr+1),foo(n,num));
    return dp[curr]=val;
}
