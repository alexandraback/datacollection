#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

int t,i;
deque <char> ans;
char s[1005];

void init(){
}

int main(){
	scanf("%d", &t);
	int testcase = 0;
	while(++testcase <= t){
		init();
		scanf("%s", s);
		int l = strlen(s);
		ans.push_back(s[0]);
		for(i = 1; i < l; i++){
			if(ans.front() <= s[i])
			ans.push_front(s[i]);
			else
			ans.push_back(s[i]);
		}
		printf("Case #%d: ", testcase);
		while(ans.size()){
			printf("%c", ans.front());
			ans.pop_front();
		}
		printf("\n");
	}
}

