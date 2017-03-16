#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
#define MAX(x,y) (x > y ? x : y)
#define MIN(x,y) (x > y ? y : x)
long long mod = 1000000007;

int n,m,k;
int solve() {
	if (n > m)swap(n,m);
	if(n<3) return k;
	if (k < 5) return k;
	if (n == 3)  {
		if (m==3)return k-1;
		if (k<8)return k-1;
		if (k<11)return k-2;
		if (m==4)return k-2;
		if (k<14)return k-3;
		if (m==5)return k-3;
		return k -4;
	}
	if (k<8) return k-1;
	if (k<10)return k-2;
	if (k<12)return k-3;
	if (k<14)return k -4;
	if (m ==4) return k - 4;
	if (k<16)return k-5;
	return k-6;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	int T;
	cin>>T;
	
	
	for (int idx = 1; idx <= T; idx++) {
		cin >> n >> m >>k;
		cout<<"Case #"<<idx<<": ";
		if(true)cout<<solve();
		//else cout<<"impossible";
		cout<<endl;
	}
	return 0;
}