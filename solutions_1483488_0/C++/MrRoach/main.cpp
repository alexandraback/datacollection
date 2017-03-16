#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int pow10[] = {1,10,100,1000,10000,100000,1000000,10000000};

int T,A,B;
int d;
bool exist[2000000];
int list[10];

int main(){
	cin >> T;
	for (int times = 0; times < T; ++ times){
		memset(exist,false,sizeof(exist));
		memset(list,0,sizeof(list));
		cin >> A >> B;
		d = 0;
		int tmp = A;
		while (tmp != 0){
			++d;
			tmp /= 10;
		}
		int count = 0;
		for(int n = A; n <= B; ++ n){
			for (int k = 0; k < d-1; ++k){
				int big = n / pow10[k+1];
				int small = n % pow10[k+1];
				int newN = small * pow10[d-k-1] + big;
				if (newN < n && newN >= A && !exist[newN]) {
					++count;
					exist[newN] = true;
					list[k] = newN;
				}
			}
			for (int k = 0; k < d-1; ++k){
				exist[list[k]] = false;
				list[k] = 0;
			}
		}
		cout << "Case #" << (times + 1) << ": " << count << endl;
	}
	return 0;
}