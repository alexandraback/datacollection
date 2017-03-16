#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <cstdlib>
#include <queue>
#include <set>
#include <iomanip>

#define long long
#define mp make_pair

using namespace std;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int test;
	cin >>test;
	for (int t=1; t<=test; ++t){
		int n,x,y;
		cin >>n >>x >>y;
		int k=1,sum=0;
		while (sum<abs(x)+abs(y) && n>0){
			sum+=2;
			n-=k;
			k+=4;
		}
		if (n<=0){
			cout <<"Case #" <<t <<": " <<0 <<endl;
			continue;
		}
		if (n>=k){
			cout <<"Case #" <<t <<": " <<1 <<endl;
			continue;	
		}
		sum=abs(x)+abs(y);
		x+=sum;
		sum+=sum;
		vector<vector<long double> > dyn(n+1,vector<long double>(sum+1));
		for (int i=1; i<=n; ++i)
			for (int j=0; j<=sum; ++j){
				dyn[i][j]=dyn[i-1][j];
				if (j<sum/2)
					dyn[i][j]+=((j ? dyn[i-1][j-1] : 1)-dyn[i-1][j])*(i>=sum/2+j+1 ? 1 : 0.5);
				if (j>sum/2)
					dyn[i][j]+=((j<sum ? dyn[i-1][j+1] : 1)-dyn[i-1][j])*(i>=sum/2+(sum-j)+1 ? 1 : 0.5);
			}
		cout <<"Case #" <<t <<": " <<setprecision(9) <<dyn[n][x] <<endl;
	}
	return 0;
}