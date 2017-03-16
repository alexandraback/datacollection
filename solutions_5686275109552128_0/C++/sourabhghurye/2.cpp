#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int maxx(int a,int b){
	if(a>b) return a;
	return b;
}

int main(){
	int t;cin>>t;
	for(int qq=1;qq<=t;qq++){
		int d;cin>>d;
		vector<int> v(d);
		for(int i=0;i<d;i++) cin>>v[i];
		
		
		int m=*max_element(v.begin(), v.end());
		int min=m;
		for(int i=1;i<m;i++){
			int c=0;
			for(int j=0;j<d;j++){
				c+=(v[j]/i-1);
				if(v[j]%i!=0) c++;
			}
			if(c+i<min) min=c+i;
		}
		cout<<"Case #"<<qq<<": "<<min<<endl;
	}
}
