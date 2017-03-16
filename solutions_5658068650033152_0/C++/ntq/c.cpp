#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int main(int argc, char const *argv[])
{
	ull T;
	cin >> T;	

	for (int i = 0; i < T; ++i)
	{
		cout << "Case #" << i+1 << ": "; 

		int N,M,K;
		cin >> N >> M >> K;

		//first enclose optimally
		int k = 0;
		int n = 0;
		int m = 0;
		while(k+1<K){
			if((n<m || m+2<M) && n+2<N){
				n++;
			} else if(m+2<M){
				m++;
			} else { //cant enclose anymore
				break;
			}
			k = n*m + 2*(n+m);
		}
		int stones = 2*(n+m);
		if(k<K){
			stones += K-k;
		}

		cout << stones << endl;
	}

	return 0;
}