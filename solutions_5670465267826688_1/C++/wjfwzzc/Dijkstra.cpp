#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=10005;
const int mat[5][5]= {0,0,0,0,0,
                      0,1,2,3,4,
                      0,2,-1,4,-3,
                      0,3,-4,-1,2,
                      0,4,3,-2,-1
                     };
char s[MAXN];
int val[MAXN];
int mul(int a,int b) {
    int ret=mat[abs(a)][abs(b)];
    if(a<0)
        ret=-ret;
    if(b<0)
        ret=-ret;
    return ret;
}
int main() {
    //freopen("C-large.in","r",stdin);
    //freopen("C-large.out","w",stdout);
    int t,l;
    long long x;
    scanf("%d",&t);
    for(int cas=1; cas<=t; ++cas) {
        scanf("%d%lld%s",&l,&x,s);
        val[0]=s[0]-'g';
        for(int i=1; i<l; ++i)
            val[i]=mul(val[i-1],s[i]-'g');
        int v=val[l-1],vv=mul(v,v),vvv=mul(vv,v),m=1;
        for(int i=x&3; i; --i)
            m=mul(m,v);
        bool flag=m==-1;
        if(flag) {
            int p=l<<2,q=l<<2;
            for(int i=0; i<l; ++i)
                if(val[i]==2)
                    p=min(p,i+1);
                else if(mul(v,val[i])==2)
                    p=min(p,l+i+1);
                else if(mul(vv,val[i])==2)
                    p=min(p,2*l+i+1);
                else if(mul(vvv,val[i])==2)
                    p=min(p,3*l+i+1);
            val[l-1]=s[l-1]-'g';
            for(int i=l-2; ~i; --i)
                val[i]=mul(s[i]-'g',val[i+1]);
            for(int i=l-1; ~i; --i)
                if(val[i]==4)
                    q=min(q,l-i);
                else if(mul(val[i],v)==4)
                    q=min(q,2*l-i);
                else if(mul(val[i],vv)==4)
                    q=min(q,3*l-i);
                else if(mul(val[i],vvv)==4)
                    q=min(q,4*l-i);
            flag=p<(l<<2)&&q<(l<<2)&&p+q<x*l;
        }
        printf("Case #%d: %s\n",cas,flag?"YES":"NO");
    }
}
