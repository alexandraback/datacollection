#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

#define NMAX 20

int n;
map<int, int> sumState;
int num[NMAX];
bool found;
int state1, state2;

void dp(int id, int state, int sum){
	if (found)
		return;
	if (id>n){
		if (sumState.find(sum) == sumState.end())
			sumState[sum] = state;
		else if (sumState[sum] != state){
			found = true;
			state1 = sumState[sum];
			state2 = state;
		}
		return;
	}
	int newState = state |= (1<<id);
	dp(id+1, state, sum);
	dp(id+1, newState, sum+num[id]);
}

void brute2(){
	int state = 0;
	while (state++ < 1048575){
		int sum = 0;
		for (int i=0; i<n; i++){
			int tchk = state & (1<<i);
			if (tchk)
				sum += num[i];
		}

		if (sumState.find(sum) == sumState.end())
			sumState[sum] = state;
		else {
			state1 = sumState[sum];
			state2 = state;
			found = true;
			break;
		}
	}
}

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int tc;
	cin >> tc;
	for (int tci=0; tci<tc; tci++){
		cin >> n;
		for (int i=0; i<n; i++)
			cin >> num[i];

		sumState.clear();
		found = false;
		//dp(0, 0, 0);
		brute2();
		printf("Case #%d:\n", tci+1);

		if (found){
			int tchk;
			bool first = true;
			for (int i=0; i<n; i++){
				tchk = state1 & (1<<i);
				if (tchk){
					if (first) first = false;
					else printf(" ");
					printf("%d", num[i]);
				}
			}
			printf("\n");

			first = true;
			for (int i=0; i<n; i++){
				tchk = state2 & (1<<i);
				if (tchk){
					if (first) first = false;
					else printf(" ");
					printf("%d", num[i]);
				}
			}
			printf("\n");
		}else
			printf("Impossible\n");
	}
}