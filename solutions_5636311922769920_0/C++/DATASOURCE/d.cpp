#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	for(int Case = 1; Case <= t; Case++){
		int k, c, s;
		scanf("%d%d%d", &k, &c, &s);
		printf("Case #%d: ", Case);
        for(int i = 0; i < s; i++)
            printf("%d%c", i + 1, i == s - 1 ? '\n' : ' ');
	}
	return 0;
}

