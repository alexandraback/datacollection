#include<bits/stdc++.h>

using namespace std;
#include <fstream>
#include <sstream>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define INF INT_MAX/3
#define PB push_back
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define SET(a,c) memset(a,c,sizeof a)

#define VS vector<string>
#define VI vector<int>
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
#define PI acos(-1.0)

#define INFILE() freopen("B-large.in","r",stdin)
#define OUTFILE()freopen("BoutLarge.txt","w",stdout)
#define FASTIO ios_base::sync_with_stdio(0);cin.tie();

#define LL long long
#define ULL unsigned long long
#define EPS 1e-9
#define MOD 1000000007
#define xx first
#define yy second
#define PII pair<LL,LL>
template<typename T>inline string toString(T a)
{
    ostringstream os("");
    os<<a;
    return os.str();
}
template<typename T>inline LL toLong(T a)
{
    LL res;
    istringstream os(a);
    os>>res;
    return res;
}
//MATHEMATICS
template<typename T>inline T  SQ(T a)
{
    return a*a;
}

template<typename T>inline ULL bigmod(T a, T b, T m)
{
    if (b == 0)return 1;
    else if (b % 2 == 0)return SQ(bigmod(a, b / 2, m)) % m;
    else return (a % m*bigmod(a, b - 1, m)) % m;
}
template<typename T>inline VS parse(T str)
{
    VS res;
    string s;
    istringstream os(str);
    while(os>>s)res.PB(s);
    return res;
}
template<typename T>inline ULL  dist(T A,T B)
{
    ULL res=(A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);
    return res;
}
template<typename T>inline double cosAngle(T a,T b,T c)
{
    double res=a*a+b*b-c*c;
    res=res/(2*a*b);
    res=acos(res);
    return res;
}

#define Mx 105

string str,nec;

int table[1005][Mx];
int Cnt[1005][Mx];
int match[1005];
char inp[10004];
int LEN;
int M,N,lim=51;

double dp[105][105][105];
int vis[105][105][105];
int KS;
int SZ;

vector<char>vv;




void build()
{

    int len=str.length();
    LEN=len;
    SET(match,0);
    int i,j;
    for(i=1; i<len; i++)
    {
        j=match[i-1];
        while(j>0 && str[i]!=str[j])
        {
            j=match[j-1];
        }
        if(str[i]==str[j])
        {
            j++;
        }
        match[i]=j;
    }

    SET(table,0);

    for(i=0; i<len; i++)
    {
        for(int j=0; j<vv.size(); j++)
        {
            char ch=vv[j];
            if(i>0 && ch!=str[i])
            {
                table[i][ch-'A']=table[match[i-1] ][ch-'A'];
            }
            else
            {
                table[i][ch-'A']=i+(ch==str[i]);

                if(table[i][ch-'A']== LEN )
                {
                    table[i][ch-'A']=0;
                    bool ok=false;
                    Cnt[i][ch-'A']=1;
                    if(i>0 && (ch!=str[i] || ok==false) )
                    {
                        ok=true;
                        table[i][ch-'A']=table[match[i-1] ][ch-'A'];
                    }

                }
            }




        }
    }
//            cout<<i<<" "<<ch<<" : --> "<<table[i][ch-'A']<<"  ";
//            cout<<Cnt[i][ch-'A']<<endl;

//    cout<<table[4][0]<<endl;
//    cout<<Cnt[4][0]<<endl;


}
// pos, prefix match,


double solve(int pos, int pm , int add){

  //  cout<<" debug" <<pos<<" "<<pm<<" "<<add<<endl;


    if(pos==N){
        return add;
    }



//    DEBUG(KS);

    if(vis[pos][pm][add]==KS)return dp[pos][pm][add];
    double &ret=dp[pos][pm][add]=0;
    vis[pos][pm][add]=KS;

    for(int i=0;i<vv.size();i++){
//        cout<<"here";
//
//        cout<<i<<" "<<vv[i]<<" : "<<table[pm][vv[i]-'A' ]

        ret = ret + ( solve(pos+1, table[pm][vv[i]-'A' ], add +Cnt[pm][vv[i]-'A' ]  )  );
    }



    ret = ret / SZ;

    return ret;
}

int memo[105][105];

int fun(int pos, int pm){
    if(pos==N)return 0;

    if(memo[pos][pm]!=-1)return memo[pos][pm];

    int &ret =memo[pos][pm] =0;

    for(int i =0 ;i<vv.size() ;i++ ){

        ret  = max (ret , fun(pos+1, table[pm][vv[i]-'A'] ) + Cnt[pm][vv[i]-'A' ]  );

    }
    return ret;

}


int main()
{

    INFILE();
    OUTFILE();

    int x,y,i,j;
    int ks,cas,tw;
    KS=5;

    cin>>ks;
    FOR(cas,1,ks+1)
    {
        // K, L , S
        cin>>SZ>>tw>>N;
        vv.clear();
        scanf("%s",inp);

        FOR(i,0,strlen(inp))
        {
            vv.PB(inp[i]);
        }

        SZ  = (int)vv.size();

        scanf("%s",inp);
        str=inp;
        M=strlen(inp);

        SET(Cnt,0);
        build();

        ++KS;

        double ret = solve(0,0,0);

        SET(memo,-1);

        double ans =  fun(0,0);


//        DEBUG(ret);
//        DEBUG(ans);

        ans -= ret;
        cout<<"Case #"<<cas<<": ";
        cout<<setprecision(10)<<fixed;
        cout<<ans<<endl;
    }



    return 0;
}


