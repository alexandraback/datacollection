#include<cstdio>

int d[3], m[3];

int main() {
	int t; scanf("%d", &t);
	for(int _ = 0; _ < t; _++) {
		int n; scanf("%d", &n);
		int cnt = 0;
		for(int i = 0; i < n; i++) {
			int dd, h, mm; scanf("%d%d%d", &dd, &h, &mm);
			for(int j = 0; j < h; j++) {
				d[cnt] = dd;
				m[cnt] = mm + j;
				cnt++;
			}
		}
		if(cnt >= 2) {
			if(m[0] == m[1]) {
				printf("Case #%d: 0\n", _+1);
				continue;
			}
			if(m[0] > m[1]) {
				int temp = m[1];
				m[1] = m[0];
				m[0] = temp;
				temp = d[1];
				d[1] = d[0];
				d[0] = temp;
			}
			if((360ll-d[1])*m[1] >= (720ll-d[0])*m[0]) {
				printf("Case #%d: 1\n", _+1);
			} else {	
				printf("Case #%d: 0\n", _+1);
			}
		} else {
			printf("Case #%d: 0\n", _+1);
		}
	}
	return 0;
}
