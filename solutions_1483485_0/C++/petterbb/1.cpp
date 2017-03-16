#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;

char m[] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int n;
	cin >> n;
	char str1[101];
	getchar();
	for(int k = 1; k <= n; k++){
		gets(str1);
		cout << "Case #" << k << ": " ;
		for(int i = 0; i < strlen(str1); i++){
			if(str1[i] >= 'a' && str1[1] <= 'z')
				putchar(m[str1[i] - 'a']);
			else
				putchar(str1[i]);
		}
		putchar('\n');
	}

	return 0;
}
