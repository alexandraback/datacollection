#include<cmath>
#include<cstdio>
#include<cctype>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

#define sqr(a) (a)*(a)
#define cub(a) (a)*(a)*(a)
#define for1(i,a,b) for(i=(a);i<(b);i++)
#define for2(i,a,b) for(i=(a);i>(b);i--)
#define same(a) memset((a),0,sizeof(a));
#define ll long long

int cmpint(const void*a,const void *b)
{
    if(((int*)a)[0]==((int*)b)[0])
      return ((int*)b)[2]-((int*)a)[2];
    return ((int*)a)[0]-((int*)b)[0];
}

int a[100005][3];
int b[100005][3];
int c[100005];

typedef struct tem{
    int a,b,c;
    bool operator <(const tem &other) const
      { return c<other.c;}
};
tem ts;
int main()
{
    int i,j,n,m,k,l,o,p;
    freopen("B-small-attempt6.in","r",stdin);
    freopen("B-small-attempt6.out","w",stdout);
    scanf("%d",&p);
    for1(o,1,p+1){
        priority_queue<tem> q;
        scanf("%d",&n);
        for1(i,0,n){
          scanf("%d%d",&a[i][0],&b[i][0]);
          a[i][1]=i;
          b[i][1]=i;
          a[i][2]=b[i][0];
          b[i][2]=a[i][0];
        }
        qsort(a,n,sizeof(int)*3,cmpint);
        qsort(b,n,sizeof(int)*3,cmpint);
       // printf("%d %d %d\n",n,b[0][0],b[0][2]);
        same(c);
        int now=0;
        int ans=0;
        bool flag=true;
        i=0;j=0;
        while(flag){
            while(j<n&&b[j][0]<=now){
                k=b[j][1];
                if(c[k]==0){
                    j++;
                    ans++;
                    now+=2;
                    c[k]=2;
                }
                else if(c[k]==1){
                    j++;
                    ans++;
                    now++;
                    c[k]=2;
                }
                //printf("j i=%d now=%d\n",i,now);
            }
            if(j==n) break;

            while(i<n&&a[i][0]<=now){
                k=a[i][1];
                if(c[k]==2) i++;
                else {
                    ts.a=a[i][0];
                    ts.b=a[i][1];
                    ts.c=a[i][2];
                    q.push(ts);
                    i++;
                } //printf("tyest\n");
            }
            if(q.empty()){
                flag=false;
                break;
            }
            else{
                ts=q.top();
                q.pop();
                k=ts.b;
                while(c[k]==2){
                    if(q.empty()){
                        flag=false;
                        break;
                    }
                    ts=q.top();
                    q.pop();
                    k=ts.b;
                }
                if(!flag) break;
                c[k]=1;
                ans++;
                now++;
            }
        }
        if(!flag) printf("Case #%d: Too Bad\n",o);
        else printf("Case #%d: %d\n",o,ans);
    }
    return 0;
}
