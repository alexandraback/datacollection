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

vector<int> v2;

bool func(double p,int a,int cnt){
	double p2 = cnt*p+a,p3=0;
	for(int i=0;i<SZ(v2);i++){
		if(p2<=v2[i]) break;
		else p3+=(p2-v2[i])/cnt;
	}
	return p3>1.0;
}

int main(){
	ofstream cout("/Users/admin/Downloads/output.txt");
	ifstream cin("/Users/admin/Downloads/input.txt");
	cout << setprecision(6);
	cout << setiosflags(ios::fixed); 
	int t,n;
	cin>>t;
	for(int ii=1;ii<=t;ii++){
		cin>>n;
		vector<int> v;
		v2.clear();
		int cnt=0,T;
		for(int i=0;i<n;i++){
			cin>>T;
			v.push_back(T);
			v2.push_back(T);
			cnt+=T;
		}
		vector<double> ans;
		SORT(v2);
		for(int i=0;i<n;i++){
			double l=0,r=1,mid;
			for(int j=0;j<100;j++){
				mid=(l+r)/2.0;
				if(func(mid,v[i],cnt)) r=mid;
				else l=mid;
			}
			ans.push_back(mid*100);
		}
		cout<<"Case #"<<ii<<": ";
		for(int i=0;i<n-1;i++) cout<<ans[i]<<" ";
		cout<<ans[n-1]<<endl;
	}
}