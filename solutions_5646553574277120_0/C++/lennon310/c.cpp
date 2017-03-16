#include<iostream>
#include<algorithm>
#include<cstring>
#include <string>
#include<vector>
#include <queue>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,d;
ll V;
ll coin[101];
int main(){
   // freopen("input1.txt","r",stdin);
   freopen("C-small-attempt1.in","r",stdin);
  // freopen("A-large-practice.in","r",stdin);
    freopen("output1.txt","w",stdout);
    
    int t;
    cin >> t;
	
    for(int ti=1;ti<=t;ti++){
		cout << "Case #"<<ti<<": ";
        cin>>c>>d>>V;
		for(int i=0;i<d;i++) cin>>coin[i];
		vector<int> v;
		map<int,int> mp;
		for(int i=1;i<pow(2,d);i++){
			int tmp = 0;
			for(int j=0;j<d;j++){
				if (i&(1<<j)) tmp += coin[j];
			}
			if (tmp>V) continue;
			if (find(v.begin(),v.end(),tmp)==v.end()) v.push_back(tmp),mp[tmp] = 1;
		}
		/*for(int i=0;i<v.size();i++) cout << v[i] << ", ";
		cout << endl;*/
		sort(v.begin(),v.end());
		int cnt = 0;
		for(int i=1;i<=V;i++){
			if (mp.count(i)) continue;
			mp[i] = 1;
			cnt ++;
			//v.push_back(i);
			for(int j=0;j<v.size();j++){
				mp[v[j]+i] = 1;
			}
			if (find(v.begin(),v.end(),i)==v.end()) v.push_back(i);
			for(auto it=mp.begin();it!=mp.end();it++){
				int tm = it->first;
				if (find(v.begin(),v.end(),tm)==v.end()) v.push_back(tm);
			}
		}
		cout << cnt << "\n";
    }
    return 0;
}
