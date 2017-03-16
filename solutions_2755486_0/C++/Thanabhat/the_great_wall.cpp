/*
LANG: C++
*/

#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<functional>
#include<vector>
#include<list>
#include<set>
#include<queue>
#include<map>
#include<cctype>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
#include<ctime>

#define pii pair<int,int>

using namespace std;

int wall[5000];
int new_wall[5000];

int solve(int cc){
    int N;
    int d[10],n[10],w[10],e[10],s[10],d_d[10],d_p[10],d_s[10];
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d %d %d %d %d %d %d %d",&d[i],&n[i],&w[i],&e[i],&s[i],&d_d[i],&d_p[i],&d_s[i]);
        w[i]+=1000;
        e[i]+=1000-1;
    }
    for(int i=0;i<=2000;i++)
        wall[i]=0;
    for(int i=0;i<=2000;i++)
        new_wall[i]=wall[i];
    vector<pii > vt;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<n[i];j++)
            vt.push_back(pii(d[i]+d_d[i]*j,i));
    }
    sort(vt.begin(),vt.end());
    printf("Case #%d: ",cc);
//    for(int i=0;i<vt.size();i++)
//        printf("%d %d\n",vt[i].first,vt[i].second);
//    printf("\n");
    int sol=0;
    int last_d=vt[0].first;
    for(int i=0;i<vt.size();i++)
    {
        //increase after end of day
        if(vt[i].first>last_d)
        {
            last_d=vt[i].first;
            for(int j=0;j<=2000;j++)
                wall[j]=new_wall[j];
        }

        //init
        int tr=vt[i].second;
        int nn=0;
        for(int j=0;j<n[tr];j++)
            if(d[tr]+d_d[tr]*j==vt[i].first)
                nn=j;
        int ww=w[tr]+d_p[tr]*nn;
        int ee=e[tr]+d_p[tr]*nn;
        int ss=s[tr]+d_s[tr]*nn;

        //check whether attack successful
        bool suc=false;
        for(int j=ww;j<=ee;j++)
            if(wall[j]<ss)
                suc=true;
        if(suc)
            sol++;

        //adjust new wall height
        for(int j=ww;j<=ee;j++)
            new_wall[j]=max(new_wall[j],ss);

//        printf("day=%d,tribe=%d,str=%d,ww=%d,ee=%d,sol=%d\n",vt[i].first,tr,ss,ww,ee,sol);
    }

    printf("%d\n",sol);


    return 1;
}

int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
        solve(i);

	return 0;
}
