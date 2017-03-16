#include <stdio.h>
int mul[5][5] = {{0,0,0,0,0},
{0,1,2,3,4},
{0,2,-1,4,-3},
{0,3,-4,-1,2},
{0,4,3,-2,-1}};
struct data {
	data() {
		data(0);
	}
	data(int x) {
		num = x;
	}
	int num;
};
data multiple(data a, data b) {
	int chk = 1, t1, t2;
	if(a.num < 0) {
		chk *= -1;
		t1 = -a.num;
	}
	else t1 = a.num;
	if(b.num < 0) {
		chk *= -1;
		t2 = -b.num;
	}
	else t2 = b.num;
	return data(chk*mul[t1][t2]);
}
char d[100050];
void YES(int x) {
	printf("Case #%d: YES\n", x);
	return;
}
void NO(int x) {
	printf("Case #%d: NO\n", x);
	return;
}
int main() {
	freopen("C-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T, i, j, k, L, i_pos, k_pos;
	long long X;
	data tot;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
		for(i = 0; i <= 100000; i++) d[i] = 0;
		scanf("%d %lld", &L, &X);
		scanf("%s", d);
		tot = data(1);
		for(i = 0; i < L; i++) {
			tot = multiple(tot, data(d[i]-'i'+2));
		}
		if(tot.num == 1) {
			NO(t);
			continue;
		}
		if(tot.num == -1 && X%2==0) {
			NO(t);
			continue;
		}
		if(tot.num != 1 && tot.num != -1 && X%4!=2) {
			NO(t);
			continue;
		}
		i_pos = k_pos = -1;
		if(X >= 8) {
			for(i = 1; i <= 3; i++) for(j = 0; j < L; j++) d[L*i+j] = d[j];
			tot = data(1);
			for(i = 0; i < 4*L; i++) {
				tot = multiple(tot, data(d[i]-'i'+2));
				if(tot.num == 2 && i_pos == -1) i_pos = i;
				if(tot.num == 4) k_pos = i;
			}
			if(i_pos != -1 && k_pos != -1) {
				YES(t);
				continue;
			}
			else {
				NO(t);
				continue;
			}
		}
		for(i = 1; i < X; i++) for(j = 0; j < L; j++) d[L*i+j] = d[j];
		tot = data(1);
		for(i = 0; i < X*L; i++) {
			tot = multiple(tot, data(d[i]-'i'+2));
			if(tot.num == 2 && i_pos == -1) i_pos = i;
			if(tot.num == 4) k_pos = i;
		}
		if(i_pos != -1 && k_pos != -1 && i_pos < k_pos) {
			YES(t);
			continue;
		}
		else {
			NO(t);
			continue;
		}
	}
	return 0;
}