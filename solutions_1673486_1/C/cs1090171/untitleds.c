#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

#define miN(a,b) (a<b)?(a):(b)

vector<double> p,q;
int a,b,t;
double temp;
double m;

int main(){
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>a>>b;
		for(int j=0;j<a;j++){
			cin>>temp;
			p.push_back(temp);
			if(j) q.push_back(temp*q[j-1]);
			else q.push_back(temp);
		}
		m=q[a-1]*(b-a+1)+(1.0-q[a-1])*(2*b-a+2);
		m=miN(m,(a+b+1));
		m=miN(m,(b+2));
		for(int j=1;j<a;j++){
			double u=q[j-1]*(2*(a-j)+(b-a+1))+(1-q[j-1])*(2*(a-j)+(b-a+1)+b+1);
			m=miN(m,u);
		}
		p.clear();
		q.clear();
		printf("Case #%d: %.6f\n",(i+1),m);
	}
	return 0;
}

