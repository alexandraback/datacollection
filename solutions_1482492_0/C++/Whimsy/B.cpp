#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int Test;

double eps = 1e-7;
double x[2100],t[2100];
int N,A;	
double h;
int kk;

double simulate(double g){
	double speed = 0;
	double location = 0;
	double dis =0;
	double tmp = 0;
	
	
	for (int i = 1;i<N;++i){
		tmp = t[i]-t[i-1];
		dis = speed * tmp+ 0.5*g*tmp*tmp;
		if (location+dis>x[i]+eps) {
			location = x[i];
			speed = sqrt(2*(x[i]-x[i-1])/g)*g;
		} else {
			location += dis;
			speed += tmp * g;
		}
	}
	if (location > h-eps ) return t[N-1];
	double a,b,c;
	a = 0.5*g; b = speed; c = location - h;
	double det = b*b-4*a*c;

	double ans = (-b+sqrt(det))/2/a;

	return t[N-1]+ (-b+sqrt(det))/2/a;
}

void work(){
	cin >> h >> N >> A;

	for (int i = 0;i<N;++i){
		cin >> t[i] >> x[i];
	}
	
	double tmp;	

	if (x[0]>h-eps){
		for (int i = 0;i<A;++i){
			cin >> tmp;
		
	
			printf("%.7lf\n",sqrt(h*2/tmp) );
		}
		return;	
	}
	
	
	while (N>0 && x[N-1]>=h){
		--N;
	}
	++N;
	t[N-1] = t[N-2]+(t[N-1]-t[N-2])*( (h-x[N-2])/( x[N-1]-x[N-2] ) );
	
	for (int i = 0;i<A;++i){
		cin >> tmp;
		
		printf("%.7lf\n",simulate(tmp) );
	}
}

int main(){
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	cin >> Test;
	for (int ii = 1;ii<=Test;++ii){
		kk = ii;

		printf("Case #%d:\n",ii);
		work();
	}
	return 0;
}
