/*********************
****SHASHANK GUPTA****
***@(my_blue_luck)****
**********************/

#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long int ll;

//#define gc getchar_unlocked
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

/*void scanint(long long int &x)
{
    register long long int c = gc();
    x = 0;
    long long int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}*/

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    ll t,i,ar[30],l,j,cnt;
    char str[2005];
    cin >> t ;
    for(i=1;i<=t;i++)
    {
        memset(ar,0,sizeof(ar));
        vector<ll> V;
        cin >> str;
        l=strlen(str);
        for(j=0;j<l;j++)
        {
            ar[str[j]-'A']++;
        }
        cnt=1;
        while(cnt<l)
        {
            if(ar[25]!=0)
            {
                while(ar[25]!=0)
                {
                    V.pb(0);
                    ar[25]--;
                    ar[4]--;
                    ar[17]--;
                    ar[14]--;
                    cnt+=4;
                }
            }
            if(ar[22]!=0)
            {
                while(ar[22]!=0)
                {
                    V.pb(2);
                    ar[22]--;
                    ar[19]--;
                    ar[14]--;
                    cnt+=3;
                }
            }
            if(ar[23]!=0)
            {
                while(ar[23]!=0)
                {

                    V.pb(6);
                    ar[23]--;
                    ar[18]--;
                    ar[8]--;
                    cnt+=3;
                }
            }
            if(ar[6]!=0)
            {
                while(ar[6]!=0)
                {
                    V.pb(8);
                    ar[6]--;
                    ar[4]--;
                    ar[8]--;
                    ar[7]--;
                    ar[19]--;
                    cnt+=5;
                }
            }
            if(ar[20]!=0)
            {
                while(ar[20]!=0)
                {
                    V.pb(4);
                    ar[5]--;
                    ar[14]--;
                    ar[20]--;
                    ar[17]--;
                    cnt+=4;
                }
            }
            if(ar[17]!=0)
            {
                while(ar[17]!=0)
                {
                    V.pb(3);
                    ar[19]--;
                    ar[7]--;
                    ar[17]--;
                    ar[4]-=2;
                    cnt+=5;
                }
            }
            if(ar[14]!=0)
            {
                while(ar[14]!=0)
                {
                    V.pb(1);
                    ar[14]--;
                    ar[13]--;
                    ar[4]--;
                    cnt+=3;
                }
            }
            if(ar[18]!=0)
            {
                while(ar[18]!=0)
                {
                    V.pb(7);
                    ar[18]--;
                    ar[4]-=2;
                    ar[21]--;
                    ar[13]--;
                    cnt+=5;
                }
            }
            if(ar[21]!=0)
            {
                while(ar[21]!=0)
                {
                    V.pb(5);
                    ar[5]--;
                    ar[8]--;
                    ar[21]--;
                    ar[4]--;
                    cnt+=4;
                }
            }
            if(ar[4]!=0)
            {
                while(ar[4]!=0)
                {
                    V.pb(9);
                    ar[4]--;
                    cnt+=4;
                }
            }

        }
        sort(V.begin(),V.end());
        l=V.size();
        cout << "Case #" << i << ":" << " " ;
        for(j=0;j<l;j++)
            cout << V[j];
            cout << endl ;
            V.clear();
    }
    return 0;
}
