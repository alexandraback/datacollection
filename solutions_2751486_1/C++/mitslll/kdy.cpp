#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;


bool ja(char t){
	if(t == 'a' || t=='e' || t=='i' || t== 'o' || t == 'u')	return false;
	return true;
}
void process(){
	string s;
	int n, m;
	
	cin >> s >> m;
	n = s.length();
	long long ans = 0;
	vector<int> can(n,0);
	vector<int> num;
	can[0] = ja(s[0]);
	if(can[0] >= m)
		num.push_back(0);
	for(int i=1;i<n;i++){
		can[i] = ja(s[i]) * can[i-1] + ja(s[i]);
		if(can[i] >= m)
			num.push_back(i);
	}
	if(!num.size()){
		printf("0\n");
		return ;
	}
	num.push_back(n);
	for(int i=0;i<num.size()-1;i++){
		long long a, b;
		a = num[i] - m + 2;

		b = num[i+1] - num[i] ;
		ans += a * b;

	}
	printf("%lld\n",ans);
}

int main(){
	int t; scanf("%d",&t);
	for(int i=0;i<t;i++){
		printf("Case #%d: ",i+1);
		process();
	}
	return 0;
}
