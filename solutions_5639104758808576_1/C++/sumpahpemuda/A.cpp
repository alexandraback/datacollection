#include <stdio.h>

int main()
{
	int n, lebar, i, j;
	char formation[1005];
	
	scanf("%d", &n);

	for(int i=0; i<n; i++)
	{
		int temp = 0;
		int ans = 0;
		scanf("%d %s", &lebar, formation);
		for(j=1; j<=lebar; j++) {
			temp += formation[j-1] - '0';
			if(j > temp) {
				ans += j - temp;
				temp = j;
			}
		}
		printf("Case #%d: %d\n", i+1, ans);
	}

	return 0;
}