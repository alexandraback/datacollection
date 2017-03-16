#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i, j, k, n, c = 1, x, len, ans, count, flag, max;
	long long tt;
	int r, t;
	char input[200];
	scanf("%d", &t);
	while(t--){
		scanf("%s%d", input, &x);
		len = strlen(input);
		ans = 0;
		for(i = 0;i < len;i++){
			//printf("%d %d\n",i,len);
			for(k = i; k < len;k++){
				count = max = 0;
				flag = 0;
				for(j = i;j <= k;j++){
					if(input[j] != 'a' && input[j] != 'e' && input[j] != 'i' && input[j] != 'o' && input[j] != 'u'){
						if(flag)
							count++;
						else{
							flag = 1;
							count = 1;
						}
					}else
						flag = 0;
					if(count > max)
						max = count;
					//printf("%d\n", max);
				}
				if(max >= x)
					ans++;
			}
			
		}
		printf("Case #%d: %d\n", c++, ans);
	}
	return 0;
}