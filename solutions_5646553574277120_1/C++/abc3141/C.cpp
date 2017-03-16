#include<iostream>
#include<fstream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int ll;
ll T;
ll C, D, V;
ll P[100];
int main()
{
	ifstream fin("C:/Users/Toshifumi/C-large.in");
	ofstream fout("C:/Users/Toshifumi/out.txt");
	fin >> T;
	for (int Case = 1; Case <= T; Case++){
		fin >> C >> D >> V;
		for (int i = 0; i < D; i++)fin >> P[i];
		int ans = 0;
		if (P[0] != 1){
			ans++;
		}
		ll K = C;
		int now;
		if (P[0] == 1)now = 1;
		else now = 0;
		while (K < V){
			if (now == D){
				ans++;
				K += (K + 1)*C;
			}
			else{
				if (K+1 >= P[now]){
					K += P[now] * C;
					now++;
				}
				else{
					K += (K + 1)*C;
					ans++;
				}
			}
			
		}
		

		fout << "Case #" << Case << ": " << ans << "\n";
	}
	return 0;
}