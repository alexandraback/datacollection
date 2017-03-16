/*  Towhidul Islam
    University Of Dhaka
    Problem Name :
    Algorithm Used :
*/

#include<bits/stdc++.h>

typedef long long ll;

#define SSTR(x)         dynamic_cast< ostringstream & >( \
                        (ostringstream() << dec << x )).str()
#define pb              push_back
#define mem(a, x)       memset(a, x, sizeof a)
#define PI              acos(-1)
#define all(a)          a.begin(), a.end()
#define ff              first
#define ss              second
#define read(in)        freopen("in.txt", "r", stdin)
#define write(out)      freopen("out.txt", "w", stdout)
#define INF             1<<30
#define eps             1e-9
#define FORN(i, n)      for(int i = 0; i < n; i++)
#define FORAB(i, x, n)  for(int i = x; i < n; i++)
#define FORD(i, x, n)   for(int i= n - 1; i >= x; i--)
#define scan(n)         scanf("%d", &n)
#define print(n)        printf("%d\n", n)
#define tor             vector
#define dbg(x)          cout<<#x<<" : "<<x<<endl
#define chkwhere        cout<<"LOL\n"
#define pii             pair<int, int>
#define MOD             1000000007
#define MAX             100007

using namespace std;

int a[3000];
vector<int>res;
int main(){
    read(in);
    write(out);
	int tc, cs = 1, t, n;
	scan(tc);
	while(tc--){
        scan(n);
        mem(a, 0);
        int cnt = (2 * n - 1) * n;
        FORAB(i, 0, cnt){
                cin>>t;
                a[t]++;
        }

        FORAB(i, 1, 2501){
            if(a[i] % 2 == 1) res.pb(i);
        }

        sort(all(res));
		printf("Case #%d:", cs++);
		FORAB(i, 0, n){
            printf(" %d", res[i]);
		}
		puts("");
        res.clear();
	}
    return 0;
}
