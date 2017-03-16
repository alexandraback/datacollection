#include<cstdio>
#include<cstdlib>
#include<string.h>

int main() {
	int T;
	scanf("%d", &T);
	for (int nm=1;nm<=T;nm++) {
		int K, L, S;
		scanf("%d%d%d", &K, &L, &S);
		char key[101];
		scanf("%s", key);
		char target[101];
		scanf("%s", target);
		int nkey[26]={0}, ntarget[26]={0};
		int lenkey=strlen(key), lentarget=strlen(target);
		for (int i=0;i<lenkey;i++) {
			nkey[key[i]-'A']++;
		}
		bool unique = true;
		for (int i=0;i<lenkey;i++) {
			if (nkey[i]>0 && nkey[i]!=lenkey) {
				unique = false;
				break;
			}
		}
		for (int i=0;i<lentarget;i++) {
			ntarget[target[i]-'A']++;
		}
		bool pass = true;
		for (int i=0;i<26;i++) {
			if (ntarget[i]>0 && nkey[i]==0) {
				pass = false;
				break;
			}
		}
		//if (pass) //printf("pass = 1\n");
		//else //printf("pass = 0\n");
		int dup = 0;
		for (int pt=1;pt<lentarget;pt++) {
			bool pass = true;
			int i;
			for (i=0;i+pt < lentarget;i++) {
				if (target[i] != target[pt + i]) {
					pass = false;
					break;
				}
			}
			if (pass) {
				dup = i;
				break;
			}
		}
		//printf("dup = %d\n", dup);
		double remain = 1;
		for (int j=0;j<lentarget;j++) {
			remain*= (double)nkey[target[j]-'A']/(double)lenkey;
		}
		int all = (S - dup) / (lentarget - dup);
		//printf("all= %d\n", all);
		double exp = 0.0, tmp= 1.0, save= 1.0;
		for (int j=dup;j<lentarget;j++) {
			save*= (double)nkey[target[j]-'A']/(double)lenkey;
		}
		for (int i=1;i<=all;i++) {
			//printf("i= %d\n", i);
			if (i == 1) {
				for (int j=0;j<dup;j++) {
					tmp*= (double)nkey[target[j]-'A']/(double)lenkey;
				}
			}
			//printf("tmp= %lf, save= %lf\n", tmp, save);
			tmp*= save;
			double shift = S - dup-(lentarget-dup)*i+1;
			double sremain= remain*(double)(shift - 1);
			sremain= 1.0 - sremain;
			//printf("shift = %lf\n", shift);
			if (!(unique && i!=all)) {
				//printf("permited\n");
				exp+= tmp * (double)i * shift * sremain;
			}
			//printf("tmp= %lf, save= %lf\n", tmp, save);
			//printf("exp= %lf\n", exp);
		}
		//printf("end exp= %lf\n", exp);
		double ans;
		if (pass) ans = (double)all - exp;
		else ans = 0.0;
		printf("Case #%d: %.7lf\n", nm, ans);
		//printf("\n");
	}
	return 0;
}
