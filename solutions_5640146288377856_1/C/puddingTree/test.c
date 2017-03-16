#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
	int testcase;
	int test_num;
	int r, c, w;
	int i, j, k;
	int total=0;
	int second=0;
	scanf("%d", &test_num);
	for(testcase=1;testcase<=test_num;testcase++){
		total=0;
		second=0;
		scanf("%d %d %d", &r, &c, &w);
		
		
			
		total+=(c/w);
			
		
		
		total=total*(r-1);
		if(w==1)
			total+=c;
		else if(c==w) total+=w;
		else 
		{
			if (c%w==0)
				total+=(c/w+w-1);
			else total+=(c/w+w);
		}

		printf("Case #%d: %d\n", testcase, total);
	}
	return 0;
}