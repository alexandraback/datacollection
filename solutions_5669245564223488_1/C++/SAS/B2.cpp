#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
using namespace std;
char str[121][121];
int allCount[30];
int centerCount[30];
void reduceSize(char * a){
	char na[121];
	for(int i=0;i<121;i++)na[i] = 0;
	int idx=0;
	char pre = 0;
	for(int i=0;a[i] != '\0';i++){
		if(a[i] != pre)
		na[idx++] = a[i];
		pre = a[i];
	}
	for(int i=0;i <121;i++){
		a[i] = na[i];
	}

}
int edge[500][2];
long long int base = 1000000007;
long long int fac(int a){
	if(a == 0 || a == 1)return 1;
	long long int re = 1;
	for(int i=2;i<=a;i++){
		re *= i;
		re %= base;
	}
	return re;
}
int check(char * a){
	int len = strlen(a);
	int used[26];
	for(int i=0;i<26;i++)used[i] = 0;
	char pre = a[0];
	for(int i=0;i<len + 1;i++){
		if(a[i] == pre){
			continue;
		}
		if(a[i] != pre){
			if(used[pre - 'a'] != 0)return -1;
			used[pre - 'a'] ++;
		}
		pre = a[i];
	}
	return 1;
	
}
int main(){
	int T;
	scanf("%d",&T);
	int N;
	for(int ca = 1; ca <=T ;ca++){
		scanf("%d",&N);
		for(int i=0;i<30;i++)allCount[i] = centerCount[i] =0;
		bool failFlag = false;
		for(int i=0;i<N;i++){
			scanf("%s",str[i]);
			if(check(str[i]) == -1){
				failFlag = true;
			}
			reduceSize(str[i]);
			int len = strlen(str[i]);
			for(int j=0;j < len;j++){
				allCount[str[i][j] - 'a'] ++;
			}
			for(int j=1;j < len - 1;j++){
				centerCount[str[i][j] - 'a'] ++;
			}
		}
		printf("Case #%d: ",ca);
		if(failFlag){
			printf("0\n");
			continue;
		}
		fprintf(stderr, "Case #%d: ",ca);
		for(int i=0;i<N;i++){
			fprintf(stderr,"%s ",str[i]);
		}
		fprintf(stderr,"\n");
		for(int i=0;i<26;i++){
			if(allCount[i] == 0 || allCount[i] == 1)continue;
			if((centerCount[i] != 0 && allCount[i] != centerCount[i]) || centerCount[i] > 1){
				failFlag = true;
				break;
			}
		}
		if(failFlag){
			printf("0\n");
			continue;
		}
		int sn = 0;
		int beginCount[26], endCount[26];
		int equalCount[26];
		for(int i=0;i<26;i++)equalCount[i] = beginCount[i] = endCount[i] = 0;
		for(int i=0;i<500;i++)edge[i][0] = -1;
		for(int i=0;i<N;i++){
			int begin = str[i][0] - 'a';
			int end = str[i][strlen(str[i]) - 1] - 'a';
			if(begin == end){
				equalCount[begin]++;
			}else{
				edge[sn][0] = begin;
				edge[sn][1] = end;
				sn++;
			}
		}
		
		for(int i=0;i<26;i++)centerCount[i] = 0;
		while(1){
			bool breakFlag = false;
			for(int i=0;i<sn;i++){
				if(edge[i][0] == -1)continue;
				for(int j=0;j<sn;j++){
					if(edge[j][0] == -1)continue;
					if(i == j)continue;
					if(edge[i][1] == edge[j][0]){
						edge[sn][0] = edge[i][0];
						edge[sn][1] = edge[j][1];
						edge[i][0] = -1;
						edge[j][0] = -1;
						centerCount[edge[i][1]] ++;
						sn++;
						breakFlag = true;
						break;
					}
				}
				if(breakFlag)break;
			}
			if(!breakFlag)break;
		}
		int newSn = 0;
		for(int i=0;i<sn;i++){
			if(edge[i][0] == -1)continue;
				
			edge[newSn][0] = edge[i][0];
			edge[newSn][1] = edge[i][1];
			newSn++;
		}
		sn = newSn;
		for(int i=0;i<sn;i++){
			if(centerCount[edge[i][0]] != 0 || centerCount[edge[i][1]] != 0){
				failFlag = true;
				break;
			}
		}

		for(int i=0;i<sn;i++){
			beginCount[edge[i][0]] ++;
			endCount[edge[i][1]]++;
		}
		for(int i=0;i<26;i++){
			if(beginCount[i] >= 2 || endCount[i] >= 2 || (beginCount[i] > 0 && endCount[i] > 0)){
				failFlag = true;
				break;
			}
		}
		
		
		if(failFlag){
			printf("0\n");
			continue;
		}
		
		long long int ans = 1;
		int allp = sn;
		//fprintf(stderr, "sn = %d\n",sn);
		for(int i=0;i<26;i++){
			if(equalCount[i] == 0 || centerCount[i] != 0)continue;
			bool flag = false;
			for(int j=0;j<sn;j++){
				if(edge[j][0] == i || edge[j][1] == i){
					flag = true;
					break;
				}
			}
			if(!flag){
				//fprintf(stderr,"%c\n",i + 'a');
				allp++;
			}
		}
		//fprintf(stderr, "allp = %d\n",allp);
		ans *= fac(allp);
		ans %= base;
		for(int i=0;i<26;i++){
			ans *= fac(equalCount[i]);
			ans %= base;
		}
		printf("%lld\n", ans);
		
	}
	return 0;
}
