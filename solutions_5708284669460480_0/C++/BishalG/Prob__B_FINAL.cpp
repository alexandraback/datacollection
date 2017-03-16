
/****************************************************************************
 *                                                                          *
 *                    ==>> BG_PeaceMind(BISHAL)                             *
 *                   try=0; while(!success) try++;                          *
 ****************************************************************************/
#include<bits/stdc++.h>
#define PI acos(-1.0)
#define nl puts("")
#define SZ(x) x.size()
#define pb(x) push_back(x)
#define X first
#define Y second
#define pii pair<int,int>
#define S(a) scanf("%d",&a)
#define P(a) printf("%d",a)
#define SL(a) scanf("%lld",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define S3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define SL2(a,b) scanf("%lld%lld",&a,&b)
#define SL3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define all(v) v.begin(),v.end()
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define fr(i,a,n) for(i=a;i<=n;i++)
#define rf(i,n,a) for(i=n;i>=a;i--)
#define LB(v,k) lower_bound(v.begin(),v.end(),k)
#define _cin ios_base::sync_with_stdio(0),cin.tie(0)
#define ct(x) cerr<<__LINE__<< ":: "<<#x<<"= "<<x<<endl
#define fi(it,n) for(__typeof(n.begin()) it=n.begin();it!=n.end();it++)
using namespace std;
typedef long long ll;

/// atoi( str.c_str() ); // char string to int
/// sprintf(str,"%d",num);// num to char string
///int month[]={-1,31,28,31,30,31,30,31,31,30,31,30,31}; //Not Leap Yr
///int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Dir
///int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 Dir
///int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight
/************************************************************************
 * /////////////////////////////////////////////////////////////////////*
 ************************************************************************/
/// [ Look at my code below, My code is so amazing !! :P ]
///  Digit    0123456789
#define MX    200

int K, L, S, lps[200 + 5];
char s[MX + 5], patt[MX + 5];
void findlps(char *p)
{
    CLR(lps);
    int ln, len = 0;
    ln = strlen(p);
    lps[0] = 0;
    for(int i = 1; i < ln ; )
    {
        if(p[i] == p[len])
        {
            lps[i] = ++len;
            i++;
        }
        else
        {
            if(len == 0)lps[i] = 0, i++;
            len = lps[len - 1];
        }
    }
}

int chk(char *str)
{
    char pat[MX+5];
    strcpy(pat,patt);
    strcat(pat, "$");
    int frm = strlen(pat);
    strcat(pat, str);
    findlps(pat);
    int i,n = strlen(pat);
    int cnt = 0;
    fr(i, frm, n - 1)
    {
        if(lps[i] == frm - 1)cnt++;
    }
    return cnt;
}

int cnt,mx;
void go(int p,string t) {
    //cout<< "S "<<s<<endl;
    if(p==S) {
        char chh[MX+5];
        strcpy(chh,t.c_str());
        mx=max(mx,chk(chh ) );
       // cout<<t<< " -> "<<mx<<endl;
        cnt++;
        return;
    }
    for(int i=0;i<K;i++) {
        go(p+1,t+s[i]);
    }
}
int sm;
void go1(int p,string t) {
    //cout<< "S "<<s<<endl;
    if(p==S) {
        char chh[MX+5];
        strcpy(chh,t.c_str());
        int val=chk(chh);
        sm+=(mx-val);
       // cout<<t<< " -> "<<mx<<endl;
        //cnt++;
        return;
    }
    for(int i=0;i<K;i++) {
        go1(p+1,t+s[i]);
    }
}

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("Bishal_Out_BBB.txt", "w", stdout);
    int  tc, cs = 1, i, j;
    S(tc);
    while(tc--)
    {
        S3(K,L,S);
        getchar();
        gets(s);
        gets(patt);

       // cout<<s<<" "<<patt<<endl;
        mx=0;
        cnt=0;
        go(0,"");
        sm=0;
        go1(0,"");
        //cout<<mx<< " "<<cnt<< " "<<sm<<endl;
        double ans=(sm*1.0)/(cnt*1.0);
        printf("Case #%d: %.8lf\n", cs++, ans+0.000000001);
    }
    return 0;
}
