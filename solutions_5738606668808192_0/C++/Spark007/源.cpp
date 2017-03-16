#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<iostream>
#include<vector>
using namespace std;
int num = 0,J;
int yes(string coin, int bit){
	long long ans = 1;
	int len = coin.length();
	for (int i = 0; i < len; i++)
	{
		ans = ans*bit + coin[i] - '0';
	}
	ans = ans*bit+1;
	int aa = sqrt(ans);
	for (int i = 2; i < min(1000000,aa); i++){
		if (ans % i == 0)
			return i;
	}
	return 0;
}
bool ok(string coin){
	vector<int>v;
	for (int i = 2; i <= 10; i++){
		int ans = yes(coin, i);
		if (ans == 0)return 0;
		v.push_back(ans);
	}
	cout << "1" << coin << "1";
	for (int i = 0; i < v.size(); i++){
		printf(" %d",v[i]);
	}
	printf("\n");
	return 1;
}
void dfs(string coin,int len,int p){
	if (num >= J)
		return;
	if (p == len)
	{
		if (ok(coin))
			num++;
		return;
	}
	coin.append("0");
	dfs(coin,len,p+1);
	coin[p-1] = '1';
	dfs(coin,len,p+1);
}
int main(){
	//freopen("F:/c.out","w",stdout);
	int t;
	cin >> t;
	int n;
	int cas = 1;
	while (t--){
		num = 0;
		cin >> n >> J;
		printf("Case #%d: \n",cas++);
		string coin("");
		dfs(coin, n - 1, 1);
	}
	return 0;
}