#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int A[110][110];

void work(int casen)
{
	memset(A, 0, sizeof(A) );
	int n;
	scanf( "%d", &n );
	for (int i = 0; i < n; i++ )
	{
		int t, k;
		scanf( "%d", &t );
		for (int j = 0; j < t; j++ )
		{
			scanf( "%d", &k );
			A[i][k - 1] = 1;
		}
	}
	bool success = false;
	for (int k = 0; k < n; k++ )
		for (int i = 0; i < n; i++ )
			for (int j = 0; j < n; j++ )
				if (A[i][k] == 1 && A[k][j] == 1)
					if (A[i][j] == 0) A[i][j] = 1;
					else success = true;
	if ( success ) cout << "Case #" << casen << ": " << "Yes" << endl;
	else cout << "Case #" << casen << ": " << "No" << endl;
}

int main()
{
	freopen( "in.txt", "r", stdin );
	freopen( "out.txt", "w", stdout );
	int test_cases;
	scanf( "%d", &test_cases );
	for (int i = 0; i < test_cases; i++ )
		work(i + 1); 
} 