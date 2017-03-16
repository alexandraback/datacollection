#include<iostream>
#include<vector>
using namespace std;
int h,w;
int main(){
	int t;
	cin>>t;
	int cnt=0;
	while(t--){
		cin>>h>>w;
		vector<vector<int> > a(h,vector<int>(w));
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				cin>>a[i][j];
			}
		}
		vector<vector<int> > f(h,vector<int>(w,100));
		
		for(int i=0;i<h;i++){
			int mm=0;
			for(int j=0;j<w;j++){
				mm=max(mm,a[i][j]);
			}
			for(int j=0;j<w;j++){
				f[i][j]=min(mm,f[i][j]);
			}
		}
		for(int i=0;i<w;i++){
			int mm=0;
			for(int j=0;j<h;j++){
				mm=max(mm,a[j][i]);
			}
			for(int j=0;j<h;j++){
				f[j][i]=min(mm,f[j][i]);
			}
		}
		bool flag=false;
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				if(f[i][j]!=a[i][j]){
					flag=true;
					//goto end;
				}
				//cout<<f[i][j]<<" ";
			}
			//cout<<endl;
		}
		end:;
		
		cout<<"Case #"<<++cnt<<": ";
		if(flag){
			cout<<"NO"<<endl;
		}else{
			cout<<"YES"<<endl;
		}
	}
	return 0;
}