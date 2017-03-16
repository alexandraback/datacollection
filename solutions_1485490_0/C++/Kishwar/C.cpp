/*
ID: kishwarshafin
PROG:
LANG: C++
*/
/*
Timus JI: 119454XP
*/
#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<queue>
#include<map>
#include<algorithm>
#include<sstream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100
#define INF 2147483647
#define in(a) freopen(a,"r",stdin)
#define out(a) freopen(a,"w",stdout)
#define ULL long long

struct toys{
    ULL type;
    ULL pr;
}T[1001];
struct boxs{
    ULL type;
    ULL pr;
}B[1001];
ULL N,M;
ULL mem[1001][1001];

ULL DP(ULL t_indx,ULL b_indx)
{

    if(t_indx>=N || b_indx>=M)return 0;
    else if(mem[t_indx][b_indx]!=-1)return mem[t_indx][b_indx];
    else
    {
        ULL a=0,b=0,c=0,d=0;

        if(T[t_indx].type==B[b_indx].type)
        {
//            cout<<t_indx<<" "<<b_indx<<" "<<endl;
            if(T[t_indx].pr>B[b_indx].pr)
            {
                T[t_indx].pr-=B[b_indx].pr;
                b=B[b_indx].pr+DP(t_indx,b_indx+1);
                c=B[b_indx].pr+DP(t_indx+1,b_indx+1);
                T[t_indx].pr+=B[b_indx].pr;
            }
            else if(T[t_indx].pr<B[b_indx].pr)
            {
                B[b_indx].pr-=T[t_indx].pr;
                a=T[t_indx].pr+DP(t_indx+1,b_indx);
                c=T[t_indx].pr+DP(t_indx+1,b_indx+1);
                B[b_indx].pr+=T[t_indx].pr;
            }
            else if(T[t_indx].pr==B[b_indx].pr)
            {
                a=T[t_indx].pr+DP(t_indx+1,b_indx+1);
            }
            ULL res=max(a,b);
            res=max(res,c);
            a=DP(t_indx+1,b_indx);
            b=DP(t_indx,b_indx+1);
            c=DP(t_indx+1,b_indx+1);
            res=max(res,a);
            res=max(res,b);
            res=max(res,c);
            mem[t_indx][b_indx]=res;
            return res;
        }
        else
        {
            a=DP(t_indx+1,b_indx);
            b=DP(t_indx,b_indx+1);
            c=DP(t_indx+1,b_indx+1);
            ULL res=max(a,b);
            res=max(res,c);
            mem[t_indx][b_indx]=res;
            return res;
        }
    }

}

void take_input()
{
    memset(mem,-1,sizeof(mem));
    cin>>N>>M;
    for(ULL i=0;i<N;i++)
        cin>>T[i].pr>>T[i].type;
    for(ULL i=0;i<M;i++)
        cin>>B[i].pr>>B[i].type;
    cout<<DP(0,0)<<endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
	in("in.txt");
	out("out.txt");
    #endif

    ULL t,caseno=1;
    cin>>t;
    while(t--)
    {
        printf("Case #%lld: ",caseno++);
        take_input();
    }
	return 0;
}
