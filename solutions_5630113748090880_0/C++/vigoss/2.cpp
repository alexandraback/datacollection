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
    //fr("B-small-attempt0.in");
   // fw("B-small-attempt0.out");
    int t,cas = 1;
    cin >> t;
    while(t--)
    {
        int n,a;
        cin >> n;
        map<int,int>vis;
        for(int i = 0;i < 2 * n - 1;i++)
        {
            for(int j = 0;j < n;j++)
                scanf("%d",&a),vis[a]++;
        }
        printf("Case #%d: ",cas++);
        map<int,int>::iterator it = vis.begin();
        vi v;
        for(it;it != vis.end();it++)
        {
            if(it -> second % 2 != 0)
                v.PB(it -> first);
        }
        sort(v.begin(),v.end());
        cout << v[0];
        for(int i = 1;i < n;i++)
        {
            cout << " " << v[i];
        }
        cout << endl;
    }
}