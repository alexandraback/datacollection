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
#define pi(a) printf("%d\n",a)
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

int n,m,a[20],b[MAX];

map<string,int> m1,m2;

int main(){
    int tt,r,k,i,c=0,x=0,y=0,j,t,l,z,x1=0,y1=0;
    ll ans=0;string p[100],q[100];

    si(t);
    f(tt,1,t+1){
        m1.clear();m2.clear();
        si(n);
        f(i,0,n){
            cin>>p[i]>>q[i];
        }
        printf("Case #%d: ",tt);
        z=0;
        f(l,0,1<<n){
            k=0;
            x=l;
            clr(a,0);
            while(x){
                if(x%2)
                    a[k]=1;
                x/=2;
                k++;
            }
            c=0;
            f(i,0,n){
                if(a[i]){
                    x1=0;y1=0;
                    f(j,0,n){
                        if(!a[j]){
                            if(p[i]==p[j])
                                x1=1;
                            if(q[i]==q[j])
                                y1=1;
                        }
                    }
                    if(!x1 || !y1){
                        c=1;
                        break;
                    }
                }
            }
            if(!c){
                x=0;
                f(i,0,n)
                    if(a[i])
                        x++;
                z=max(z,x);
            }
        }
        cout<<z<<endl;
    }

    return 0;
}
/*
5
7
B E
A B
A C
B D
C D
A D
B C
8
b b
b c
a b
c d
a c
c c
a d
c b
*/
