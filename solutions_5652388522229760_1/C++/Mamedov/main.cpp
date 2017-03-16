#include <bits/stdc++.h>
#define maxx 100005
#define inf 2000000000
#define mod 1000000007
#define pii pair<int,int>
#define piii pair<pii,pii>
#define pli pair<long long,int>
#define f first
#define s second
#define in(x) scanf("%d",&x)
#define IN(x) scanf("%lld",&x)
#define inch(x) scanf("%s",x)
#define indo(x) scanf("%lf",&x)
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int t, n;
int used[15];
int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("a_large_output.txt", "w", stdout);
    cin >> t;
    for(int cases = 1; cases <= t; cases++){
        cin >> n;
        cout << "Case #" << cases << ": ";
        if(n == 0){
            cout << "INSOMNIA" << endl;
            continue;
        }
        memset(used, 0, sizeof(used));
        for(int i = n; ;i += n){
            int x = i;
            while(x){
                used[x%10] = 1;
                x /= 10;
            }
            int cnt = 0;
            for(int j = 0; j < 10; j++)
                cnt += used[j];

            if(cnt == 10){
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
