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

int main(){
    read(in);
    write(out);
	int tc, cs = 1;
	scan(tc);
	string str;
	while(tc--){
        cin>>str;
        string tmp = "";
        FORAB(i, 0, str.size()){
            if(tmp.size() == 0){
                tmp.pb(str[i]);
            }
            else{
                if(str[i] >= tmp[0]){
                    tmp.pb('x');
                    for(int i = tmp.size() - 1; i > 0; i--){
                        swap(tmp[i], tmp[i-1]);
                    }
                    tmp[0] = str[i];
                }
                else{
                    tmp.pb(str[i]);
                }
            }
        }
		printf("Case #%d: ", cs++);
		cout<<tmp<<endl;
	}
    return 0;
}
