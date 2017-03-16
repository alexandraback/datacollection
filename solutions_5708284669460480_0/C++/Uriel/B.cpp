#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#define N 110
using namespace std;

#define INF 0x7FFFFFFF

FILE *fp, *fw;

int fg[100];

int nxt[N], len1, len2, ans;
char s1[N], s2[N], key[N];
 
void getnext(){
    int k,j;
    len1=strlen(s1);
    nxt[0]=-1;
    j=0;
    k=-1;
    while(j<len1){
        if(k==-1||s1[k]==s1[j]){
            k++;
            j++;
            nxt[j]=k;
        }
        else
            k=nxt[k];
    }
    return ;
}
 
int kmp(){
    int j, k, cnt;
    len2=strlen(s2);
    j = k = ans = 0;
    cnt=1;
    getnext();
    while(j<len2&&k<len1){
        if(k==-1||s2[j]==s1[k]){
            j++;
            k++;
        }
        else
            k=nxt[k];
        if(k==len1){
            ans++;
            k=nxt[k];
		}
    }
    return ans;
}

void add_char(int x, int len) {
	int k = 0, j, t = 1, i;
	for(i = 1; i < len; ++i) t *= 10;
	for(; t >= 1; t /= 10) {
		j = x / t;
		x %= t;
		s2[k++] = key[j - 1];
	}
}

int main() {
	fp = fopen("H:\\GCJ\\150510_R1C\\B-small-attempt0.in", "r");
	//fp = fopen("H:\\GCJ\\150510_R1C\\in.txt", "r");
	fw = fopen("H:\\GCJ\\150510_R1C\\outBs.txt", "wt");
	int cse, g = 1, l, i, n, j, c, d, v, t, a[10], res, k, tp, maxt, ttp, ok;
	double cnt, nt;
	fscanf(fp, "%d", &cse);
	while(cse--) {
		fscanf(fp, "%d %d %d", &k, &l, &n);
		fscanf(fp, "%s", key);
		fscanf(fp, "%s", s1);
		cnt = 0; nt = 0;
		t = 1;
		for(i = 1; i < n; ++i) {
			t *= 10;
			t += 1;
		}
		maxt = 0;
		for(i = t; i <= k * t; ++i) {
			ttp = i;
			ok = 1;
			while(ttp > 0) {
				if((ttp % 10 > k) || !(ttp % 10)) {
					ok = 0;
					break;
				}
				ttp /= 10;
			}
			if(!ok) continue;
			//printf("~%d\n", i);
			memset(s2, 0x00, sizeof(s2));
			add_char(i, n);
			//puts(s2);
			tp = kmp();
			if(tp > maxt) maxt = tp;
			cnt += 1.0 * tp;
			nt += 1.0;
		}
		cnt /= nt;
		fprintf(fw, "Case #%d: %.7lf\n", g++, 1.0 * maxt - cnt);
	}
	fclose(fp); 
	fclose(fw);
	system("PAUSE");
	return 0;
}