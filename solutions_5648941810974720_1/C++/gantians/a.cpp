#include <iostream>
#include <cstdio>
#include <cstring>
#include <bits/stdc++.h>

using namespace std;

char ch[110];
int a[200];
vector<int> ans;

void gao(int x,int y){
	for (int i=0;i<y;i++) ans.push_back(x);
}

int main(){
	int T;
	cin >> T;
	for (int ti=1;ti<=T;ti++){
		string s;
		cin >> s;
		ans.clear();
		memset(a,0,sizeof(a));
		for (int i=0;i<s.length();i++)
			a[s[i]]++;
		gao(0, a['Z']);
		gao(2, a['W']);
		gao(8, a['G']);
		gao(6, a['X']);
		gao(4, a['U']);
		gao(3, -a['G']+a['H']);
		gao(7, -a['X']+a['S']);
		gao(5, -a['U']+a['F']);
		gao(1, a['O']-a['U']-a['Z']-a['W']);
		gao(9, a['I']-a['G']-a['X']-a['F']+a['U']);


		sort(ans.begin(),ans.end());
		cout << "Case #" <<ti <<": ";
		for (int i=0;i<ans.size();i++) cout<<ans[i];
		cout<<endl;
	}
	return 0;
}
