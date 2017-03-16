#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char name[1000006];

int vowelP[1000006];
int vowelS[1000006];
int vowelN;


int cCP[1000006];
int cCN[1000006];

int isVowel(char c){
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')return 1;
	return 0;
}
int main(){
	int T;
	int n;
	scanf("%d",&T);
	for(int ca = 0; ca < T; ca ++){
		scanf("%s %d",name, &n);
		int L = strlen(name);
		int vowelN = 0;
		for(int i=0;i<L;i++){
			if(isVowel(name[i])){
				vowelP[vowelN++] = i;
			}
		}
		int cCN = 0;
		int nowCon = 0;
		for(int i=0;i<L;i++){
			if(isVowel(name[i])){
				nowCon = 0;
				continue;
			}
			nowCon += 1;
			if(nowCon >= n){
				cCP[cCN ++] = i - n + 1;
			}
		}
		long long int ans = 0;
		int vowelInd = 0;
		int cCInd = 0;
		for(int i=0;i<L;i++){
			while(cCInd < cCN && cCP[cCInd] < i){
				cCInd++;
			}
			int reallyBegin = cCP[cCInd] + n;
			if(cCInd == cCN) reallyBegin = L;
			while(vowelInd < vowelN && vowelP[vowelInd] < reallyBegin){
				vowelInd++;
			}
			if(cCInd == cCN)break;
			int remainVowel = vowelN - vowelInd;
			int remainCon   = reallyBegin - remainVowel;
			ans += (L - reallyBegin + 1);
		}
		printf("Case #%d: %lld\n", ca + 1, ans);
	}
	return 0;
}
