#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char a[2000];
bool b[2000];
char ret[2000];

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("small.out","w",stdout);
	
	int task; scanf("%d", &task);
	for (int cs=1; cs<=task; cs++){
		scanf("%s", a);
		char z = a[0];
		int len = 0 ;
		for (int i=0; a[i]; i++){
			if (a[i]>=z){
				z = a[i];
				b[i] = true;
			}else{
				b[i] = false;
			}

			len++;
		}

		int s = 0, t = len-1;
		ret[t+1] = 0;
		for (int i=len-1; i>=0; i--){
			if (b[i]){
				ret[s++] = a[i];
			}else{
				ret[t--] = a[i];
			}
		}
		printf("Case #%d: %s\n", cs, ret);
	}	
	return 0;
}
