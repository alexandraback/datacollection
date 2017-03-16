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

/*
    i=i
    j=j
    k=k
    -i=a
    -j=b
    -k=c
    1=o
    -1=x
*/

map<pair<char,char>,char> mul;
char i='i',j='j',k='k',a='a',b='b',c='c',x='x',o='o';
ll l,rep;
int actual;

void init(){
	mul[{o,o}]=o;
	mul[{o,i}]=i;
	mul[{o,j}]=j;
	mul[{o,k}]=k;
	mul[{o,x}]=x;
	mul[{o,a}]=a;
	mul[{o,b}]=b;
	mul[{o,c}]=c;

	mul[{i,o}]=i;
	mul[{i,i}]=x;
	mul[{i,j}]=k;
	mul[{i,k}]=b;
	mul[{i,x}]=a;
	mul[{i,a}]=o;
	mul[{i,b}]=c;
	mul[{i,c}]=j;

	mul[{j,o}]=j;
	mul[{j,i}]=c;
	mul[{j,j}]=x;
	mul[{j,k}]=i;
	mul[{j,x}]=b;
	mul[{j,a}]=k;
	mul[{j,b}]=o;
	mul[{j,c}]=a;

	mul[{k,o}]=k;
	mul[{k,i}]=j;
	mul[{k,j}]=a;
	mul[{k,k}]=x;
	mul[{k,x}]=c;
	mul[{k,a}]=b;
	mul[{k,b}]=i;
	mul[{k,c}]=o;

	mul[{x,o}]=x;
	mul[{x,i}]=a;
	mul[{x,j}]=b;
	mul[{x,k}]=c;
	mul[{x,x}]=o;
	mul[{x,a}]=i;
	mul[{x,b}]=j;
	mul[{x,c}]=k;

	mul[{a,o}]=a;
	mul[{a,i}]=o;
	mul[{a,j}]=c;
	mul[{a,k}]=j;
	mul[{a,x}]=i;
	mul[{a,a}]=x;
	mul[{a,b}]=k;
	mul[{a,c}]=b;

	mul[{b,o}]=b;
	mul[{b,i}]=k;
	mul[{b,j}]=o;
	mul[{b,k}]=a;
	mul[{b,x}]=j;
	mul[{b,a}]=c;
	mul[{b,b}]=x;
	mul[{b,c}]=i;

	mul[{c,o}]=c;
	mul[{c,i}]=b;
	mul[{c,j}]=i;
	mul[{c,k}]=o;
	mul[{c,x}]=k;
	mul[{c,a}]=j;
	mul[{c,b}]=a;
	mul[{c,c}]=x;

}

string s;
string pref;

bool found=0;

void compute(){


    found=0;
    bool foundi=0;
    bool foundk=0;
    if(s[0]==i)
        foundi=1;
    if(s[0]==k)
        foundk=1;

    pref[0]=s[0];
    int sz=l*actual;
    FOR(it,1,sz){
        pref[it]=mul[{pref[it-1],s[it]}];
        if(pref[it]==i)
            foundi=1;

        else if(pref[it]==k){
            if(foundi)
                found=1;
            foundk=1;
        }
    }
    if(foundk && foundi && !found){
        if(rep>=8)
            found=1;
        else{
            int lst=l*(rep-actual);
            FOR(it,0,lst)
                if(pref[it]==k){
                    found=1;
                    break;
                }
        }
    }

    if(pref[(ll)(l*rep -1)%sz]!=x)
            found=0;

}


int main() {
    freopen("C-large.in","r",stdin);
    freopen("output.out","w",stdout);

    init();
    int T;

    cin>>T;
    FORI(t,1,T){
        cin>>l>>rep;
 //       ll sz=l*rep;


        if(rep>4)
            actual=4;
        else
            actual=rep;

        string temp;
        cin>>temp;
        s=temp;
        FOR(it,1,actual)
            s+=temp;
        pref.resize(l*actual);

        compute();


        string ans=(found?"YES\n":"NO\n");

        printf("Case #%d: ",t);
        cout<<ans;
 //       cout<<pref<<endl;
    }

	return 0;
}
