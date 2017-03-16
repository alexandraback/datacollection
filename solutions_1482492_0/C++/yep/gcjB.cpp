#include <string>
#include <vector>
#include <sstream> 
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cmath>
using namespace std;

int main(){
	freopen("B-small-attempt1.in","r",stdin);
	freopen("b.out","w",stdout);
	int c;
	cin>>c;
	for (int t=0;t<c;t++){
		cout<<"Case #"<<t+1<<": "<<endl;
		double d;
		int n,m;
		cin>>d>>n>>m;
		
		double tt[3000],xx[3000],lt,lx;
		lt=0;
		lx=0;
		for (int i=0;i<n;i++){
			double x,t;
			cin>>t>>x;
			if (lx<d){
				
				
				if (x>d){
					t = lt+(d-lx)/((x-lx)/(t-lt));
					x= d;
				}
				//cout<<c<<' '<<t<<' '<<x<<endl;
				tt[i] = t;
				xx[i] = x;
			}else{
				tt[i]=0;
				xx[i]=0;
			}
			lx = x;
			lt = t;
			
		}
		for (int i=0;i<m;i++){
			double a;
			cin>>a;
			double min=0;
			for (int i=0;i<n;i++){
				double x,t;
				x=xx[i];
				t=tt[i];
				double newc = t-sqrt(2*x/a);
				if (newc>min) min = newc;
			}
			double ans = sqrt(2*d/a)+min;
			fprintf(stdout,"%.7f\n",ans);
		}
	}
}
