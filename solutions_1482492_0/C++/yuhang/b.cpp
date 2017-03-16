#include<iostream>
#include<cmath>

using namespace std;
const long double err=0.000000000000001l;

inline long double sqrt2(long double x){
	if(x<err)
		return 0.;
	else
		return sqrt(x);
}

int main(){
	int T;
	cin>>T;
	cout.precision(15);
	for(int i=1;i<=T;i++){
		long double d;
		int n,a;
		cin>>d>>n>>a;
		long double t[2000],x[2000];
		for(int j=0;j<n;j++)
			cin>>t[j]>>x[j];
		for(int j=0;j<n;j++)
			if(x[j]>d-err){
				t[j]=t[j-1]+(t[j]-t[j-1])*((d-x[j-1])/(x[j]-x[j-1]));
				x[j]=d;
				n=j+1;
				break;
			}
		cout<<"Case #"<<i<<":"<<endl;
		for(int j=0;j<a;j++){
			long double f;
			cin>>f;
			long double p=0,v=0;
			for(int k=0;k<n;k++){
				p=p+v*(t[k]-t[k-1])+f*(t[k]-t[k-1])*(t[k]-t[k-1])/2;
				if(p>x[k]){
					p=x[k];
					
				}
				v=f*sqrt2(2*p/f);
				//if(k&&(x[k]-x[k-1])/(t[k]-t[k-1])<v)
					//v=(x[k]-x[k-1])/(t[k]-t[k-1]);
			}
			//cout<<t[n-1]-t[n-1]+sqrt(t[n-1]*t[n-1]-2*(p-d)/f)<<endl;
			cout<<t[n-1]+(-v+sqrt2(v*v-2*f*(p-d)))/f<<endl;
		}
	}
	return 0;
}

