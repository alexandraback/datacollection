#include<fstream>
using namespace std;
int N,T;
int X,Y,L;
double sol;
void solve();
double make_prob(int n,int h,int j);
int mabs(int x){return x>0?x:-x;}
int main()
{
	FILE *in,*out;
	in=fopen("input.txt","r");
	out=fopen("output.txt","w");
	int i;
	fscanf(in,"%d",&T);
	for(i=0;i<T;i++){
		fscanf(in,"%d %d %d",&N,&X,&Y);
		solve();
		fprintf(out,"Case #%d: %lf\n",i+1,sol);
	}
	return 0;
}

void solve()
{
	int i,p,w;

	for(i=0;;i++){
		p=(i+1)*(i*2+1);
		if(p>=N){
			break;
		}
	}
	X=mabs(X); Y=mabs(Y);
	L=(X+Y)/2;
	if(i>L){
		sol=1.0;
	}else if(i<L){
		sol=0.0;
	}else{
		if(p==N){
			sol=1.0; return ;
		}
		i--; p=(i+1)*(i*2+1);
		N-=p;
		w=(Y-X)/2+L+1;
		if(w>L+1){
			sol=0.0; return ;
		}
		sol=make_prob(N,L+1,w);
	}
}

double cal_prob(int x, int y){//xCy(1/2)^x=x!/((x-y)!y!2^x)
	int i,yy;
	int n2;
	double res=1.0;


	n2=x;

	for(i=2;i<=x;i++){
		yy=i;

		while(n2>0 && yy%2==0){
			n2--;
			yy/=2.0;
		}

		res *=yy;
	}

	for(i=2;i<=(x-y);i++){
		res /=i;
	}
	for(i=2;i<=y;i++){
		res /=i;
	}

	for(i=0;i<n2;i++){
		res /=2.0;
	}

	return res;

}

  
double make_prob(int n,int h,int j){
	int i;
	double pr=0.0;

	if(n>=h+j){
		pr=1.0;
		return pr;
	}

	for(i=j;i<=n;i++){
		pr+=cal_prob(n,i);
	}
	return pr;
}
  