#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
const int a_o=3;
const int a_e=3;

int main(){
	int T;
	cin>>T;
	int ans=0;
	int n,len;
	for(int cs=1;cs<=T;++cs){
		cin>>len;
		cin>>n;
		vector<int> v_o;
		vector<int> v_e;
		v_o.resize(len/2-1);
		v_e.resize(len/2-1);
		for(int i=0;i<len/2-1;++i){
			if(i<len/2-1-a_o)
				v_o[i] = 0;
			else
				v_o[i] = 1;
			if(i<len/2-1-a_e)
				v_e[i] = 0;
			else
				v_e[i] = 1;
		}
		cout<<"Case #"<<cs<<":"<<endl;
		for(int i=0;i<n;++i){
			cout<<"1";
			for(int j=0;j<len/2-1;++j){
				cout<<v_o[j]<<v_e[j];
			}
			cout<<"1";
			for(int j=2;j<=10;++j)
				cout<<" "<<j+1;
			cout<<endl;
			if(!next_permutation(v_o.begin(),v_o.end()))
				next_permutation(v_e.begin(),v_e.end());
		}
	}
	return 0;
}
