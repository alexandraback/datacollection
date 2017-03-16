#include <iostream>
#include <string.h>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stdlib.h>
#include <functional>
#include <iomanip>
#include <complex>
#include <stack>
#include <fstream>
#include <set>
#include <list>
#include <vector>
#include <climits>
#include <cfloat>
using namespace std;
typedef long long int ll;
#define EPS (1e-10) 
#define SZ(a) ((int)a.size())
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(),(v).rend())
#define MP make_pair



int main(){
	ofstream cout("/Users/admin/Downloads/output.txt");
	ifstream cin("/Users/admin/Downloads/input.txt");
	int t,n,m;
	cin>>t;
	for(int ii=1;ii<=t;ii++){
		cin>>n;
		map<int,int> mp;
		vector<int> v;
		for(int i=0;i<n;i++){
			cin>>m;
			v.push_back(m);
		}
		vector<int> ans[2];
		cout<<"Case #"<<ii<<":"<<endl;
		int cnt;
		bool ok=1;
		for(int i=1;i<(1<<n)&&ok;i++){
			cnt=0;
			for(int j=0;j<n;j++){
				if((i>>j)&1) cnt+=v[j];
			}
			if(mp[cnt]){
				for(int j=0;j<n;j++){
					if((i>>j)&1) ans[0].push_back(v[j]);
				}
				for(int j=0;j<n;j++){
					if((mp[cnt]>>j)&1) ans[1].push_back(v[j]);
				}
				ok = 0;
			}else mp[cnt]=i;
		}
		if(ok) cout<<"Impossible"<<endl;
		else{
			for(int i=0;i<SZ(ans[0])-1;i++) cout<<ans[0][i]<<" ";
			cout<<ans[0][SZ(ans[0])-1]<<endl;
			for(int i=0;i<SZ(ans[1])-1;i++) cout<<ans[1][i]<<" ";
			cout<<ans[1][SZ(ans[1])-1]<<endl;
		}
	}
}