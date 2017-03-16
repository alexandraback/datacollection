#include<stdio.h>
#include<queue>
#include<string.h>
#include<iostream>
using namespace std;
string s, s0, s1, s2;
int main() {
	int T;
	cin>>T;
	int cas = 1;
	while (T--) {
		printf("Case #%d: ", cas++);
		cin >> s;
		int l = s.size();
		s0 = s[0];
		for (int i = 1; i < l; i++) {
			s1 = s0 + s[i];
			s2 = s[i] + s0;
			if (s1 > s2)
				s0 = s1;
			else
				s0 = s2;
		}
		cout << s0 << endl;
		//dq.push_front()//在头部加入一个数据
		//dq.push_back()//在尾部加入一个数据
	}
	return 0;
}
