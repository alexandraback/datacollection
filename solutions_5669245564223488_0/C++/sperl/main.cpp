#include <stdio.h>

#include <list>
#include <string.h>

#define N_MAX 151
#define ll long long

#define BEGIN 0
#define END 1
#define MIDDLE 2
#define FULL 3


char in[102][102];

int follower[26];

std::list<int> lst[26][4];

ll fac(int n) {
	ll res = n;
	while(n > 1) {
		n--;
		res *= n;
	}
	return res;
}

void note(char x, int sys, int num) {
	//printf("Added #%d in %c of %d\n", num, x, sys);
}

void message(int i) {
	//printf("Passed point %d\n", i);
}

void multiplied(ll i) {
	//printf("Multiplied with %lld\n", i);
}

void reduce(int p, int am) {
	//printf("redu %d of %d\n", p, am);
}

void solve() {

	for (int i = 0; i < 26; i++) {
		follower[i] = -1;
		lst[i][BEGIN].clear();
		lst[i][END].clear();
		lst[i][MIDDLE].clear();
		lst[i][FULL].clear();
	}

	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", &in[i][0]);
		
		char begin;
		char end;
		char last;
		bool same = true;
		int length = strlen(&in[i][0]);
		for (int j = 0; j < length; j++) {
			if (j == 0) {
				begin = in[i][j];
				same = true;
			}
			if (j == length-1) {
				if (in[i][j] == begin && same) {
					// full
					lst[begin-'a'][FULL].push_back(i);
					note(begin, FULL, i);
				}
				else {
					end = in[i][j];
					// push begin and end
					lst[begin-'a'][BEGIN].push_back(i);
					lst[end-'a'][END].push_back(i);
					
					note(begin, BEGIN, i);
					note(end, END, i);
					
					if (in[i][j] != last && !same) {
						lst[last-'a'][MIDDLE].push_back(i);
						note(last, MIDDLE, i);
					}
				}
			}
			else {
				if (same) {
					if (in[i][j] == begin) {
						// nothing -> stay same
					}
					else {
						// nothing -> was same
						same = false;
					}
				}
				else if(in[i][j] != last) {
					// push last as middle
					lst[last-'a'][MIDDLE].push_back(i);
					note(last, MIDDLE, i);
				}
			}
			last = in[i][j];
		}
	}
	
	ll possibilities = 1;
	int free = N;
	
	for (int i = 0; i < 26; i++) {
		if (lst[i][MIDDLE].size() == 1) {
			if (lst[i][BEGIN].size() > 0 || lst[i][END].size() > 0 || lst[i][FULL].size() > 0) {
				message(1);
				printf("0");
				return;
			}
		}
		else if (lst[i][MIDDLE].size() > 1) {
			message(2);
			printf("0");
			return;
		}
		
		if (lst[i][BEGIN].size() > 1 || lst[i][END].size() > 1) {
			message(3);
			printf("0");
			return;
		}
		
		if (lst[i][BEGIN].size() == 1 && lst[i][END].size() == 1) {
			// set follower
			int end = *(lst[i][END].begin());
			int begin = *(lst[i][BEGIN].begin());
			follower[end] = begin;
			free--;
			
			reduce(1, -1);
			
			int curr = begin;
			while(curr != -1) {
				if (curr == end) {
					message(4);
					printf("0");
					return;
				}
				curr = follower[curr];
			}
		}
		
		if (lst[i][FULL].size() > 0) {
			possibilities *= fac(lst[i][FULL].size());
			free = (free - lst[i][FULL].size()) + 1;
			
			reduce(2, - lst[i][FULL].size() + 1);
			
			multiplied(fac(lst[i][FULL].size()));
			
			if (lst[i][BEGIN].size() > 0 || lst[i][END].size() > 0) {
				free--;
				reduce(3, 1);
			}
		}
	}
	
	multiplied(fac(free));
	possibilities *= fac(free);
	
	printf("%lld", possibilities);
}

int main() {
	
	int T = 0;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++)  {
		printf("Case #%d: ", t);
		solve();
		printf("\n");
	}
}


