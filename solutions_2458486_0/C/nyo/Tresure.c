#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define resultOK 1
#define resultNG 0

typedef struct {
	int flag; // open, close
	int type;
	int insideNum;
	int inside[401];
} chests_t;

int keys[201];
int keyNum;
int T,K,N;

chests_t chests[200];
int openSeq[200];
int openNum;

int main(void)
{
	int i,j,k; // for loop
	int result;

	scanf("%d",&T);

	for(i=0;i<T;i++){
		scanf("%d %d", &K, &N);
		memset(keys,0,sizeof(keys));
		memset(chests,0,sizeof(chests));
		memset(openSeq,0,sizeof(openSeq));
		keyNum=0;
		openNum=0;
		for(j=0;j<K;j++){
			int key;
			scanf("%d",&key);
			keys[key]++;
			keyNum++;
		}
		for(j=0;j<N;j++){
			scanf("%d %d",&chests[j].type, &chests[j].insideNum);
			for(k=0;k<chests[j].insideNum;k++){
				scanf("%d",&chests[j].inside[k]);
			}
		}

		openChest();
		printf("Case #%d:",i+1);
		if(openNum<N){
			printf(" IMPOSSIBLE\n");
		} else {
			for(j=0;j<openNum;j++){
				printf(" %d", openSeq[j]+1);
			}
			printf("\n");
		}
	}
}

int openChest()
{
	int i,j;
	int ret = resultOK;
	int result;

	for(i=0;i<N&&openNum<N;i++){
		// ƒJƒMƒ`ƒFƒbƒN
		if(keyNum == 0) {
			ret = resultNG;
			goto out_openChest;
		}
		if(chests[i].flag == 0 && keys[chests[i].type] > 0){
			// ‚Ü‚¾‚ ‚¯‚Ä‚È‚¢ & ƒJƒM‚ ‚è
			openSeq[openNum++]=i;
			chests[i].flag = 1;
			keys[chests[i].type] --; // ƒJƒMg‚¤
			keyNum--;
			for(j=0;j<chests[i].insideNum;j++){
				keys[chests[i].inside[j]]++; // ’†‚ÌƒJƒM‚ğè‚¿‚É’Ç‰Á
				keyNum++;
			}
			result = openChest(); // Ÿ‚ğ’T‚·
			if(result == resultNG){
				// ‘±‚©‚È‚¢‚Ì‚Å–ß‚·
				openNum--;
				chests[i].flag = 0;
				keys[chests[i].type] ++;
				keyNum++;
				for(j=0;j<chests[i].insideNum;j++){
					keys[chests[i].inside[j]]--;
					keyNum--;
				}
			}
		}
	}

out_openChest:
	return ret;
}
