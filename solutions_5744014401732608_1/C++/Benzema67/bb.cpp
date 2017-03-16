#include<iostream>
#include <cstdio>
#include <cmath>
using namespace std;


int main(){
	freopen("B-large.in", "r", stdin);
	freopen("c.txt", "w", stdout);
	int T,B;
	long long M,dis,num;
	scanf("%d", &T);

	for (int round = 1; round <= T;round++){
		int mat[51][51] = { 0 };
		cin >> B >> M;
		for (int i = 1; i < 51; i++)
			for (int j = 1; j < 51; j++)
				if (i < j) mat[i][j] = 1;
		int max = pow(2, B-2);
		if (max < M){
			cout << "Case #" << round << ": IMPOSSIBLE" << endl;
			continue;
		}
		
		dis = max - M;
		for (int tmp = B - 1; tmp > 1; tmp--)
		{
			num = pow(2, tmp-2);
			if (num <= dis)
			{
				mat[tmp][B] = 0;
				dis = dis - num;
			}
		}
		cout << "Case #" << round << ": POSSIBLE" << endl;
		for (int i = 1; i <= B; i++)
		{
			for (int j = 1; j <= B; j++)
				printf("%d", mat[i][j]);
			printf("\n");
		}


	}

	return 0;

}