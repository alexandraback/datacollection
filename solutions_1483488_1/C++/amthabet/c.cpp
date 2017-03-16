#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<memory.h>
using namespace std;

vector<int> table[2000100];

int main()	{

	//freopen("c_sample.in","rt",stdin);
	
	//freopen("c_small.in","rt",stdin);
	//freopen("c_small.out","wt",stdout);

	freopen("c_large.in","rt",stdin);
	freopen("c_large.out","wt",stdout);

	for(int i=1;i<=2000000;i++) {
		vector<int> v;
		for(int j=i;j;j/=10) v.push_back(j%10);
		reverse(v.begin(), v.end());
		vector<int> v2 = v;
		set<int> st;
		for(int j=0;j+1<v.size();j++) {
			rotate(v.begin(), v.begin()+1, v.end());
			if(v[0] != 0 && v < v2) {
				int cur=0;
				for(int k=0;k<v.size();k++) cur=cur*10+v[k];
				if(st.insert(cur).second == true)
					table[i].push_back(cur);
			}
		}
	}

	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++) {
		int a,b;
		cin>>a>>b;
		
		int ans = 0;
		for(int i=a;i<=b;i++)
			for(int j=0;j<table[i].size();j++)
				if(table[i][j] >= a)
					ans++;

		cout<<"Case #"<<tt<<": "<<ans<<endl;
	}

	return 0;
}