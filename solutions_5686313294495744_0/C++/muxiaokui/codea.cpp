#include <stdio.h>
#include <iostream>
#include <cstring>
	char s1[20],s2[20];
	int cs;
bool can(int p,int q){
	if(p==1){
		int ls = strlen(s1);
		if(ls==3){
				printf("hehe\n");
				if(s1[0] != '?' && s1[0]!=q/100 )return false;
				if(s1[1] != '?' && s1[1]!=(q/10)%10) return false;
				if(s1[2] != '?' && s1[2]!=q%10) return false;
		}
		if(ls==2 ){
				if(q>=100)return false;
				if(s1[0] != '?' && s1[1]!= q/10 )return false;
				if(s1[1] != '?' && s1[1]!=q%10 ) return false;
		}
		if(ls==1 ){
				if(q>=10)return false;
				if(s1[0] != '?' && s1[1]!= q )return false;
		}
	}
	if(p==1){
		int ls = strlen(s2);
		if(ls==3){
				if(s2[0] != '?' && s2[0]!=q/100 )return false;
				if(s2[1] != '?' && s2[1]!=(q/10)%10) return false;
				if(s2[2] != '?' && s2[2]!=q%10) return false;
		}
		if(ls==2 ){
				if(q>=100)return false;
				if(s2[0] != '?' && s2[1]!= q/10 )return false;
				if(s2[1] != '?' && s2[1]!=q%10 ) return false;
		}
		if(ls==1 ){
				if(q>=10)return false;
				if(s2[0] != '?' && s2[1]!= q )return false;
		}
	}
	return true;
}

int main(void) {
	//freopen("a.out", "w", stdout);
	//freopen("a.in", "r", stdin);

	scanf("%d", &cs);

	for (int T = 1; T <= cs; T++) {
		scanf("%s%s", s1, s2);
		int ans = 99999;
		int a1=0,a2=0;
		for (int i = 0; i <= 999; i++){
			if(can(1,i)){
				for(int j=0;j<=999;j++){
					if(can(2,j)){
						int ll= i-j;
						if(ll<0)ll=0-ll;
						if(ans>ll){
							ans = ll;
							a1=i,a2=j;
						}
					}
				}
			}
		}
		printf("Case #%d: %d %d\n", T, a1, a2);
	}

	return 0;
}
