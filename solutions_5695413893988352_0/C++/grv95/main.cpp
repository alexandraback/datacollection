#include <bits/stdc++.h>
#define X first
#define Y second
#define psb push_back
#define pob pop_back
#define mp make_pair
#define ll long long
#define scand(n) scanf("%d",&n)
#define scanld(n) scanf("%lld",&n)
#define printd(n) printf("%d\n",n)
#define printld(n) printf("%lld\n",n)
#define all(x) x.begin(),x.end()
#define SET( arr, val) memset(arr,val,sizeof(arr))
#define ITR iterator
#define SZ(arr) arr.size()
#define FOR( i, L, U ) for(int i=(int)L ; i<(int)U ; ++i )
#define FORI( i, L, U ) for(int i=(int)L ; i<=(int)U ; ++i )
#define FORD( i, U, L ) for(int i=(int)U ; i>=(int)L ; --i )
#define Tcases(t) int t;cin>>t;while(t--)

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;



void fil(vector<pair<int,string>> &v,string &s,int pos){
    if(pos==s.size()){
        v.psb({stoi(s),s});
        return;
    }
    if(s[pos]!='?'){
        fil(v,s,pos+1);
        return;
    }
    else{

        FOR(i,0,10){
            s[pos]='0'+i;
            fil(v,s,pos+1);
        }
        s[pos]='?';
    }

}

int main() {
	ios_base::sync_with_stdio(false);
	freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);
	int T;
	cin>>T;

	FORI(t,1,T){
        cout<<"Case #"<<t<<": ";
        string C,J;

        cin>>C>>J;
        vector<pair<int,string>> v1,v2;
        fil(v1,C,0);
        fil(v2,J,0);
   //     sort(all(v1));
   //     sort(all(v2));

        int mn=INT_MAX;
        int a1,a2;
        string s1,s2;
        int n1=v1.size();
        int n2=v2.size();

        FOR(i,0,n1)
            FOR(j,0,n2){
                int res=abs(v1[i].X-v2[j].X);
                if(res<mn || (res==mn && v1[i].X<a1)|| (res==mn && v1[i].X==a1 && v2[j].X<a2)){
                    mn=res;
                    a1=v1[i].X;
                    s1=v1[i].Y;

                    a2=v2[j].X;
                    s2=v2[j].Y;
                }
            }
        cout<<s1<<" "<<s2<<endl;

	}

	return 0;
}
