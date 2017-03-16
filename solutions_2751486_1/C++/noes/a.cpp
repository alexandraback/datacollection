#include <cstdio>
#include <cstring>

int n, conso[1000010];
char data[1000010];

bool isVowel(char target) {

	return (target=='a' || target=='e' || target=='i' || target=='o' || target=='u');

}

int main() {

	scanf("%d", &n);
	for(int i=0; i<n; ++i) {

		scanf("%s", data);
		int len=strlen(data);
		int minConso;
		scanf("%d", &minConso);

		int consoInRow=0, idx=-1, preidx=0;
		long long int res=0;
		for(int j=0; j<len; ++j) {

			if(!isVowel(data[j])) {
				++consoInRow;
			} else {
				consoInRow=0;
			}

			if(consoInRow>=minConso) {
				idx=j;
				int stIdx=idx-minConso+1;
				long long int stChoose=stIdx-preidx+1, edChoose=len-idx;

				res+=stChoose*edChoose;
				preidx=stIdx+1;
			}

		}
		
		printf("Case #%d: %lld\n", i+1, res);


	}

	return 0;

}