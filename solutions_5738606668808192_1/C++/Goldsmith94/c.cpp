#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

#define ll long long int
#define endl '\n'

char ret[50];
char evens[40];
char odds[40];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, N, J;
	cin >> T >> N >> J;
	cout << "Case #1:\n";
	memset(evens, '0', sizeof(evens));
	memset(odds, '0', sizeof(odds));
	evens[0] = evens[1] = odds[0] = odds[1] = '1';
	sort(evens, evens+(N-2)/2);
	sort(odds, odds+(N-2)/2);
	memset(ret, '0', sizeof(ret));
	ret[0] = '1';
	ret[N-1] = '1';
	ret[N] = '\0';
	int cnt = 0;
	do{
		do{
			for (int i = 0; i < (N-2)/2; i++){
				ret[1+2*i] = evens[i];
				ret[2+2*i] = odds[i];
			}
			cout << ret << " 3 2 3 2 7 2 9 2 3\n";
			cnt += 1;
		}while(next_permutation(evens, evens+(N-2)/2) && cnt < J);
	}while(next_permutation(odds, odds+(N-2)/2) && cnt < J);
	return 0;
}