/*************************************************************************
    > File Name: a.cpp
    > Author: temp24
    > Mail: tianmingfly@gmail.com 
    > Created Time: Sat 28 Apr 2012 09:28:14 AM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <bitset>
#include <vector>
#include <utility>
#include <map>
#include <set>

#define LOCAL
#define INF 1061109567
#define IM 101000
#define PI M_PI

#define FU(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define FD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define CL(a,v) memset((a),(v),sizeof(a))

using namespace std;

int A,B;
double p[IM];
double a,a1,a2;
double imin;

void Init(){
	cin>>A>>B;
	FU(i,0,A){
		cin>>p[i];
	}
	a = a1 = a2 = 1;
	FU(i,0,A){
		a *= p[i];
	}
	
	FU(i,0,A-1){
		a1 *= p[i];
	}
	FU(i,0,A-2){
		a2 *= p[i];
	}
}

int main()
{
    #ifdef LOCAL
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    #endif
	int T;
	cin>>T;
	FU(i,0,T){
		cout<<"Case #"<<i+1<<": ";
		Init();
		imin = INF;
		imin = min(imin,a*(B-A+1)+(1-a)*(2*B-A+2));
//        cout<<a*(B-A+1)+(1-a)*(2*B-A+2)<<endl;
		imin = min(imin,a1*(B-A+3)+(1-a1)*(2*B-A+4));
//        cout<<a1*(B-A+3)+(1-a1)*(2*B-A+4)<<endl;
		imin = min(imin,a2*(B-A+5)+(1-a2)*(2*B-A+6));
//		cout<<a2*(B-A+5)+(1-a2)*(2*B-A+6)<<endl;
		imin = min(imin,(double)(B+2));
		printf("%.6lf\n",imin);
	}
    return 0;
}
