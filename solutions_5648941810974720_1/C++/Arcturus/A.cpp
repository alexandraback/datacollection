#include <stdio.h>
#include <string.h>

char str[2010];
int ctr[30];
int nums[11];

int main(){
	int jcase;
	
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	
	scanf("%d", &jcase);
	gets(str);
	
	for(int icase=0; icase<jcase; icase++){
		gets(str);
		memset(ctr, 0, sizeof(ctr));
		
		int len = strlen(str);
		for(int i=0; i<len; i++){
			ctr[str[i]-'A']++;
		}
		
		memset(nums, 0, sizeof(nums));
		nums[0] = ctr['Z'-'A'];
		ctr['R'-'A'] -= nums[0];
		ctr['O' - 'A'] -= nums[0];
		
		nums[2] = ctr['W'-'A'];
		ctr['O'-'A']-= nums[2];
		
		nums[4] = ctr['U'-'A'];
		ctr['F'-'A'] -= nums[4];
		ctr['O'-'A'] -= nums[4];
		ctr['R'-'A'] -= nums[4];
		
		nums[6] = ctr['X'-'A'];
		ctr['I'-'A'] -= nums[6];
		
		nums[3] = ctr['R'-'A'];
		
		nums[1] = ctr['O'-'A'];
		
		nums[5] = ctr['F'-'A'];
		ctr['I'-'A'] -= nums[5];
		ctr['V'-'A'] -= nums[5];
		
		nums[7] = ctr['V'-'A'];
		
		nums[8] = ctr['G'-'A'];
		ctr['I'-'A'] -= nums[8];
		
		nums[9] = ctr['I'-'A'];
		
		printf("Case #%d: ", icase+1);
		for(int i=0; i<=9; i++){
			for(int j=0; j<nums[i]; j++) printf("%d", i);
		}
		printf("\n");
	}
	
	return 0;
}

