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

int n,m,a[MAX],b[MAX];

map<char,int> mm;
vi v;
int main(){
    int r,k,i,c=0,x=0,y=0,j,t,l,z,x1=0,y1=0;
    ll ans=0;string p;

    si(t);
    f(j,1,t+1){
        cin>>p;
        printf("Case #%d: ",j);

        mm.clear();
        f(i,0,p.size())
            mm[p[i]]++;
        if(mm['Z']){
            c=mm['Z'];
            f(i,0,c)
                v.pb(0);
            mm['O']-=c;
        }
        if(mm['W']){
            c=mm['W'];
            f(i,0,c)
                v.pb(2);
            mm['O']-=c;
        }
        if(mm['X']){
            c=mm['X'];
            f(i,0,c)
                v.pb(6);
        }
        if(mm['U']){
            c=mm['U'];
            f(i,0,c)
                v.pb(4);
            mm['O']-=c;
            mm['F']-=c;
        }
        if(mm['F']){
            c=mm['F'];
            f(i,0,c)
                v.pb(5);
            mm['V']-=c;
        }
        if(mm['V']){
            c=mm['V'];
            f(i,0,c)
                v.pb(7);
            mm['N']-=c;
        }
        if(mm['G']){
            c=mm['G'];
            f(i,0,c)
                v.pb(8);
            mm['H']-=c;
        }
        if(mm['H']){
            c=mm['H'];
            f(i,0,c)
                v.pb(3);
            mm['H']-=c;
        }
        if(mm['O']){
            c=mm['O'];
            f(i,0,c)
                v.pb(1);
            mm['N']-=c;
        }
        if(mm['N']){
            c=mm['N']/2;
            f(i,0,c)
                v.pb(9);
        }
        sort(all(v));
        f(i,0,v.size())
            cout<<v[i];
            v.clear();
            nl;
    }

    return 0;
}
