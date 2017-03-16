#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int T,A,B,Ans;
vector<int> shit;
int myPow(int p) {
	int x = 1;
	for (int i =1;i <=p ;i++)
		x*=10;
	return x;
}
int myLog(int n) {
	int x = 0;
	while(n)
		x++, n/= 10;
	return x;
}
int Calc(int now) {
	int ret = 0, tmp, mod;
	int totalDigit = myLog (now), modDigit = 0;
	shit.clear ();
	if (now == 1212)
		now = 1212;
	while(modDigit < totalDigit - 1) {
		mod = (now / myPow(modDigit)) % 10;
		modDigit++;
		if (mod == 0)
			continue;
		tmp = now % myPow (modDigit) * myPow (totalDigit - modDigit) + now/myPow (modDigit);
		if (now < tmp && tmp <=B) {
			bool repeated = false;
			for (int t = 0; t<shit.size (); t++)
				if(tmp == shit.at(t)) {
					repeated = true;break;
				}
			if (!repeated) {
				shit.push_back (tmp);
				ret ++;
			}
		}
	}
	return ret;
}
int main() {
	freopen ("in.txt","r",stdin);
	freopen ("out.txt","w",stdout);
	scanf("%d",&T);
	for (int i = 1; i <= T; i++) {
		scanf("%d%d",&A,&B);
		Ans = 0;
		for (int j = A; j<B; j++)
			Ans += Calc(j);
		printf("Case #%d: %d\n",i,Ans);
	}
}