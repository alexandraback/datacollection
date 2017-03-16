#include<iostream>
using namespace std;
int main(){

	int t,i,j;
	cin>>t;
	char p[1010];
	for(i=1;i<=t;++i){
		cin>>p;
		cout<<"Case #"<<i<<": ";
		int a[4000];
		for(j=0;j<4000;++j) a[j]=-1;
		int l=1001,k=1001;
		for(j=0;p[j]!='\0';++j){
			if(j==0){
				a[k++]=j;
			}else if(p[a[l]]>p[j]){
				a[k++]=j;
			}else a[--l]=j;
		}
		for(j=l;j<k;++j) cout<<p[a[j]];
		cout<<"\n";
	}


	return 0;
}
