/*
    xxx_joker/codersumit
*/
#include <bits/stdc++.h>
#define bitcnt(x) __builtin_popcountll(x)
#define sd(a) scanf("%d",&a)
#define sld(a) scanf("%lld",&a)
#define ss(a) scanf("%s",a)
#define sc(a) scanf("%c",&a)
#define pd(a) printf("%d",a)
#define ps(a) printf("%s",a)
#define pc(a) printf("%c",a)
#define space printf(" ");
#define nw printf("\n")
#define pb push_back
#define FOR(i,a,b) for(i=a;i<b;i++)
#define FORR(i,a,b) for(i=a;i>=b;i--)
#define all(v) v.begin(),v.end()
#define MAX 1000005
#define MAXX 1<<13
#define inf 1e9
#define mod 1000000007

typedef long long ll;
typedef unsigned long long ull;
using namespace std;
inline void fastread(int *a)
{
 register char c=0;
 while (c<33) c=getchar();
 *a=0;
 while (c>33)
 {
     *a=*a*10+c-'0';
     c=getchar();
 }
}
int dist[MAX],visit[MAX];
/*int dfs(int num){
    cout<<"num= "<<num<<endl;
    if(num<=1)
        return 1;
    if(ans[num]!=-1)
        return ans[num];
    int rev,temp,a,b,dig,flag=0;
    a=b=1e8;
    if(visit[num-1]==0){
        visit[num-1]=1;
        a=1+dfs(num-1);
    }
    temp=num;
    rev=0;
    while(temp>0){
        dig=temp%10;
        if(dig==0 && flag==0){
            temp/=10;
            continue;
        }
        else if(dig!=0)
            flag=1;
        rev=(rev*10)+dig;
        temp/=10;
    }
    //cout<<"rev= "<<rev<<endl;
    if(visit[rev]==0){
        visit[rev]=1;
        b=1+dfs(rev);
    }
    a=min(a,b);
    ans[num]=a;
    return a;
}*/
queue<int> q;
int main(){//while(1){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int test,k=1,dig,flag;
    int ans,num,temp,t,a,rev;
    sd(test);
    while(test--){
        sd(num);
        memset(visit,0,sizeof(visit));
        //memset(ans,-1,sizeof(ans));
        while(!q.empty())
            q.pop();
        visit[1]=1;
        q.push(1);
        dist[1]=1;
        while(!q.empty()){
            temp=q.front();
            q.pop();
            //cout<<"temp= "<<temp<<" dist= "<<dist[temp]<<endl;
            if(temp==num){
                ans=dist[temp];
                break;
            }
            a=temp+1;
            t=temp;
            flag=0;
            rev=0;
            while(t>0){
                dig=t%10;
                if(dig==0 && flag==0){
                    t/=10;
                    continue;
                }
                else if(dig!=0)
                    flag=1;
                rev=(rev*10)+dig;
                t/=10;
            }
            if(visit[a]==0){
                visit[a]=1;
                q.push(a);
                //cout<<"a= "<<a<<endl;
                dist[a]=dist[temp]+1;
                //cout<<"dist= "<<dist[a]<<endl;
            }
            if(visit[rev]==0){
                visit[rev]=1;
                q.push(rev);
                dist[rev]=dist[temp]+1;
            }
        }
        printf("Case #%d: %d\n",k,ans);
        k++;
    }
    return 0;
}
