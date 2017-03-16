#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

int count[3000];

int main(){
	int TC, c= 1;
	scanf("%d",&TC);
	while(TC--){
		priority_queue<int, vector<int>, greater<int> > q;
		memset(count, 0, sizeof count);
		int N, input;
		scanf("%d", &N);
		for (int i = 0; i < 2*N-1; i++){
			for (int j = 0; j < N; j++){
				cin >> input;
				if (count[input]++ == 0)
					q.push(input);
			}
		}
		printf("Case #%d: ",c++);
		while (!q.empty()){
			int elt = q.top();
			if (count[elt] % 2 == 1)
				printf("%d ",elt);
			q.pop();
		}
		printf("\n");
	}
	return 0;
}
