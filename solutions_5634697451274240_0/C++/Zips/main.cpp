#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define max_S 103
using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	scanf("%d", &T);

	char S[max_S];
	int j;
	int ans;

	for(int i=0; i<T; i++){
		scanf("%s", S);

		j = 1;
		ans = 0;

		while(S[j]!='\0'){
				if(S[j]!=S[j-1]) ans++;
                j++;
		}

		if(S[0]=='-') ans=ans-(ans%2)+1;
		else ans=ans+1-((ans+1)%2);

		printf("Case #%d: %d\n", i+1, ans);
	}

	return 0;
}
