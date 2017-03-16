#include <iostream>
#include <cstdio>
#include <map>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;

int N,M,R,K,mul[50];
int num[15],sot[15];
map<int,int> has;
map<int,double> state;

int dfs2(int mul,int h,int up)
{
    if(mul>up) return 0;
    if(h==N)
    {
        if(mul==up) return 1;
        return 0;
    }
    int ret=0;
    ret+=dfs2(mul*num[h],h+1,up);
    ret+=dfs2(mul,h+1,up);
    return ret;
}

double fengbu()
{
    double score=0.0;
    for(map<int,int>::iterator it=has.begin();it!=has.end();it++)
    {
        int key=it->first;
        int num=dfs2(1,0,key);
        double expt=(double)1.0*num/(double)(1<<N)*K;
        if(num==0) return 0;
        score+=1.0/(1.0+(double)(expt-it->second)*(expt-it->second));
    }
    return score;
}

void dfs(int h,double P)
{
    //cout<<"a"<<endl;
    if(h==N)
    {
        for(int i=0;i<N;i++) sot[i]=num[i];
        sort(sot,sot+N);
        int key=0;
        for(int i=0;i<N;i++) key=key*10+sot[i];
        if(state.find(key)!=state.end())
        {
            state[key]+=fengbu()*P;
        }
        else
        {
            state.insert(pair<int,double>(key,fengbu()*P));
        }
        return;
    }
    for(int i=2;i<=M;i++)
    {
        num[h]=i;
        dfs(h+1,P/(double)(M-1));
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        printf("Case #%d:\n",cas);
        scanf("%d%d%d%d",&R,&N,&M,&K);
        while(R--)
        {
            has.clear();
            //cout<<"a1"<<endl;
            for(int i=0;i<K;i++)
            {
                scanf("%d",&mul[i]);
                if(has.find(mul[i])!=has.end()) has[mul[i]]++;
                else has.insert(pair<int,int>(mul[i],1));
            }
            //cout<<"a0"<<endl;
            state.clear();
            //cout<<"a"<<endl;
            dfs(0,1.0);

            double ans=-10.0;
            int put=222;

            for(map<int,double>::iterator it=state.begin();it!=state.end();it++)
            {
                //cout<<"a"<<endl;
                if((it->second)>ans)
                {
                    ans=it->second;
                    put=it->first;
                }
            }
            printf("%d\n",put);
        }
    }
    return 0;
}
