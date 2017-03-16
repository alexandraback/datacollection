#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int a[2000];
//int dfs(int p,int h, int n,vector<int> v, vector<int> path){
//	v[p]=1;
//	//if(!path.empty()&&a[p]!=path.back()){
//	//	path.push_back(p);
//	//	return dfs(a[p],h,n,v,path);
//	//}
//	path.push_back(p);
//	int max = -1;
//	for(int i=0;i<path.size();++i){
//	}
//	for(int i=0;i<n;++i){
//		int tmp=dfs(i,h,n,v,path);
//		if(tmp>max)
//			max=tmp;
//	}
//	return max;
//	if(a[p]!=p){
//		v[p]=1;
//		return dfs(a[p],h,n,v,counter+1);
//	}
//}
	
int main(){
	int TT;
	cin>>TT;
	int ans=0;

	int n;
	for(int T=1;T<=TT;++T){
		cin>>n;	
		vector<int> v;
		for(int i=0;i<n;++i){
			cin>>a[i];
			--a[i];
			v.push_back(i);
		}
		int max=-1;
		do{
			//for(int i=0;i<n;++i)
			//	cout<<v[i]<<" ";
			//cout<<endl;
			//v[0]=7-1;
			//v[1]=9-1;
			//v[2]=3-1;
			//v[3]=10-1;
			//v[4]=3-1;
			//v[5]=1-1;
			//if(a[v[0]]==v[1]&&a[v[1]]==v[0])
			//	max=2;
			for(int i=1;i<n;++i){
				if(a[v[i]]==v[i-1]||a[v[i]]==v[0]){
					if(a[v[0]]==v[i]||a[v[0]]==v[1]){
						if(i+1>max)
							max=i+1;
					}
				}
				if(i+1<n){
					if(a[v[i]]!=v[i-1]&&a[v[i]]!=v[i+1]){
						break;
					}
				}
			}
		}while(next_permutation(v.begin(),v.end()));
				cout<<"Case #"<<T<<": "<<max<<"\n";


	}
	return 0;
}
