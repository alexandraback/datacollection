#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int t;
char str[200];
int main(int argc, char const *argv[])
{
	scanf("%d",&t);
	for (int TT=1;TT<=t;TT++){
		scanf("%s",str);
		int l=strlen(str);
		int cnt=0;
		for (int i=1;i<l;i++)
			if (str[i]!=str[i-1])
				cnt++;
		if (str[l-1]=='-') cnt++;
		printf("Case #%d: %d\n",TT,cnt );
	}
	return 0;
}