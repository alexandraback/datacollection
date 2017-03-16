//Author: Tusshar Singh
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>
#include<sstream>

using namespace std;

#define mod 1000000007
#define inf 2147483647
#define ninf -2147483648
#define FOR(i,a,b) for(i=a;i<b;i++)
#define s(a) scanf("%d",&a)
#define lls(a) scanf("%lld",&a)
#define ss(a) scanf("%s",a)
#define p(a) printf("%d",a)
#define llp(a) printf("%lld",a)
#define sp(a) printf("%s",a)
#define cp(a) printf("%c",a)
#define nline printf("\n")
#define space printf(" ")
#define ll long long
string tostr(long long x)
{
    stringstream ss;
    ss << x;
    return ss.str();
}

int palin(string s)
{
    int len=s.size();
        for(int i=0;i<len/2;i++)
        {
            if(s[i]!=s[len-i-1])
            return 0;
        }
        return 1;
}
int main()
{
    long long i,j,k,t=0;
    FILE *fw;
    fw=fopen("Fair_and_Square.txt","w");
    for(i=0;i<=10000000;i++)
    {
        if(palin(tostr(i)))
        {
            if(palin(tostr(i*i)))
            {
                fprintf(fw,"%lld\n",i*i);
                t++;
            }
        }
    }
    return 0;
}
