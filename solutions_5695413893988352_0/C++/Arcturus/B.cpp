#include <stdio.h>
#include <string.h>

char str1[5], str2[5];
int len1, len2;
int now1, now2;

int mindif, minA, minB;

void Do(int id){
	if(id < len1){
		int now = now1;
		if(str1[id] == '?'){
			for(int i=0; i<=9; i++){
				now1 = now*10 + i;
				if(id+1 == len1) now2 = 0;
				Do(id+1);
			}
		}else{
			int a = str1[id]-'0';
			now1 = now*10 + a;
			if(id+1 == len1) now2 = 0;
			Do(id+1);
		}
		return;
	}
	id -= len1;
	
	if(id < len2){
		int now = now2;
		if(str2[id] == '?'){
			for(int i=0; i<=9; i++){
				now2 = now*10 + i;
				Do(id+len1+1);
			}
		}else{
			int a = str2[id]-'0';
			now2 = now*10 + a;
			Do(id+len1+1);
		}
		return;
	}
	
	//time to count
	//printf("cnt %d %d\n", now1, now2);
	int diff = now1 - now2;
	if(diff < 0) diff = -diff;
	
	if((diff < mindif) || ((diff == mindif)&&(now1 < minA)) || ((diff == mindif)&&(now1 == minA)&&(now2 < minB))){
		mindif = diff;
		minA = now1;
		minB = now2;
	}
}

int main(){
	int jcase;
	
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	
	scanf("%d", &jcase);
	for(int icase=0; icase<jcase; icase++){
		scanf("%s %s", str1, str2);
		len1 = strlen(str1);
		len2 = strlen(str2);
		
		mindif = 1000;
		minA = minB = 1000;
		
		now1 = now2 = 0;
		Do(0);
		
		printf("Case #%d: ", icase+1);
		if(len1 == 1) printf("%01d ", minA);
		else if(len1 == 2) printf("%02d ", minA);
		else if(len1 == 3) printf("%03d ", minA);
		if(len2 == 1) printf("%01d\n", minB);
		else if(len2 == 2) printf("%02d\n", minB);
		else if(len2 == 3) printf("%03d\n", minB);
	}
	
	return 0;
}
