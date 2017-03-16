//__hr1212__//

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef map<int,int> mi;

#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d %d",&a,&b)
#define nl printf("\n");
#define pi(a) printf("%d",a)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define f(i,a,b) for(i=a;i<b;i++)
#define rf(i,a,b) for(i=a;i>=b;i--)
#define clr(x,a) memset(x,a,sizeof(x))
#define MAX 1000100
#define MOD 1000000007
#define F first
#define S second

int n,m,a[MAX],b[MAX];
string p,q,s;

int valid1(int x){
    int i;
    for(i=p.size()-1;i>=0;i--){
        if(x==0)
            break;
        if(p[i]!=(x%10 + '0') && p[i]!='?')
            return 0;
        x/=10;
    }
    if(x!=0)
        return 0;
    for(;i>=0;i--){
        if(p[i]!='0' && p[i]!='?')
            return 0;
    }
    return 1;
}

int valid2(int x){
    int i;
    for(i=q.size()-1;i>=0;i--){
        if(x==0)
            break;
        if(q[i]!=(x%10 + '0') && q[i]!='?')
            return 0;
        x/=10;
    }
    if(x!=0)
        return 0;
    for(;i>=0;i--){
        if(q[i]!='0' && q[i]!='?')
            return 0;
    }
    return 1;
}

int main(){
    int r,k,i,c=0,x=0,y=0,j,t,l,z,x1=0,y1=0;
    ll ans=0;

    si(t);
    f(k,1,t+1){
        cin>>p>>q;
        printf("Case #%d: ",k);
        z=1e9;
        f(i,0,999){
            f(j,0,999){
                if(valid1(i) && valid2(j)){
                        if(abs(i-j)<z){
                            x=i;y=j;
                            z=abs(i-j);
                        }
                }
            }
        }
        s.clear();
        for(i=p.size()-1;i>=0;i--){
            s+=(x%10+'0');x/=10;
        }
        reverse(all(s));
        cout<<s;
        cout<<" ";
        s.clear();
        for(i=q.size()-1;i>=0;i--){
            s+=(y%10+'0');y/=10;
        }
        reverse(all(s));
        cout<<s;
        nl;
    }

    return 0;
}
