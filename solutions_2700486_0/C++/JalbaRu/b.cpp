#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
double binpow(double a,int n){
	double res=1;
	while(n){
		if(n&1)
			res=res*a;
		n>>=1;
		a=a*a;
	}
	return res;
}

double f(int a){
	double res=1;
	for(int i=0;i<a;i++)
		res=res*(i+1);
	return res;
}

double c(int a,int b){
	if(a>b || a<0) return 0.0;
	return f(b)/f(a)/f(b-a);
}

int main(){
//	freopen("1.txt","r",stdin);
	freopen("B-small-attempt5.in","r",stdin);
	freopen("BoutSmall5.txt","w",stdout);
//	freopen("B-large.in","r",stdin);
//	freopen("BoutLarge.txt","w",stdout);
	int TT;
	cin>>TT;
	for(int T=0;T<TT;T++){
		printf("Case #%d: ",T+1);
		int n,x,y;
		cin>>n>>x>>y;
		if(x<0) x=-x;
		int l=(x+y)/2;
		int m=l*(2*l-1);
		double ans=0;
		if(m+4*l+1<=n) 
			ans=1;
		else
			if(m+y+1<=n){
				int line=y;
				int cnt=n-m;
				int k=l*2;
				int u=0;
				int p=0;
				for(int i=0;i<k && p<cnt;i++){
					u++;
					ans+=c(line,i)/binpow(2,u);
					p++;
				}
				for(int i=0;i<k && p<cnt;i++){
					ans+=c(line-i,k-1-i)/binpow(2,u);
					u--;
					p++;
				}
			}
		//if(ans>1) printf("%d %d %d ",n,x,y),
		printf("%lf\n",ans);
		double d=0;
		switch (n)
		{
			case 1:
				if(x==0 && y==0) d=1;
				break;
			case 2:
				if(x==0 && y==0) d=1;
				if(y==0 && abs(x)==2) d=0.5;
				break;
			case 3:
				if(x==0 && y==0) d=1;
				if(y==0 && abs(x)==2) d=0.75;
				if(y==1 && abs(x)==1) d=0.25;
				break;
			case 4:
				if(x==0 && y==0) d=1;
				if(y==0 && abs(x)==2) d=1;
				if(y==1 && abs(x)==1) d=0.5;
				break;
			case 5:
				if(x==0 && y==0) d=1;
				if(y==0 && abs(x)==2) d=1;
				if(y==1 && abs(x)==1) d=1;
				break;
			case 6:
				if(x==0 && y==0) d=1;
				if(y==0 && abs(x)==2) d=1;
				if(y==1 && abs(x)==1) d=1;
				if(y==2 && x==0) d=1;
				break;

			case 7:
				if(x==0 && y==0) d=1;
				if(y==0 && abs(x)==2) d=1;
				if(y==1 && abs(x)==1) d=1;
				if(y==2 && x==0) d=1;
				if(y==0 && abs(x)==4) d=0.5;
				break;
			case 8:
				if(x==0 && y==0) d=1;
				if(y==0 && abs(x)==2) d=1;
				if(y==1 && abs(x)==1) d=1;
				if(y==2 && x==0) d=1;
				if(y==0 && abs(x)==4) d=0.75;
				if(y==1 && abs(x)==3) d=0.25;
				break;
			case 9:
				if(x==0 && y==0) d=1;
				if(y==0 && abs(x)==2) d=1;
				if(y==1 && abs(x)==1) d=1;
				if(y==2 && x==0) d=1;
				if(y==0 && abs(x)==4) d=7.0/8;
				if(y==1 && abs(x)==3) d=4.0/8;
				if(y==2 && abs(x)==2) d=1.0/8;
				break;
			case 10:
				if(x==0 && y==0) d=1;
				if(y==0 && abs(x)==2) d=1;
				if(y==1 && abs(x)==1) d=1;
				if(y==2 && x==0) d=1;
				if(y==0 && abs(x)==4) d=15.0/16;
				if(y==1 && abs(x)==3) d=11.0/16;
				if(y==2 && abs(x)==2) d=5.0/16;
				if(y==3 && abs(x)==1) d=1.0/16;
				break;
			case 11:
				if(x==0 && y==0) d=1;
				if(y==0 && abs(x)==2) d=1;
				if(y==1 && abs(x)==1) d=1;
				if(y==2 && x==0) d=1;
				if(y==0 && abs(x)==4) d=1;
				if(y==1 && abs(x)==3) d=7.0/8;
				if(y==2 && abs(x)==2) d=4.0/8;
				if(y==3 && abs(x)==1) d=1.0/8;
				break;
			case 12:
				if(x==0 && y==0) d=1;
				if(y==0 && abs(x)==2) d=1;
				if(y==1 && abs(x)==1) d=1;
				if(y==2 && x==0) d=1;
				if(y==0 && abs(x)==4) d=1;
				if(y==1 && abs(x)==3) d=1;
				if(y==2 && abs(x)==2) d=3.0/4;
				if(y==3 && abs(x)==1) d=1.0/4;
				break;
			case 13:
				if(x==0 && y==0) d=1;
				if(y==0 && abs(x)==2) d=1;
				if(y==1 && abs(x)==1) d=1;
				if(y==2 && x==0) d=1;
				if(y==0 && abs(x)==4) d=1;
				if(y==1 && abs(x)==3) d=1;
				if(y==2 && abs(x)==2) d=1;
				if(y==3 && abs(x)==1) d=1.0/2;
				break;
			case 14:
				if(x==0 && y==0) d=1;
				if(y==0 && abs(x)==2) d=1;
				if(y==1 && abs(x)==1) d=1;
				if(y==2 && x==0) d=1;
				if(y==0 && abs(x)==4) d=1;
				if(y==1 && abs(x)==3) d=1;
				if(y==2 && abs(x)==2) d=1;
				if(y==3 && abs(x)==1) d=1;
				break;
			case 15:
				if(x==0 && y==0) d=1;
				if(y==0 && abs(x)==2) d=1;
				if(y==1 && abs(x)==1) d=1;
				if(y==2 && x==0) d=1;
				if(y==0 && abs(x)==4) d=1;
				if(y==1 && abs(x)==3) d=1;
				if(y==2 && abs(x)==2) d=1;
				if(y==3 && abs(x)==1) d=1;
				if(y==4 && abs(x)==0) d=1;
				break;
			case 16:
				if(x==0 && y==0) d=1;
				if(y==0 && abs(x)==2) d=1;
				if(y==1 && abs(x)==1) d=1;
				if(y==2 && x==0) d=1;
				if(y==0 && abs(x)==4) d=1;
				if(y==1 && abs(x)==3) d=1;
				if(y==2 && abs(x)==2) d=1;
				if(y==3 && abs(x)==1) d=1;
				if(y==4 && abs(x)==0) d=1;
				if(y==0 && abs(x)==6) d=1.0/2;
				break;
			case 17:
				if(x==0 && y==0) d=1;
				if(y==0 && abs(x)==2) d=1;
				if(y==1 && abs(x)==1) d=1;
				if(y==2 && x==0) d=1;
				if(y==0 && abs(x)==4) d=1;
				if(y==1 && abs(x)==3) d=1;
				if(y==2 && abs(x)==2) d=1;
				if(y==3 && abs(x)==1) d=1;
				if(y==4 && abs(x)==0) d=1;
				if(y==0 && abs(x)==6) d=3.0/4;
				if(y==1 && abs(x)==5) d=1.0/4;
				break;
			case 18:
				if(x==0 && y==0) d=1;
				if(y==0 && abs(x)==2) d=1;
				if(y==1 && abs(x)==1) d=1;
				if(y==2 && x==0) d=1;
				if(y==0 && abs(x)==4) d=1;
				if(y==1 && abs(x)==3) d=1;
				if(y==2 && abs(x)==2) d=1;
				if(y==3 && abs(x)==1) d=1;
				if(y==4 && abs(x)==0) d=1;
				if(y==0 && abs(x)==6) d=7.0/8;
				if(y==1 && abs(x)==5) d=4.0/8;
				if(y==2 && abs(x)==4) d=1.0/8;
				break;
			case 19:
				if(x==0 && y==0) d=1;
				if(y==0 && abs(x)==2) d=1;
				if(y==1 && abs(x)==1) d=1;
				if(y==2 && x==0) d=1;
				if(y==0 && abs(x)==4) d=1;
				if(y==1 && abs(x)==3) d=1;
				if(y==2 && abs(x)==2) d=1;
				if(y==3 && abs(x)==1) d=1;
				if(y==4 && abs(x)==0) d=1;
				if(y==0 && abs(x)==6) d=15.0/16;
				if(y==1 && abs(x)==5) d=11.0/16;
				if(y==2 && abs(x)==4) d=5.0/16;
				if(y==3 && abs(x)==3) d=1.0/16;
				break;
			case 20:
				if(x==0 && y==0) d=1;
				if(y==0 && abs(x)==2) d=1;
				if(y==1 && abs(x)==1) d=1;
				if(y==2 && x==0) d=1;
				if(y==0 && abs(x)==4) d=1;
				if(y==1 && abs(x)==3) d=1;
				if(y==2 && abs(x)==2) d=1;
				if(y==3 && abs(x)==1) d=1;
				if(y==4 && abs(x)==0) d=1;
				if(y==0 && abs(x)==6) d=31.0/32;
				if(y==1 && abs(x)==5) d=26.0/32;
				if(y==2 && abs(x)==4) d=16.0/32;
				if(y==3 && abs(x)==3) d=6.0/32;
				if(y==4 && abs(x)==2) d=1.0/32;
				break;
		}
		if(d!=ans) 		cout<<"fail\n", printf("%d %d %d %.6lf",n,x,y,d);
		
	}
}
