#include <iostream>
using namespace std;

int main()
{
	int t,q=0;
	cin>>t;
	while(t--){
		q++;
		int n,m;
		int a[100][100];
		cin>>n>>m;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>a[i][j];
			}
		}
		int flag=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				int f1=0,f2=0;
				for(int p=0;p<n;p++){
					if(a[i][j]<a[p][j]){
						f1=1;
						break;
					}
				}
				for(int p=0;p<m;p++){
					if(a[i][j]<a[i][p]){
						f2=1;
						break;
					}
				}
				if(f1==1 && f2==1){
					flag=1;
					break;
				}
			}
			if(flag==1){
				break;
			}
		}
		if(flag==1){
			cout<<"Case #"<<q<<": "<<"NO"<<endl;
		}
		else{
			cout<<"Case #"<<q<<": "<<"YES"<<endl;
		}
	}
	return 0;
}
