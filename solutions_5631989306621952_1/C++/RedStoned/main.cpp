#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define D(x) cout << #x << " = " << (x) << endl;
#define all(x) (x).begin(),(x).end()
string s;
int n;

int main()
{
    freopen("/home/khaled/file.in","r",stdin);
    freopen("/home/khaled/file.out","w",stdout);
    int T,tc(1);
    cin >> T;
    while(T--){
		cin >> s;
		n = (int) s.size();
		string p = ""; p += s[0];
		for(int i=1;i<n;i++){
			if(s[i]>=p[0]) p = s[i] + p;
			else p += s[i];
		}
		cout << "Case #" << tc++ << ": " << p << endl;
    }
    return 0;
}



