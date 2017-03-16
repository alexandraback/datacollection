#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;


int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int T, N;
	cin >> T;
	int s1[300], s2[300];
	for(int cas = 1; cas <= T; ++cas){
		cin >> N;
		double sum = 0, sumBak;
		for(int i = 0; i < N; ++i){
			cin >> s1[i];
			sum += s1[i];
			s2[i] = s1[i];
		}
		sort(s2, s2 + N);
		sumBak = sum;

		double aver = s2[0];
		int j = 1;
		for(j = 1; j < N; ++j){
			double d = (s2[j] - s2[j - 1]) * j;
			if(sum >= d){
				sum -= d;
				aver = s2[j];
			}
			else{
				break;
			}
		}
		aver += sum / j;
		printf("Case #%d:", cas);
		for(int i = 0; i < N; ++i){
			double res = 0;
			if(s1[i] < aver){
				res = (aver - s1[i]) * 100 / sumBak;
			}
			printf(" %.6f", res);
		}
		puts("");
	}

	return 0;
}
