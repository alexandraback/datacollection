#include <bits/stdc++.h>
using namespace std;
string conv(int n, int b) {
	string ret = "";
	for (int i = 0; i < b; ++i) ret += ((n >> i) & 1) ? "11" : "00";
	return "11" + ret + "11";
}
int main(int argc, char const *argv[]) {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) {
    	printf("Case #%d:\n", i);
    	int n, b;
    	scanf("%d%d", &b, &n);
    	for (int j = 1; j <= n; ++j) {  
    		cout << conv(j, (b >> 1) - 2) << " ";
    		for (int z = 3; z <= 11; ++z) printf("%d ", z);
    		printf("\n");
    	}
    }
	return 0;
}