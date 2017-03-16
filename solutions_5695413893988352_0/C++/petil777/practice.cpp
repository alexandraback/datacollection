#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <iostream>
#include <string>
using namespace std;
#define ll long long
string str1, str2, t1, t2, ans1, ans2;
ll key= 0xffffffffffffff;
int test;
void go(int now)
{
	if (now == str1.size()){
		ll dif = abs(stoll(t1) - stoll(t2));
		if (key > dif){
			key = dif;
			ans1 = t1; ans2 = t2;
		}
		else if (key == dif){
			if (ans1 > t1){
				ans1 = t1; ans2 = t2;
			}
			else if (ans1 == t1 && ans2 > t2){
				ans2 = t2;
			}
		}
		return;
	}
	if (str1[now] != '?' && str2[now] != '?'){
		t1.push_back(str1[now]); t2.push_back(str2[now]);
		go(now + 1);
		t1.pop_back(); t2.pop_back();
	}
	else if (str1[now] == '?' && str2[now]!='?'){
		t2.push_back(str2[now]);
		for (int i = 0; i < 10; i++){
			t1.push_back('0'+i);
			go(now + 1);
			t1.pop_back();
		}
		t2.pop_back();
	}
	else if (str1[now] != '?' && str2[now] == '?'){
		t1.push_back(str1[now]);
		for (int i = 0; i < 10; i++){
			t2.push_back('0'+i);
			go(now + 1);
			t2.pop_back();
		}
		t1.pop_back();
	}
	else{
		for (int i = 0; i < 10; i++){
			for (int j = 0; j < 10; j++){
				t1.push_back('0' + i);
				t2.push_back('0' + j);
				go(now + 1);
				t1.pop_back();
				t2.pop_back();
			}
		}
	}
}
int main(){
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B0.txt", "w", stdout);

	cin >> test;
	int lev = 0;
	while (test--){

		key = 0xffffffffffffff;
		++lev;
		ans1.clear(); ans2.clear();
		ans1 = "99999999999";
		ans2 = "99999999999";
		t1.clear(); t2.clear();
		cin >> str1 >> str2;
		go(0);
		printf("Case #%d: ", lev);
		cout << ans1 << " " << ans2 << endl;
	}
}