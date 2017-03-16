#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
#define PB push_back
#define UB upper_bound
#define LB lower_bound
#define MP make_pair
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<vi>
#define mst(x,y) memset(x,y,sizeof(x))
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define sp system("pause")
#define INF 1e18
#define MAXN 50005
#define PI acos(-1.0)
#define eps 1e-4

int main()
{
    //fr("A-large (1).in");
    //fw("A-large (1).out");
    int t,cas = 1;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        printf("Case #%d: ",cas++);
        string h = "";
        for(int i = 0;i < s.size();i++)
        {
            if(h.size() > 0 && s[i] >= h[0])
                h.insert(h.begin(),s[i]);
            else
                h.insert(h.end(),s[i]);
        }
        cout << h << endl;
    }
}