#include <bits/stdc++.h>
using namespace std;
const int MAX = 1010;
char s[MAX];
deque<char>dq;
void solve(int tc){
  	scanf("%s", s);
  	dq.push_back(s[0]);
  	for(int i = 1; s[i]; i++){
  		if(dq.back() <= s[i])dq.push_back(s[i]);
  		else dq.push_front(s[i]);
  	}
  	printf("Case #%d: ", tc);
  	while(!dq.empty()){
  		printf("%c", dq.back());
  		dq.pop_back();
  	}
  	printf("\n");
}
int main(){
  int tc;
  scanf("%d", &tc);
  getchar();
  for(int i = 1; i <= tc; i++)solve(i);
}