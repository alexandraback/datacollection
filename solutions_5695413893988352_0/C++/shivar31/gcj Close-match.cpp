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

int len ;
ll absdiff , CFinal , JFinal ;
string maximize( string str )
{
    string ans = "" ;
    int len = str.length();
    REP( i , 0 , len - 1 )
    {
        if( str[i] == '?' )
            ans += '9';
        else
            ans += str[i];
    }
    return ans;
}

string minimize( string str )
{
    string ans = "";
    int len = str.length();
    REP( i , 0 , len - 1 )
    {
        if( str[i] == '?' )
            ans += '0';
        else
            ans += str[i] ;
    }
    return ans;
}

ll converttoNo( string str )
{
    int len = str.length();
    ll ans = 0 ;
    REP( i , 0 , len - 1 )
    {
        ans *= 10;
        ans += ( str[i] - '0' );
    }
    return ans;
}

string converttoString( ll no )
{
    string ans = "";
    while( no > 0 )
    {
        ans += char( no % 10 + '0' );
        no /= 10;
    }
    reverse( ans.begin() , ans.end() ) ;
    return ans;
}

void upd( ll Cno , ll Jno )
{
    //cout << Cno << " " << Jno << endl;
    if( abs( Cno - Jno ) < absdiff )
    {
        absdiff = abs( Cno - Jno );
        CFinal = Cno;
        JFinal = Jno;
    }
    else if( abs( Cno - Jno ) == absdiff )
    {
        if( Cno < CFinal )
        {
            CFinal = Cno;
            JFinal = Jno;
        }
        else if( Cno == CFinal )
        {
            if( Jno < JFinal )
            {
                CFinal = Cno;
                JFinal = Jno;
            }
        }
    }
}

void recurse( int idx , string C1 , string J1 )
{
    //cout  << idx << " " << C1 << " " << J1 << " " << len << endl;
    if( idx == len )
    {
        //cout << C1 << " " << J1 << endl;
        ll Cno = converttoNo(C1) , Jno = converttoNo(J1);
        upd( Cno , Jno );
        return;
    }
    if( C1[idx] == '?' && J1[idx] == '?' )
    {
        C1[idx] = '0' , J1[idx] = '0' ;
        recurse( idx + 1 , C1 , J1 );
        C1[idx] = '1' , J1[idx] = '0';
        recurse( len , minimize( C1 ) , maximize( J1 ) ) ;
        C1[idx] = '0' , J1[idx] = '1';
        recurse( len , maximize( C1 ) , minimize( J1 ) ) ;
    }
    else if( C1[idx] == J1[idx] )
    {
        recurse( idx + 1 , C1 , J1 );
    }
    else if( C1[idx] > J1[idx] && C1[idx] != '?' && J1[idx] != '?' )
    {
        recurse( len , minimize( C1 ) , maximize( J1 ) ) ;
    }
    else if( J1[idx] > C1[idx] && C1[idx] != '?' && J1[idx] != '?' )
    {
        //cout << J1 << " " << C1  << endl;
        recurse( len , maximize( C1) , minimize( J1 ) ) ;
    }
    else if( J1[idx] == '?' && C1[idx] != '?' )
    {
        J1[idx] = C1[idx];
        recurse( idx + 1 , C1 , J1 ) ;
        if( C1[idx] != '0' )
        {
            J1[idx] = C1[idx] - 1;
            recurse( len , minimize( C1 ) , maximize( J1 ) ) ;
        }
        if( C1[idx] != '9' )
        {
            J1[idx] = C1[idx] + 1;
            recurse( len  , maximize( C1 ) , minimize( J1 ) ) ;
        }
    }
    else if( C1[idx] == '?' && J1[idx] != '?' )
    {
        C1[idx] = J1[idx];
        recurse( idx + 1 , C1 , J1 ) ;
        if( J1[idx] != '0' )
        {
            C1[idx] = J1[idx] - 1;
            recurse( len , maximize( C1 ) , minimize( J1 ) ) ;
        }
        if( J1[idx] != '9' )
        {
            C1[idx] = J1[idx] + 1;
            recurse( len  , minimize( C1 ) , maximize( J1 ) ) ;
        }
    }
}

string correctLength( string str , int len )
{
    int siz = str.length();
    while( siz < len  )
    {
        str = "0" + str;
        siz++;
    }
    return str;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
    string huge;
    REP( i , 0 ,17 )
        huge += '9';
    int t ; s(t) ;
    REP( T , 1 , t  )
    {
        string C , J ;
        cin >> C >> J ;
        len = C.length();
        absdiff = CFinal = JFinal = converttoNo(huge);
        recurse( 0 , C , J );
        string CString = converttoString(CFinal) , JString = converttoString(JFinal);
        CString = correctLength(CString , len) , JString = correctLength(JString , len);
        cout << "Case #" << T << ": " << CString << " " << JString << endl;
    }
    return 0;
}
