#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
#define A first
#define B second
#define pii pair<int,int>
#define mp make_pair
const int maxn=1100000;
char st[maxn];
int n,len;
int b[200];
int a[maxn];
pii c[maxn];
ll ans;
int tot;
void run(){
    tot=0; ans=0;
    if (b[st[0]]) a[0]=0; else a[0]=1;
    for (int i=1; i<len; i++)
        if (b[st[i]]) {
            //cout<<i<<' '<<st[i]<<endl;
            a[i]=0;
            if (a[i-1]==0) continue;
            //cout<<i<<' '<<a[i-1]<<endl;
            if (a[i-1]>=n)
            c[tot++]=mp(i-a[i-1],i-1);
        } else
        a[i]=a[i-1]+1;

    if (a[len-1]!=0&&a[len-1]>=n)
    c[tot++]=mp(len-a[len-1],len-1);
    //for (int i=0; i<tot;i++)
    //cout<<c[i].A<<' '<<c[i].B<<endl;
    for (int i=0; i<len; i++){
        pii left=mp(i,0);
        int t=lower_bound(c,c+tot,left)-c;
        if (t-1>=0)
            if (c[t-1].B-i+1>=n){
                ans+=len-(i+n)+1;
                continue;
            }
        if (t<tot)
        ans+=len-(c[t].A+n)+1;
    }
}

int main(){
    b['a']=1; b['e']=1; b['i']=1;
    b['o']=1; b['u']=1;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T; cin>>T;
    for (int tt=1;tt<=T;tt++){
        printf("Case #%d: ",tt);
        scanf("%s",st); len=strlen(st);
        scanf("%d",&n);
        run();
        //cout<<st<<' '<<n<<endl;
        cout<<ans<<endl;
    }
}
