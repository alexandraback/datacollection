#include <bits/stdc++.h>
using namespace std;
int tcs;
char buf[10000];
deque<char> pq;
int main(){
	scanf("%i\n", &tcs);
	for(int tc=1;tc<=tcs;tc++){
		gets(buf);
		pq.clear();
		pq.push_back(buf[0]);
		for(int i=1;i<strlen(buf);i++){
			if(buf[i] < pq.front()) pq.push_back(buf[i]);
			else pq.push_front(buf[i]);
		}
		printf("Case #%i: ", tc);
		while(!pq.empty()){
			printf("%c", pq.front());
			pq.pop_front();
		}
		printf("\n");
	}
}