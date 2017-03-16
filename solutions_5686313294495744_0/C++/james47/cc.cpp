/*************************************************************************
    > File Name: cc.cpp
    > Author: james47
    > Mail: 
    > Created Time: Sun May  1 01:59:13 2016
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int T, cas = 0;
int n;
char s1[1100][30];
char s2[1100][30];
int main()
{
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%s %s", s1[i], s2[i]);
		int ans = 0;
		for (int i = 1; i < (1<<n); i++){
			int temp = 0;
			for (int j = 0; j < n; j++){
				if ((i & (1<<j)) == 0){
					bool f1 = false, f2 = false;
					for (int k = 0; k < n; k++){
						if ((i & (1<<k)) && strcmp(s1[j], s1[k]) == 0)
							f1 = true;
					}
					for (int k = 0; k < n; k++){
						if ((i & (1<<k)) && strcmp(s2[j], s2[k]) == 0)
							f2 = true;
					}
					if (f1 && f2)
						temp ++;
				}
			}
			if (temp > ans) ans = temp;
		}
		printf("Case #%d: %d\n", ++cas, ans);
	}
	return 0;
}
