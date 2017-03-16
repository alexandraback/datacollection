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

string s;

vector<string> dig={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int main() {
	ios_base::sync_with_stdio(false);
	freopen("input.in","r",stdin);
freopen("output.txt","w",stdout);
    int T;
    cin>>T;
    FORI(t,1,T){
        cout<<"Case #"<<t<<": ";
        cin>>s;
        unordered_map<char,int> m;
        vi v(10,0);
        for(int i=0;i<s.size();i++)
                ++m[s[i]];
        int cnt;

        cnt=m['Z'];
        for( char ch:dig[0])
            m[ch]-=cnt;
        v[0]+=cnt;

        cnt=m['W'];
        for(char ch:dig[2])
            m[ch]-=cnt;
        v[2]+=cnt;

        cnt=m['U'];
        for(char ch:dig[4])
            m[ch]-=cnt;
        v[4]+=cnt;

        cnt=m['X'];
        for(char ch:dig[6])
            m[ch]-=cnt;
        v[6]+=cnt;

        cnt=m['G'];
        for(char ch:dig[8])
            m[ch]-=cnt;
        v[8]+=cnt;

        cnt=m['O'];
        for(char ch:dig[1])
            m[ch]-=cnt;
        v[1]+=cnt;

        cnt=m['S'];
        for(char ch:dig[7])
            m[ch]-=cnt;
        v[7]+=cnt;

        cnt=m['V'];
        for(char ch:dig[5])
            m[ch]-=cnt;
        v[5]+=cnt;

        cnt=m['R'];
        for(char ch:dig[3])
            m[ch]-=cnt;
        v[3]+=cnt;

        cnt=m['I'];
        for(char ch:dig[9])
            m[ch]-=cnt;
        v[9]+=cnt;

        FOR(i,0,10)
            FOR(j,0,v[i])
                cout<<i;
        cout<<endl;


    }

	return 0;
}
