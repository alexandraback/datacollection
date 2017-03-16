#include <iostream>
#include <iomanip>
using namespace std;

const int N = 202;
int s[N];
double o[N];
bool mk[N];
int main()
{
	int t,n,sum;
//	long long sum;
	cin>>t;
	cout<<setiosflags(ios::fixed)<<setprecision(6);
	for(int ca=1;ca<=t;ca++){
		cin>>n;
		sum=0;
		for(int i=0;i<n;i++){cin>>s[i];sum+=s[i];
//			cout<<"s"<<i<<"="<<s[i]<<endl;
		}
		double md	= 2.0 / n;
		bool pd=true;
		int gc;
//	cout<<"SUM="<<sum<<endl;

		for(int i=0;i<n;i++){
			
			o[i]=md-1.0*s[i]/sum;
//			cout<<"O"<<o[i]<<endl;
		}
		for(int i=0;i<n;i++)mk[i]=false;
		int qz=sum;
		while (pd){
			pd=false;
			for(int i=0;i<n;i++){
//				cout<<"oi="<<o[i]<<",mk="<<mk[i]<<endl;
				if((o[i]<0)&&(!mk[i])){
					mk[i]=true;
					pd=true;
				}
			}
//			cout<<"Pd="<<pd<<endl;
			if(pd){ 	
				bool az=true;
				for(int i=0;i<n;i++){
					if(o[i]>=0){
						if(s[i]>0){
							az=false;break;
						}
					}
				}

				if(az)
					for(int i=0;i<n;i++){
						if(o[i]>=0)s[i]=1;
					}
				

				sum=0;
				gc=0;
				for(int i=0;i<n;i++){
//					cout<<"o"<<i<<"="<<s[i]<<endl;
					if(o[i]>=0){
//						cout<<"!!\n";
						sum+=s[i];++gc;}
//					cout<<sum<<"\\"<<gc<<endl;
				}
				md=1.0*(qz+sum)/gc;
//				cout<<"sum="<<sum<<endl;
				for(int i=0;i<n;i++){
					if(o[i]>=0)o[i]=1.0*(md-s[i])/qz;
				}
			}
		}

		cout<<"Case #"<<ca<<":";
		for(int i=0;i<n;i++){
			double rst=o[i];
			if(rst<0)rst=0;
			cout<<" "<<rst*100;
		}
		cout<<endl;
	}
}
