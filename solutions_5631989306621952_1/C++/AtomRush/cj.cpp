#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef unsigned long long llu;

#define author ayushtomar
#define rf freopen("in121.in", "r", stdin)
#define wf freopen("out.txt", "w", stdout)
#define debug(x) cerr<<#x<<" "<<x<<endl;
#define f first
#define s second
#define mp make_pair
#define pb push_back
string s1;
vector < char > v;
int main()
{
    rf;wf;
    int t;
    scanf("%d",&t);
for (int tt=1;tt<=t;tt++){
    v.clear();
    cin>>s1;
    char beg=s1[0];
    v.pb(s1[0]);
    for(int i=1;i<s1.size();i++)
    {
        if(s1[i]>=beg)
            {
                beg=s1[i];
                vector < char > :: iterator it=v.begin();

                v.insert(it,s1[i]);
            }
        else
            v.push_back(s1[i]);
    }
        printf("Case #%d: ",tt);
    for(int i=0;i<v.size();i++)
        cout<<v[i];
printf("\n");
}
 return 0;
}
