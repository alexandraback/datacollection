#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <sstream>
#include <fstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <limits.h>
#include <time.h>

using namespace std;
typedef long long ll;

const int mod = 1e9+7;
const double eps = 1e-11;

int main(){
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int test;
	cin>>test;
	for(int tt = 0; tt < test; tt++){
		double c, f, x;
		double cur = 2;
		cin>>c>>f>>x;
		double res = x / cur;
		double t = 0;
		while(1){
			double buf = c / cur;
			t += buf;
			cur += f;
			double ress = x / cur;
			ress += t;
			if(res + eps < ress)
				break;
			res = ress;
		}

		cout<<"Case #"<<tt+1<<": ";
		printf("%.7lf\n", res);
	}
    return 0;
}