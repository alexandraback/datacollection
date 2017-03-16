#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main(){
	deque<char> str;
	int times;
	char s[1010];
	scanf("%d\n", &times);
	for (int t=1; t<=times; t++){
		gets(s);
		str.clear();
		for (int i=0; s[i]!='\0'; i++){
			if (s[i]>=str.front()){
				str.push_front(s[i]);
			}else{
				str.push_back(s[i]);
			}
		}
		printf("Case #%d: ", t);
		for (int i=0; s[i]!='\0'; i++){
			printf("%c", str[i]);
		}
		putchar('\n');
	}
	
	return 0;
}
