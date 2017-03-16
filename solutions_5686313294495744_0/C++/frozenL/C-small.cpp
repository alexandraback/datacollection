#include <iostream>
using namespace std;

const int N = 20;
int main(){
	int t;
	cin >> t;
	string w[N][2];
	int n;
	for(int i = 0; i < t; i ++){
		cout << "Case #" << i + 1 << ": ";
		cin >> n;
		for(int i = 0; i < n; i ++)
			cin >> w[i][0] >> w[i][1];
		int r = 0;
		for(int i = 0; i < (1 << n); i ++){//1: fake
			int tmpCnt = 0;
			for(int j = 0; j < n; j ++){
				int binaryJ = 1 << (n - j - 1);
				bool f1 = 0, f2 = 0;
				if((i & binaryJ) == 0)
					continue;
				for(int k = 0; k < n; k ++){
					int binaryK = 1 << (n - k - 1);
					if((i & binaryK) > 0)//fake
						continue;
					if(w[j][0] == w[k][0])
						f1 = 1;
					if(w[j][1] == w[k][1])
						f2 = 1;
				}
				if(f1 && f2)
					tmpCnt ++;
				else{
					tmpCnt = 0;
					break;
				}
			}
			r = max(r, tmpCnt);
		}
		cout << r << endl;
	}
	return 0;
}

