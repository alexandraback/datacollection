#include<iostream>
#include<algorithm>
#include<cmath>
#include<math.h>
#include<string>
#include<fstream>
#include<vector>
#include<set>
#include<stdio.h>
#include<map>
#include<queue>
#include<stack>
using namespace std;
#define REPN(i,N) for(int i=0;i<N;i++)
#define FORa(i,a,N) for(int i=a;i<N;i++)
#define FORs(i,a,s,N) for(int i=a;i<N;i+=s)
#define vi vector<int>
#define vii vector< vector<int> >
#define LL long long

ifstream fin("Asmall.in");
//ifstream fin("ALarge.in");
ofstream fout("Asmall.out");
//ofstream fout("ALarge.out");

int main()
{
    int T;
    LL r,paint;
    fin>>T;
    FORa(t,1,T+1)
    {
        fin>>r>>paint;
        LL rb=r+1;
        fout<<"Case #"<<t<<": ";
        LL ans=0;
        while(paint)
        {
           if(paint-(rb*rb-r*r)<0)break;
           paint-=(rb*rb-r*r);
           ans++;
           r+=2;
           rb+=2;
        }
        fout<<ans<<endl;
    }
    return 0;
}
