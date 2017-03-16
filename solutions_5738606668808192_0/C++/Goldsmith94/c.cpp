#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

#define ll long long int
#define endl '\n'

char ret[50];
char evens[7] = {'0', '0', '0', '0', '0', '1', '1'};
char odds[7] = {'0', '0', '0', '0', '0', '1', '1'};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, N, J;
	cin >> T >> N >> J;
	cout << "Case #1:\n";
	sort(evens, evens+7);
	sort(odds, odds+7);
	memset(ret, '0', sizeof(ret));
	ret[0] = '1';
	ret[N-1] = '1';
	ret[N] = '\0';
	int cnt = 0;
	do{
		do{
			for (int i = 0; i < 7; i++){
				ret[1+2*i] = evens[i];
				ret[2+2*i] = odds[i];
			}
			cout << ret << " 3 2 3 2 7 2 9 2 3\n";
			cnt += 1;
		}while(next_permutation(evens, evens+7) && cnt < 50);
	}while(next_permutation(odds, odds+7) && cnt < 50);
	return 0;
}