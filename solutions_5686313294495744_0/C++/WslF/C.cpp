//solution by Wsl_F
#include <bits/stdc++.h>

using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")


typedef long long LL;
typedef unsigned long long uLL;
typedef double dbl;
typedef vector<int> vi;
typedef vector<LL> vL;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef pair<LL,LL> pLL;

#define mp(x,y)  make_pair((x),(y))
#define pb(x)  push_back(x)
#define sqr(x) ((x)*(x))

const int MaxN= 16;
int pw[32];
pair<string,string> topics[MaxN+10];

void solve()
{
    int n;
    cin>>n;
    string s1,s2;
    for (int i= 0; i<n; i++)
    {
        cin>>s1>>s2;
        topics[i]= mp(s1,s2);
    }

    int ans= 0;
    // 1 - fake
    for (int mask= 0; mask<pw[n]; mask++)
    {
        vi fake;
        set<string> originFirst;
        set<string> originSecond;
        for (int i= 0; i<n; i++)
            if ((int)(mask&pw[i])!=0)
        {
            fake.pb(i);
        }
        else
        {
            originFirst.insert(topics[i].first);
            originSecond.insert(topics[i].second);
        }

        if (fake.size()<=ans) continue;

        bool flag= 1;
        for (int fk : fake)
        {
            if (originFirst.count(topics[fk].first)==0 ||
                originSecond.count(topics[fk].second)==0)
            {
                flag= 0;
                break;
            }
        }

        if (flag) ans= fake.size();
    }

    cout<<ans<<endl;
}

int main()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 srand(__rdtsc());
 // LL a[110];
 // memset(a,0,sizeof(a));

 freopen("C-small-attempt0.in","r",stdin);
 freopen("output_C_small.txt","w",stdout);
 //cout<<fixed;
 //cout<<setprecision(9);

  pw[0]= 1;
  for (int i= 1; i<32; i++)
        pw[i]= pw[i-1]*2;

 int T;
 cin>>T;
 for (int testCase= 1; testCase <= T; testCase++)
 {
     cout<<"Case #"<<testCase<<": ";
     solve();
 }


 return 0;
}
