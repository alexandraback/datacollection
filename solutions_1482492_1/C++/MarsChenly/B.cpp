#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int task;

double zero=1e-7;
double die[2100],keng[2100];
int N,A;	
double h;
int kk;

double monia(double g){
	double sudu=0;
	double weizhi=0;
	double dis =0;
	double temp=0;
	
	
	for (int i=1;i<N;++i){
		temp=keng[i]-keng[i-1];
		dis=sudu * temp+ 0.5*g*temp*temp;
		if (weizhi+dis>die[i]+zero) {
			weizhi=die[i];
			sudu=sqrt(2*(die[i]-die[i-1])/g)*g;
		} else {
			weizhi += dis;
			sudu += temp * g;
		}
	}
	if (weizhi > h-zero ) return keng[N-1];
	double a,b,c;
	a=0.5*g; b=sudu; c=weizhi - h;
	double delta=b*b-4*a*c;

	double answer=(-b+sqrt(delta))/2/a;

	return keng[N-1]+ (-b+sqrt(delta))/2/a;
}

void work(){
	cin >> h >> N >> A;

	for (int i=0;i<N;++i){
		cin >> keng[i] >> die[i];
	}
	
	double temp;	

	if (die[0]>h-zero){
		for (int i=0;i<A;++i){
			cin >> temp;
		
	
			printf("%.7lf\n",sqrt(h*2/temp) );
		}
		return;	
	}
	
	
	while (N>0 && die[N-1]>=h){
		--N;
	}
	++N;
	keng[N-1]=keng[N-2]+(keng[N-1]-keng[N-2])*( (h-die[N-2])/( die[N-1]-die[N-2] ) );
	
	for (int i=0;i<A;++i){
		cin >> temp;
		
		printf("%.7lf\n",monia(temp) );
	}
}

int main(){
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	cin >> task;
	for (int cases=1;cases<=task;++cases){
		kk=cases;

		printf("Case #%d:\n",cases);
		work();
	}
	return 0;
}
