/*
 * b.cpp
 *
 *  Created on: 2012-4-14
 *      Author: whimsy
 */
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int Test;
int n,s,p,ans;

void work(){
	cin >> n >> s >> p;
	ans = 0;
	int tmp;
	int cnt = 0;
	for (int i = 0;i<n;++i){
		cin >> tmp;
		if (tmp >= 3*p-2) ++ ans;
		else
		if (tmp >= 2 && tmp >=3*p-4) ++cnt;
	}
//	cout << ans << cnt << s << "   ";
	if (cnt < s) ans += cnt; else  ans += s;
	cout << ans << endl;
}

int main(){
	freopen("in.txt","r",stdin);
	freopen("b.txt","w",stdout);
//	cout << "what" << endl;
	cin >> Test;
	for (int ii = 0;ii<Test;++ii){
		printf("Case #%d: ",ii+1);
		work();
	}
	return 0;
}



