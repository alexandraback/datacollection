#include<iostream>
using namespace std;
int main(){
	int p;
	int a[2000];
	int b[2000];
	int c[2000];
	int T;
	cin>>T;
	int d;
	for(int cs=1;cs<=T;++cs){
		cin>>d;
		for(int i=0;i<2000;++i)
			a[i]=0;
		int p_max=0;
		for(int i=0;i<d;++i){
			cin>>p;
			if(p>p_max)
				p_max=p;
			++a[p];
		}
		int s=0;
		for(int i=1;i<2000;++i){
			if(a[i]>0){
				b[s]=i;
				c[s]=a[i];
				++s;
			}
		}
		int mi=p_max;
		for(int i=1;i<2000;++i){
			int sum=0;
			for(int j=i+1;j<2000;++j){
				if(a[j]>0){
					sum+=((j-1)/i)*a[j];
				}
			}
			if(sum+i<mi)
				mi=sum+i;
		}
		cout<<"Case #"<<cs<<": "<<mi<<endl;;
	}
	return 0;
}
