#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cctype>
#include <fstream>
using namespace std;

#define lowbit(x) ((x)&(-(x)))
#define sqr(x) ((x)*(x))
#define PB push_back
#define MP make_pair


int main(int argc,char** argv){
	int T;
	cin>>T;
	for (int r=1;r<=T;r++){
		printf("Case #%d: ",r);
		double C,F,X;
		cin>>C>>F>>X;
		double res=1e100;
		double rate=2;
		double curT=0;
		for (;curT<res;){
			res=min(res,curT+X/rate);
			curT+=C/rate;
			rate+=F;
		}
		printf("%.10f\n",res);
	}
	return 0;
}