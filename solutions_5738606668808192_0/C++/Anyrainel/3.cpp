#include <iostream>
//#include <bitset>
using namespace std;

int T, N, nn, J;
int bitp[32];
void print(int x)
{
	cout << '1';
	for(int i = nn; i >= 0; i--) {
		cout <<( (x&bitp[i]) == 0? "00" : "11");
	}
	cout << '1';
}
// int count(int bits)
// {
// 	int cnt = 0;
// 	while(bits){
// 		cnt += bits & 1;
// 		bits >>= 1;
// 	}
// 	return cnt;
// }
int main()
{
	
	//int bits;
	string div=" 3 4 5 6 7 8 9 10 11";
	ios_base::sync_with_stdio(false);
	cin >> T >> N >> J;
	nn = (N - 2) / 2 - 1;
	bitp[0] = 1;
	for(int i = 1; i < 32; i++)
		bitp[i] = bitp[i-1] << 1;
	for(int kase = 1; kase <= T; kase++) {
		cout << "Case #" << kase <<":\n";
		//bits = 0;
		for(int i = 0; i < J; i++) {
			//while(count(i) % 2 == 1) bits++;
			print(i);
			cout << div << '\n';
			//bits += 3;
		}
	}
	return 0;
}