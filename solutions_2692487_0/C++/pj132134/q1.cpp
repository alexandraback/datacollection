#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;


class mycomparison
{
public:
	bool operator() (int lhs, int rhs) const
	{
		return lhs > rhs;
	}
};  //ascending order



int solve(int currentsize, priority_queue<int,vector<int>,mycomparison> pq,int no_steps){
	if (pq.size()==0) {
		return no_steps;
	}
	//printf("cursize= %d pq.top= %d\n",currentsize,pq.top());
	if (currentsize>pq.top()) {
		currentsize+=pq.top();
		pq.pop();
		return solve(currentsize,pq,no_steps);
	}
	else {
		int a = 400000000;
		if (currentsize > 1) {
			a = solve(currentsize+currentsize-1,pq,no_steps+1);
		}
		pq.pop(); //deletion
		int b = solve(currentsize,pq,no_steps+1);
		return min(a,b);
	}

}

int main ()
{
	int no_testcases;
	scanf("%d", &no_testcases);
	
	
	for (int i=0; i<no_testcases; i++) {
		int A,N;
		int temp100;
		priority_queue<int,vector<int>,mycomparison> pq;
		
		scanf("%d",&A);
		scanf("%d",&N);
		for (int j=0; j<N; j++) {
			scanf("%d",&temp100);
			pq.push(temp100);
			
		}
		int answer = solve(A,pq,0);
		
		printf("Case #%d: %d\n",i+1,answer);
		
		
	}
	
	return 0;
}