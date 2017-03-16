#include <bits/stdc++.h>
using namespace std;
set<char> all;
bool check(int n) {
	stringstream str;
	str << n;
	string s = str.str();
	for (int i = 0; i < s.length(); ++i) all.erase(s[i]);
	return all.size() == 0;
}
int main(int argc, char const *argv[]) {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) {
    	printf("Case #%d: ", i);
    	int n;
    	scanf("%d", &n);
    	if (n == 0) {
    		printf("INSOMNIA\n");
    		continue;
    	}
    	all.clear();
    	for (int j = 0; j < 10; ++j) all.insert((char)j + 48);
    	int sum = n;
    	while (sum <= 1e7) {
    		if (check(sum)) {
    			printf("%d\n", sum);
    			break;
    		}
    		sum += n;
    	}
    }
	return 0;
}