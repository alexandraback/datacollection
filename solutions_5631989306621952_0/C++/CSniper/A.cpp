#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <cmath>
#include <iostream>
#define INF (1<<30)
using namespace std;

int main(){
	int t=0, c=0;
	scanf("%d", &t);
	while(t--){
		c++;
		vector<char> W;
		char s[20];
		scanf("%s", s);
		W.push_back(s[0]);
		int i=0;
		while(s[++i]){
			W.push_back(s[i]);
			if(W[W.size()-1]>=W[0])
				for(int i=W.size()-1; i>0; i--)
					swap(W[i], W[i-1]);
		}
		printf("Case #%d: ", c);
		for(int i=0; i<W.size(); i++)
			printf("%c", W[i]);
		printf("\n");
	}
	return 0;
}

