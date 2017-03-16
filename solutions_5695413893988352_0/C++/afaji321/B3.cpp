#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <utility>
#include <iostream>
#include <map>
using namespace std;
char d1[33],d2[33];
int N;


bool cocok(string s,int x){

	int N = s.size();
	for (int i=N-1;i>=0;i--){

		char bz = x%10;
		x/=10;

		if (s[i] == '?')
			continue;
		if (s[i] != (bz + '0'))
			return 0;
	}
	if (x > 0)
		return 0;
	return 1;
}


int main() {

	int T = 0;
	int tt = 1;
	scanf("%d",&T);
	while (T--){

		printf("Case #%d: ",tt++);
		scanf("%s %s",d1,d2);
		int res = 99999;
		int r_a = 9999;
		int r_b = 9999;

		N = strlen(d1);
		for (int i=0;i<1000;i++)
			for (int j=0;j<1000;j++) {
				int dist = abs(i-j);
				if (dist > res)
					continue;
				if (cocok(d1,i) && cocok(d2,j)){
					int dist = abs(i-j);
					if (dist < res) {
						res = dist;
						r_a = i;
						r_b = j;
					}
				}
			}
		if (N==3)
			printf("%03d %03d\n",r_a,r_b);
		if (N==2)
			printf("%02d %02d\n",r_a,r_b);
		if (N==1)
			printf("%01d %01d\n",r_a,r_b);


	}
}