#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <queue>

using namespace std;

	long long int parcour[120][120];
long long int drij (long long int matrice[120][120],int N,int M)
{
	for (int i = 0; i < N+1; i += 1)
	{
		for (int j = 0; j < M+1; j += 1)
		{
			parcour[i][j] = 0;
		}
	}
	for (int i = 1; i <= N; i += 1)
	{
		for (int j = 1; j < M+1; j += 1)
		{
			parcour[i][j] = max (parcour[i-1][j],parcour[i][j-1]) + matrice[i][j];
		}
	}
	return parcour[N][M];
}

int main (int argc, char const* argv[])
{
	int T;
	long long int matrice[120][120];
	long long int boite[120];
	int typeboite[120];
	int typejouet[120];
	long long int jouet[120];
	cin >> T;
	for (int cas = 0; cas < T; cas += 1)
	{
		int N,M;
		cin >> N;
		cin >> M;
		long long int temp;
		for (int i = 1; i <= N; i += 1)
		{
			cin >> boite[i];
			cin >> typeboite[i];
		}
		for (int j = 1; j <= M; j += 1)
		{
			cin >> jouet[j];
			cin >> typejouet[j];
		}
		for (int i = 1; i <= N+1; i += 1)
		{
			for (int j = 1; j <= M+1; j += 1)
			{
				matrice[i][j]=0;
			}
		}
		for (int i = 1; i < N+1; i += 1)
		{
			for (int j = 1; j < M+1; j += 1)
			{
					if (typeboite[i]==typejouet[j])
					{
						matrice[i][j] = min (jouet[j],boite[i]);
						jouet[j] -= matrice[i][j];
						boite[i] -= matrice[i][j];
					}
					else
					{
						matrice[i][j] = 0;
					}
			}
		}

		long long int resultat;
		resultat = drij(matrice,N,M);
		cout << "Case #" << cas +1 << ": " << resultat << endl;
	}
	return 0;
}
