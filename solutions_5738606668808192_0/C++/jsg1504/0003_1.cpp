#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

string nextCandidate(string cand, int candLen){

	string ans = "";
	if(cand == ""){
		int len = candLen-2;
		while(len--){
			ans += '0';
		}
		return "1"+ans+"1";
	}
	if(candLen > 2){
		ans = cand.substr(1,candLen-2);
		int len = ans.size();
		bool isChg = false;
		for(int i = len-1; i >= 0 ; i--){
			if(ans[i] == '1'){
				ans[i] = '0';
			}
			else{
				ans[i] = '1';
				isChg = true;
				break;
			}
		}
		if(!isChg) return "";
	}

	return "1"+ans+"1";
}

long long pow(int n, int p){

	if(p == 0) return 1;
	else if(p == 1) return n;

	long long temp = pow(n,p/2);
	if(p%2 == 0){
		return temp*temp;
	}
	else{
		return temp*temp*n;
	}
}

long long chgBase(string s, int base){

	int len = s.size();

	long long num = 0;
	for(int i = 0 ; i < len ; i++){
		if(s[len-i-1] == '1') num += pow(base,i);
	}

	return num;
}

int main(){

	int T;
	scanf("%d",&T);

	for(int test_case = 1 ; test_case <= T; test_case++){
		int N,J;
		scanf("%d %d",&N,&J);

		printf("Case #%d:\n",test_case);

		int count = 0;
		string num = "";
		do{
			num = nextCandidate(num,N);

			bool success = true;
			long long divisor[11] = {0,};
			long long llNum;
			for(int i = 2 ; i <= 10 ; i++){
				llNum = chgBase(num,i);

				bool getDiv = true;
				for(long long j = 2 ; j*j <= llNum ; j++){
					if(llNum%j == 0){
						divisor[i] = j;
						getDiv = true;
						break;
					}
					getDiv = false;
				}
				if(!getDiv){
					success = false;
					break;
				}
			}

			if(success){
				printf("%s ",num.c_str());
				for(int i = 2 ; i <= 10 ; i++) printf("%lld ",divisor[i]);
				printf("\n");
				count++;
			}

			if(count >= J) break;

		}while(!num.empty());

	}

	return 0;
}
