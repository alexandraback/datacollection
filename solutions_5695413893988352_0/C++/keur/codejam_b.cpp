#include <iostream>
#include <vector>
#include <set>
using namespace std;

__attribute__ ((const, hot)) bool cmp(string my_string, int index, int n){
	if (-1 == index) {return 0 == n;}
	char last_ = my_string[index];
	if ('?' != last_ ){
		return (last_-'0' == n%10)
		&&
		cmp(my_string, index-1, n/10);}
	return cmp(my_string, index-1, n/10);
	}

void print_digits(int number, int digits){
	if (digits > 2){
		cout << (number/100)%10;
		}
	if (digits > 1){
		cout << (number/10)%10;
	}
	if (digits > 0){
		cout << (number/1)%10;
	}
}

void foo(string S1, string S2){
	bool init = false;
	int best_value;
	int best_c;
	int best_j;
	for (int c = 0; c < 1000; c += 1){
		for (int j = 0; j < 1000; j += 1){
			bool _c = cmp(S1,S1.size()-1, c);
			bool _j = cmp(S2,S2.size()-1, j);
			int best = abs(c-j);
			if ( _c and _j ){
				if (not init){
					init = true;
					best_c = c;
					best_j = j;
					best_value = best;
				}
				if (best_value > best){
					best_c = c;
					best_j = j;
					best_value = best;
					}
			}
			}
		}
	print_digits(best_c, S1.size());
	cout << " ";
	print_digits(best_j, S2.size());
//	cout << best_c << " " << best_j ;
	}
int main(void){
	//for (int i = 0; i <= 1000; i += 1){cout << i << " " << cmp("?1?", 2, i) << endl;}
	int t;
	cin >> t;
	for (int i = 1; i <= t; i += 1){
		string S1, S2;
		cin >> S1 >> S2;
		cout << "Case #" << i << ": ";
		foo(S1, S2);
		cout << "\n";
	}
	return 0;
}
