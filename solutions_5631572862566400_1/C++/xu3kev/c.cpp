#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
	
int main(){
	int TT;
	cin>>TT;
	int ans=0;


	int n;
	int a[2000];
	int b[2000];
	int c[2000];
	for(int T=1;T<=TT;++T){
		int max = 0;
		cin>>n;	
		for(int i=0;i<n;++i){
			cin>>a[i];
			--a[i];
		}
		for(int i=0;i<n;++i)
			c[i]=0;
		for(int j=0;j<n;++j){
			int counter = 0;
			int p=a[j];
			for(int i=0;i<n;++i){
				b[i]=-1;
			}
			b[j]=0;	
			//cout<<j<<" ";
			while(b[p]<0){
				//cout<<p<<" ";
				++counter;
				b[p]=counter;
				p=a[p];

			}
			//cout<<" count= "<<counter<<", p="<<p<<" , j ="<<j;
			//cout<<endl;
			if(p==j&&counter+1>max){
				max=counter+1;
			}
			if(b[p]==counter-1){
				if(counter-1>c[p])
					c[p]=counter-1;
			}

		}
		int tmp=0;
		for(int i=0;i<n;++i){
			if(a[a[i]]==i){
				tmp+=c[i]+c[a[i]]+2;
			}
		}
		tmp/=2;
		if(tmp>max)
			max=tmp;
		cout<<"Case #"<<T<<": "<<max<<"\n";


	}
	return 0;
}
