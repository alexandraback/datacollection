#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	int n, a, b, c;
	bool ans;
	
	scanf("%d", &n);

	for(int i=0; i<n; i++)
	{
		scanf("%d %d %d\n", &a, &b, &c);

		ans = true;

	    if (a >= 7)
	        ans = false;
	    else if (a > b && a > c)
	        ans = false;
	    else if (b * c % a != 0)
	        ans = false;
	    else if (int((a + 1) / 2) > min(b, c))
	        ans = false;
	    else if (a==1 || a==2 || a==3)
	        ans = true;
	    else if (a == 4)
	        ans = min(b, c) > 2;
	    else if (a == 5)
	        ans = !(min(b, c) == 3 && max(b, c) == 5);
	    else if (a == 6)
	        ans = min(b, c) > 3;
	
		if(ans)
			printf("Case #%d: GABRIEL\n", i+1);
		else
			printf("Case #%d: RICHARD\n", i+1);
	}

	return 0;
}