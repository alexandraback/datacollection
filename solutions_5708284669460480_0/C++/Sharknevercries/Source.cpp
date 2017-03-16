#include<bits\stdc++.h>
using namespace std; 
int cnt[26], fail[105], maxC;
double expect;
int sum;
int K, L, S;
double pr[105];
string p, q;
void DFS(int st, int c, double p, int maxS, bool a){
	if (st > maxS)	return;
	if (st == maxS){
		if (p > 0)
			expect += p * c, maxC = max(maxC, c);
	}
	else{
		if (L > 1 && fail[L - 1] == L - 2 && q[L - 1] == q[L - 2])
			DFS(st + 1, c + 1, p*pr[L - 1], maxS, true);
		else{
			bool v[27] = { false };
			if (a){
				for (int i = L - 1; i != -1 && fail[i] != -1; i = fail[i])
					DFS(st + L - (fail[i] + 1), c + 1, p * pr[fail[i]], maxS, true), v[q[fail[i] + 1] - 'A'] = true;
			}
			v[q[0] - 'A'] = true;
			DFS(st + L, c + 1, p * pr[0], maxS, true);
			int abc = K;
			for (int i = 0; i < 26; i++)
				if (v[i])
					abc -= cnt[i];
			DFS(st + 1, c, p * abc / K, maxS, false);
		}
	}
}
int main(){
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t ,ta = 1;
	scanf("%d", &t);
	while (t--){
		scanf("%d%d%d", &K, &L, &S);
		cin >> p >> q;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < K; i++)
			cnt[p[i] - 'A']++;
		for (int i = 1, j = fail[0] = -1; i < L; i++){
			while (j >= 0 && q[j + 1] != q[i])	j = fail[j];
			if (p[j + 1] == q[i])	j++;
			fail[i] = j;
		}
		maxC = -1, expect = sum = 0;
		for (int i = 0; i <= L; i++)
			pr[i] = 1;
		for (int i = L - 1; i >= 0; i--)
			pr[i] = pr[i + 1] * cnt[q[i] - 'A'] / K;
		DFS(0, 0, 1, S, false);
		printf("Case #%d: %lf\n", ta++, maxC - expect);
	}
	return 0;
}