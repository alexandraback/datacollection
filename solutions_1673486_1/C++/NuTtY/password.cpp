#include<iostream>
#include<vector>
using namespace std;
int main(){
	int T;
	cin>>T;
	int casenum = 1;
	while(T--){
		int a,b;
		cin>>a>>b;
		vector<double> v(a);
		for(int i=0;i<a;i++)
			cin>>v[i];
		vector<double> f(a+1);
		f[1] = v[0];
		for(int i=2;i<=a;i++)
			f[i] = v[i-1]*f[i-1];
			
		double ans = b+2;
		for(int back = 0;back < a;back++){
			double temp = back + f[a-back]*(b - a + 1 + back) + (1-f[a-back])*(2*b - a + 2 + back);
			if(temp < ans) ans = temp;
		}
		double allback = a+b+1;
		if(allback < ans) ans = allback;
		printf("Case #%d: %.6lf\n",casenum++,ans);
	}
	return 0;
}
