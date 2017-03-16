#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int T;
char ch[1100];
string ct,c1,c2;

int main() {
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int kase = 1;kase <= T; kase++) {
		scanf("%s",ch);
		int len = strlen(ch);
		ct = ch[0];
		for (int i = 1;i < len; i++) {
			c1 = ct + ch[i];
			c2 = ch[i] + ct;
			if (c1 < c2) ct = c2;
			else ct = c1;
		}
		printf("Case #%d: ",kase);
		cout<<ct<<endl;
	}
	return 0;
}