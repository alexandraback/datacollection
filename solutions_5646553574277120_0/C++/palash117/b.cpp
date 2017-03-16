#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
	int arr[200];
void check(vector<int> v,int n){
	int tmp,tt,t3;
	tt=0;
	for(int i=1;i<=((1<<(n+1))-1);i++){
		tmp=i;
		tt=0;
		t3=0;
		while(tmp>0){
			if(tmp%2==1){
				t3+=v[tt];
			}
			tt++;
			tmp/=2;
		}
		if(t3<=200)
			arr[t3]=1;
	}
}
int main(){
	int t,cas;
	ifstream fin("b.in");
	ofstream fout("b.out");
	fin>>t;
	cas=0;
	while(t--){
		cas++;
		vector<int> v;
		int n;
		int tmp,ans,vi,c;
		for(int i=0;i<100;i++)
			arr[i]=0;
		fin>>c;
		fin>>n;
		fin>>vi;
		for(int i=0;i<n;i++){
			fin>>tmp;
			v.push_back(tmp);
		}
		ans=0;
		check(v,n);
		for(int i=1;i<vi;i++){
			if(arr[i]!=1){
				ans++;
				v.push_back(i);
				n++;
				check(v,n);
			}
		}
	//	for(int i=0;i<n;i++)
	//		fout<<v[i]<<" ";
		fout<<"Case #"<<cas<<": "<<ans<<"\n";
	}
}
