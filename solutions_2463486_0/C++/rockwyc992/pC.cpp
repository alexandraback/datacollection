/*************************************************************************
    > File Name: pC.cpp
    > Author: rockwyc992
    > Mail: rockwyc992@gmail.com 
    > Created Time: 2013年04月13日 (週六) 08時45分26秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

int T, a, b;
char ker[1100];
int ans;

int main()
{
	ker[1] = ker[4] = ker[9] = ker[121] = ker[484] = 1;

	scanf("%d", &T);
	for(int t=1 ; t<=T ; t++)
	{
		ans = 0;

		scanf("%d%d", &a, &b);
		
		for(int i=a ; i<=b ; i++)
			if(ker[i])
				ans++;
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}

