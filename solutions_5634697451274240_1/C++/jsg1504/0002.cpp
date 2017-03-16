#include <cstdio>
#include <cstring>

using namespace std;

char S[101];

int main(){

	int T;
	scanf("%d",&T);

	for(int test_case = 1 ; test_case <= T ; test_case++){
		scanf("%s",S);

		int cnt = 0;
		bool plusState;
		if(S[0] == '-') plusState = false;
		else plusState = true;

		int len = strlen(S);
		for(int i = 1 ; i < len ; i++){
			if(S[i] == '-'){
				if(plusState){
					cnt++;
					plusState = false;
				}
			}
			else{
				if(!plusState){
					cnt++;
					plusState = true;
				}
			}
		}
		if(!plusState) cnt++;
		printf("Case #%d: %d\n",test_case,cnt);
		memset(S,0,sizeof(S));
	}

	return 0;
}
