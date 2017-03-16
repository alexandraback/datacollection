#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

#define PI pair<int,int>
#define F first
#define S second
#define MP make_pair
#define PB push_back

#define LIM 512
#define EPS 1e-9

int N;
double ans[LIM];
double score[LIM];
double y[LIM];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int cases;
    scanf("%d",&cases);
    for(int tt=1;tt<=cases;tt++){
        //printf("case %d\n",tt);
        scanf("%d",&N);
        vector<PI> v(N+1);
        double s=0.0f;
        for(int i=1;i<=N;i++){
            scanf("%d",&v[i].F);
            v[i].S=i;
            s += (double)v[i].F;
        }
        sort(v.begin(),v.end());
        double z=0.0,n;
        for(int i=N;i>=1;i--){
            n=(double)i;
            y[i]=(2.0*s-z-(n*(double(v[i].F))))/(n*s);
            if(y[i]<EPS) y[i]=0.0;
            score[i]=double(v[i].F)+s*y[i];
            z += score[i];
            ans[v[i].S] = 100.0*y[i];
        }
        printf("Case #%d: ",tt);
        for(int i=1;i<=N;i++) printf("%.6lf ",ans[i]);
        printf("\n");
    }
    return 0;
}
