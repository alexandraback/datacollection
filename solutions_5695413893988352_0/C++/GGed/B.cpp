#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define LLD long long
using namespace std;

int n;
char s[2][44];
LLD ret, opta, optb;

void tr(LLD a, LLD b){
	LLD d = abs(a - b);
	if (ret == -1) goto GOOD;
	if (d < ret) goto GOOD;
	else if (d == ret){
		if (a < opta) goto GOOD;
		else if (a == opta && b < optb) goto GOOD;
	}
	return;
	GOOD:
	ret = d, opta = a, optb = b;
	return;
}



LLD mxi(char s[]){
	char t[22];
	strcpy(t, s);
	FOR(i,0,n) if (t[i] == '?') t[i] = '9';
	LLD r;
	sscanf(t, "%lld", &r);
	return r;
}

LLD mni(char s[]){
	char t[22];
	strcpy(t, s);
	FOR(i,0,n) if (t[i] == '?') t[i] = '0';
	LLD r;
	sscanf(t, "%lld", &r);
	return r;
}

int main(){int tc;scanf("%d", &tc);FOE(TC,1,tc){printf("Case #%d:", TC);
	scanf("%s%s", s[0], s[1]);
	ret = -1;
	n = strlen(s[0]);
	
	FOR(i,0,n){
		if (s[0][i] != '?' && s[1][i] != '?' && s[0][i] != s[1][i]){
			if (s[0][i] > s[1][i]) tr( mni(s[0]), mxi(s[1]) );
			else tr( mxi(s[0]), mni(s[1]) );
			goto JMP2;
		}
		else if (s[0][i] == '?' && s[1][i] == '?'){
			s[0][i] = '1', s[1][i] = '0';
			tr( mni(s[0]), mxi(s[1]) );
			
			s[0][i] = '0', s[1][i] = '1';
			tr( mxi(s[0]), mni(s[1]) );
			
			s[0][i] = '0', s[1][i] = '0';
		}
		else if (s[0][i] == '?'){
			s[0][i] = s[1][i] + 1;
			if (s[0][i] <= '9') tr( mni(s[0]), mxi(s[1]) );
			s[0][i] = s[1][i] - 1;
			if (s[0][i] >= '0') tr( mxi(s[0]), mni(s[1]) );

			s[0][i] = s[1][i];
		}
		else if (s[1][i] == '?'){
			s[1][i] = s[0][i] + 1;
			if (s[1][i] <= '9') tr( mxi(s[0]), mni(s[1]) );
			s[1][i] = s[0][i] - 1;
			if (s[1][i] >= '0') tr( mni(s[0]), mxi(s[1]) );
			s[1][i] = s[0][i];
		}
		
	}
	tr( mni(s[0]), mxi(s[1]) );
	
	JMP2:
	char ss[111];
	sprintf(ss, " %%0%dlld %%0%dlld\n", n, n);
	printf(ss, opta, optb);
}return 0;}

