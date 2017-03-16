#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

const int MAXN = 100010;
double p[MAXN];
double dp[MAXN];

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int T, A, B;
	double ans, tmp;
	cin>>T;
	for(int tt = 1; tt <= T; ++tt){
		cin>>A>>B;
		dp[0] = 1;
		for(int i = 1; i <= A; ++i){
			cin>>p[i];
			dp[i] = dp[i - 1] * p[i];
		}
		ans = B + 2;
		tmp = B - A + 1 + (1 - dp[A]) * (B + 1);
		if(tmp < ans)ans = tmp;
		for(int i = 1; i <= A; ++i){
			tmp = A - i + B - i + 1 + (1 - dp[i]) * (B + 1);
			if(tmp < ans){
				ans = tmp;
			//	cout<<i<<' '<<ans<<endl;
			}
		}
		printf("Case #%d: %.9f\n", tt, ans);
//		cout<<"Case #"<<tt<<": "<<ans<<endl;
	}
	
	return 0;
}	
