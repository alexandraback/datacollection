#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, ii, iii, j, t, n, k, c = 1, r, m, flag;
	int card[6], product[12];
	printf("Case #%d:\n", c++);
	scanf("%d", &t);
	scanf("%d%d%d%d", &r, &n, &m, &k);
	while(r--){
		for(i = 0;i < k;i++)
			scanf("%d", &product[i]);
		flag = 0;
		for(i = 2;i <= 5;i++){
			for(ii = 2;ii <= 5;ii++){
				for(iii = 2;iii <= 5;iii++){
					for(j = 0;j < k;j++){
						if(product[j] != 1 && i * ii * iii != product[j] && i * ii != product[j] && i * iii != product[j] && iii * ii != product[j]\
						 && i != product[j] && ii != product[j] && iii != product[j]){
							break;
						}
					}
					if(j == k){
						flag = 1;
						break;
					}
				}
				if(flag == 1)
					break;
				}
			if(flag == 1)
				break;
		}
		if(flag)
			printf("%d%d%d\n", i, ii, iii);
		else
			printf("222\n");
	}
	return 0;
}