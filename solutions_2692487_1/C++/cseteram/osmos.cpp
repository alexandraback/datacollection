#include<stdio.h>
#include<queue>
#include<algorithm>

using namespace std;

queue<int> Q;
int arr[110];

int main() {

	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);

	int T,A,N;
	int t,i,temp,size,ans,s,now;
	
	scanf("%d", &T);

	for(t=1 ; t<=T ; t++) {

		while(Q.empty()==false) Q.pop();	// init
		ans=999999, now=0;

		scanf("%d %d", &A, &N);		// sort
		for(i=1 ; i<=N ; i++)
			scanf("%d", &arr[i]);
		sort(arr+1,arr+1+N);
		for(i=1 ; i<=N ; i++)
			Q.push(arr[i]);

		if(A==1) ans=Q.size();		//solve
		else {
			size=A;
			while(Q.empty()==false) {
				s=Q.front();
				if(size>s) size+=s, Q.pop();
				else {
					if(now+Q.size()<ans) ans=now+Q.size();
					size+=(size-1), now++;
				}
			}
		
			if(now<ans) ans=now;
		}

		printf("Case #%d: %d\n", t, ans);

	}

	return 0;
}