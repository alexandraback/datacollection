#include <cstdio>
#include <string>

using namespace std;

string getBinaryNumStr(int num,int len){

	string ans = "";
	string base2str = "";
	while(num){
		if(num%2 == 0) base2str = "0" + base2str;
		else base2str = "1" + base2str;
		num = num/2;
	}

	int zeroCnt = len - 2*base2str.size();
	for(int i = 0 ; i < zeroCnt;i++){
		ans = ans + "0";
	}

	return base2str+ans+base2str;
}

long long getFactor(int base, int num){

	long long ans = 0;
	for(int i = 0; num >0 ; i++){
		int temp = 1;
		if(num%2 == 1){
			for(int j = 1; j <= i ; j++){
				temp = temp*base;
			}
			ans += temp;
		}
		num = num/2;
	}

	return ans;
}

int main(){

	int T;
	scanf("%d",&T);

	for(int test_case = 1 ;test_case <= T; test_case++){
		int N,J;
		scanf("%d %d",&N,&J);

		printf("Case #%d:\n",test_case);
		for(int i = 1 ; i <= J ; i++){
			int equation = 2*i+1;
			string numStr = getBinaryNumStr(equation,N);
			printf("%s",numStr.c_str());

			for(int i = 2 ; i <= 10 ; i++){
				printf(" %lld",getFactor(i,equation));
			}
			printf("\n");
		}

	}

	return 0;
}
