#include <cstdio>
#include <set>

using namespace std;

int main(){

	int T;
	scanf("%d",&T);

	for(int test_case = 1 ; test_case <= T ; test_case++){
		int digits[] = {0,1,2,3,	4,5,6,7,8,9};
		set<int> s(digits,digits+10);

		int N;
		scanf("%d",&N);

		int idx = 0;
		int num;
		if(N != 0){
			while(1){
				idx++;
				num = idx*N;

				int check = num;
				int digit;
				while(check){
					digit = check%10;
					check = check/10;
					s.erase(digit);
				}

				if(s.empty()){
					break;
				}
			}
			printf("Case #%d: %d\n",test_case,num);
		}
		else{
			printf("Case #%d: INSOMNIA\n",test_case);
		}
	}

	return 0;
}
