#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
int T;
double c,f,x;
double rate;
const double eps = 1e-9;
int main(){
	cin >> T;
	for(int i=0;i<T;i++){
		double res;
		rate =2.0;
		cin >> c >> f >> x;
		printf("Case #%d: ",i+1);
		if(c>x) {printf("%.7lf\n",x/2.0); continue;}
		res = x/2.0;
		double tmp = 0.0;
		int tot =0;
		for(int j=0; j<=(int)ceil(x) && x-tmp>eps  ;j++){

			tmp+=c/rate;

			rate+=f;
			if (res-(tmp+x/rate)>eps)
				res = tmp+x/rate;

		}
		
		printf("%.7lf\n",res);

	}

	return 0;
}
