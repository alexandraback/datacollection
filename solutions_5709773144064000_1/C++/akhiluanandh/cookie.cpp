#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm> 
#include <math.h> 
#include <vector>
#include <set>
#include <map> 
#include <string.h> 
#include <cstdlib> 
#include <limits.h> 
#include <tr1/unordered_map>
#include <tr1/unordered_set>
#include <functional> 
#include <stack>
#include <queue>
using namespace std;

#define EPS 0.0000000001

int main()
{
	int t,cn=1;
	cin>>t;
	for(;cn<=t;cn++){
		double c,f,x,r,mt,t;
		mt = 100000.0,r = 2.0,t=0;
		cin>>c>>f>>x;
		while(1){
			double nt = t + x/r;
			if(nt>mt || (mt-nt)<EPS)
				break;
			mt = min(mt,nt);
			t += c/r;
			r += f;
		}
		printf("Case #%d: %.8lf\n",cn,mt);
	}
	return 0;
}



