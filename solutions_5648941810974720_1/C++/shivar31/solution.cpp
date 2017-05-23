#include<bits/stdc++.h>

using namespace std;

// Shortcuts for "common" data types in contests
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
// To simplify repetitions/loops, Note: define your loop style and stick with it!
#define s(i) scanf("%d",&i)
#define sl(i) scanf("%ld",&i)
#define sll(i) scanf("%lld",&i)
#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define NREP(i,a,b) \
for (int i = int(a); i >= int(b); i--)
#define TRvi(c, it) \
for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define INF 1000000000 // 2 billion
#define EPS 1e-9
#define MOD 1000000007

int fre[30] , temp[30];
char a[2009];
string order[] = {"ZERO","EIGHT","SIX","TWO","THREE","FOUR","FIVE","SEVEN","ONE","NINE"};
string digits[] = {"0","8","6","2","3","4","5","7","1","9"};

bool check( int dig )
{
    memset( temp , 0 , sizeof(temp) ) ;
    REP( i , 0 , order[dig].size() - 1 )
    {
        temp[order[dig][i] - 'A']++;
    }
    REP( i , 0 , 25 )
    {
        if( temp[i] > fre[i] )
            return false;
    }
    return true;
}

void rem()
{
    REP( i , 0 , 25 )
        fre[i] -= temp[i];
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
    int t ;
    s(t) ;
    REP( T , 1 , t )
    {
        memset( fre , 0 , sizeof(fre) ) ;
        scanf("%s",a);
        int len = strlen(a);
        REP( i , 0 , len - 1 )
        {
            fre[a[i] - 'A']++;
        }
        string ans = "";
        REP( i , 0,  9 )
        {
            while( check( i ) )
            {
                rem();
                ans += digits[i];
            }
        }
        sort( ans.begin() , ans.end() ) ;
        cout << "Case #" << T << ": " << ans << endl;
    }
    return 0;
}
