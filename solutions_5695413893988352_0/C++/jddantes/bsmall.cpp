#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, ll> pl;

string A, B;
int N;

map<pl, int> memo;

#define INF (1<<28)

bool valid(string str, int num){
	// cout << "Comparing " << str << " vs " << num << endl;
	while(num){
		if(str.back() == '?'){
			num/=10;
			str.pop_back();
			continue;
		}

		// printf("%c vs %c\n", str.back(), (num%10)+'0');
		if(str.back() == (num % 10) + '0'){
			num/=10;
			str.pop_back();
			continue;
		} else {
			return false;
		}
		
	}
	return true;
}

bool check(int numA, int numB){
	string strA = A;
	string strB = B;
	int sz = N;
	while(sz--){
		int digA = numA % 10;
		int digB = numB % 10;

		if(strA.back() != '?'){
			if(strA.back() != digA + '0'){
				return false;
			}
		}

		if(strB.back() != '?'){
			if(strB.back() != digB + '0'){
				return false;
			}
		}

		strA.pop_back();
		strB.pop_back();
		numA/=10;
		numB/=10;
	}
	return true;

}

int main(){
	int cases;

	scanf("%d", &cases);

	for(int e = 0; e<cases; e++){
		cin >> A >> B;
		N = A.size();

		int a = INF;
		int b = INF;
		int score = INF;
		printf("Case #%d: ", e+1);
		if(N == 1){
			for(int i = 0; i<=9; i++){
				for(int j = 0; j<=9; j++){
					if(valid(A,i) && valid(B, j)){

						if(!check(i, j)){
							continue;
						}

						int diff = abs(i-j);
						if(diff < score){
							score = diff;
							a = i;
							b = j;
						} else if (diff == score){
							if(i < a){
								a = i;
							} else if (i == a){
								if(j < b){
									b = j;
								}
							}
						}
					}
				}
			}

			printf("%d %d\n",a,b);
		} else if (N == 2){

			for(int i = 0; i<=99; i++){
				for(int j = 0; j<=99; j++){
					if(valid(A,i) && valid(B, j)){


						if(!check(i, j)){
							continue;
						}

						int diff = abs(i-j);
						if(diff < score){
							score = diff;
							a = i;
							b = j;
						} else if (diff == score){
							if(i < a){
								a = i;
							} else if (i == a){
								if(j < b){
									b = j;
								}
							}
						}
					}
				}
			}

			printf("%02d %02d\n",a,b);


		} else if (N == 3){

			for(int i = 0; i<=999; i++){
				for(int j = 0; j<=999; j++){
					if(valid(A,i) && valid(B, j)){

						if(!check(i, j)){
							continue;
						}

						int diff = abs(i-j);
						if(diff < score){
							score = diff;
							a = i;
							b = j;
						} else if (diff == score){
							if(i < a){
								a = i;
							} else if (i == a){
								if(j < b){
									b = j;
								}
							}
						}
					}
				}
			}

			printf("%03d %03d\n",a,b);

		}


	}

	return 0;
}