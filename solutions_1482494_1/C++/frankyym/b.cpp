#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int A[1100], B[1100], first[1100], second[1100];
bool used[1100];

bool sortFirst(int i, int j) {
	return A[i] <= A[j];
}

bool sortSecond(int i, int j) {
	return B[i] <= B[j];
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t=0; t<T; ++t) {
		int N;
		scanf("%d", &N);
		for (int i=0; i<N; ++i) {
			first[i] = i;
			second[i] = i;
			used[i] = 0;
			scanf("%d%d", &A[i], &B[i]);
		}
//		sort(first, first+N, sortFirst);
//		sort(second, second+N, sortSecond);
		
		for (int i=0; i<N; ++i) for (int j=i+1; j<N; ++j) 
			if (B[second[i]] > B[second[j]]) {
				swap(second[i], second[j]);
			}
		
		int collect = 0;
		int step = 0;
		int pFirst = 0, pSecond = 0;
		for (;;) {
			bool quit = true;
			
			while (pSecond < N) {
				int k = second[pSecond];
				if (collect >= B[k]) {
					if (!used[k]) collect += 2;
					else collect += 1;
					used[k] = 1;
					pSecond += 1;
					++step;
					quit = false;
				}
				else break;
			}
			
			/*
			while (pFirst < N) {
				int k = first[pFirst];
				if (used[k]) {
					++pFirst;
					continue;
				}
				
				if (collect >= A[k]) {
					collect += 1;
					used[k] = 1;
					pFirst++;
					++step;
					quit = false;
				}
				break;
			}*/
			
			
			int choice = -1;
			for (int i=0; i<N; ++i) if (!used[i]) {
				if (collect >= A[i]) {
					if ((choice == -1) || (B[choice] < B[i])) choice = i;
				}
			}
			if (choice != -1) {
				collect++;
				used[choice] = 1;
				++step;
				quit = 0;
			}
			
			if (quit) break;
		}
		
		printf("Case #%d: ", t+1);
		if (pSecond < N) printf("Too Bad\n");
		else printf("%d\n", step);
	}
	return 0;
}