#include <stdio.h>
#include <iostream>
#include <string> 
#include <stdlib.h>
#include <cstring>
#include <math.h>
#include <vector>
using namespace std;

int T;
int K, C, S;

int main(void)
{
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		printf("Case #%d:", t);
		cin >> K >> C >> S;

		std::vector<long long int> v;
		
		if(K == 1){
			v.push_back(1);
		}
		else if(C == 1){
			if(S == K)
				for(int i = 1; i <= K; i++)
					v.push_back(i);
		}
		else if(S >= K - 1){
			for(int i = 2; i <= K; i++)
				v.push_back(i);
		}

		if(v.empty())
			cout << " IMPOSSIBLE\n";
		else{
			for(int i = 0; i < v.size(); i++)
				cout << " " << v[i];
			cout << endl;
		}

	}
}