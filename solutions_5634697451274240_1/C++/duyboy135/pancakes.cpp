#include<bits/stdc++.h>
#define M 100
using namespace std;
char s[M + 5];
int ans = 0;
main(){
	freopen("test.inp","r",stdin);
	freopen("test.out","w",stdout);
	int Tc;
	scanf("%d",&Tc);
	for(int test_num = 1 ; test_num <= Tc ; test_num++){
		int n , zero = 0;
		scanf("%s",s);
		n = strlen(s);
		for(int i = 0 ; i < n ; i++)	if(i == 0 || s[i] != s[i - 1]){
			if(s[i] == '-') zero++;
		}
		printf("Case #%d: %d\n",test_num,zero*2 - (s[0] == '-'));	
	}
}
