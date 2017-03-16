#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int a[1 << 20];

int isVowel(char c){
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

long long solve(){
	long long ret = 0;
	char c;
	int l = 0, len  = 0, tail = -1, n;
	getchar();
	while ((c = getchar()) != ' ')
		a[l++] = !isVowel(c);
	scanf("%d", &n);
	for (int i = 0; i < l; ++i){
		if (i + len - 2 == tail)
			--len;
		while (len < n){
			if (++tail == l)
				break;
			if (a[tail])
				++len;
			else 
				len = 0;
		}
		if (tail == l)
			break;
		ret += l - tail;
	}
	return ret;
}

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		cout << "Case #" << i + 1 << ": " << solve() << endl;
	return 0;
}