#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cstring>
using namespace std;

int con(char c){
	if ( c == 'a' || c == 'e' || c=='i' || c=='o' || c=='u' ) return false;
	return true;
}

int main()
{
	int t,caso=1;
	int n;
	char str[1009];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s %d",str,&n);
		int cont = 0;
		int ans = 0;
		int len = strlen(str);
		for(int i=0;i<len;i++){
			for(int j=i;j<len;j++)
			{
				cont = 0;
				for(int k=i;k<=j;k++){
					if ( con(str[k])){
						cont++;
					}else{
						cont = 0;
					}
					if ( cont >= n ){
						ans++;
						break;
					}
				}
			}
		}
		printf("Case #%d: %d\n",caso++,ans);
	}
	return 0;
}
