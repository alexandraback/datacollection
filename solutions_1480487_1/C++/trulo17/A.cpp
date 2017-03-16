#include<cstdio>


int n,x;

int s[200];

bool tru(int i,double R,double C){
	for(int j=0;j<n;++j)if(j!=i){
		double y=(C-s[j])/x;
		if(y<0)continue;
		if(y>R)return false;
		else R-=y;
	}
	return true;
}

double f(int i){
	double lo=0.0,hi=1.0;
	for(int it=0;it<100;++it){
		double mi=(lo+hi)/2.0;
		double R=1-mi;
		double C=x*mi+s[i];
		if(tru(i,R,C))lo=mi;
		else hi=mi;
		//if(i==1)printf("%.2lf\n",mi);
	}
	return lo;
}

void caso(){
	scanf("%d",&n);
	x=0;
	for(int i=0;i<n;++i){
		scanf("%d",s+i);
		x+=s[i];
	}
	for(int i=0;i<n;++i){
		printf(" %.9lf",f(i)*100);
	}
	puts("");
}

int main(){
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;++i){
		printf("Case #%d:",i);
		caso();
	}
}
