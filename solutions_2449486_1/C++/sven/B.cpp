#include <iostream>
#include <vector>

using namespace std;

bool solve(int T);

int main()
{
	int T;
	cin >> T;
	for(int i=0; i<T; i++)
		if(solve(i))
			cout << "YES\n";
		else
			cout << "NO\n";

}

bool solve(int T)
{
	cout << "Case #" << T+1 << ": ";
	int N, M;
	vector <vector <int> > A;
	cin >> N >> M;
	A.resize(N);
	for(int i=0; i<N; i++)
		A[i].resize(M);
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
		{
			int temp;
			cin >> temp;
			A[i][j] = temp;
		}

	int max = 1;
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			if(max < A[i][j])
				max = A[i][j];

	for(int height=1; height <=max; height++)
	{
		//cout << "Height : " << height << endl;
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<M; j++)
			{
				if(A[i][j] == height)
				{
					//cout << "CORD : \t" << i << "\t" << j << endl;
					bool flag1 = true, flag2 = true;
					for(int k=0; k<M; k++)
						if(A[i][k] > height)
							flag1 = false;
					if(flag1)
						for(int k=0; k<M; k++)
							A[i][k] = 0;

					flag2 = true;
					for(int k=0; k<N; k++)
						if(A[k][j] > height)
							flag2 = false;
					if(flag2)
						for(int k=0; k<N; k++)
							A[k][j] = 0;

					//cout << "FLAG : \t" << flag1 << "\t" << flag2 << endl;
					if(!flag1 && !flag2)
						return false;
				}
			}
		}
	}
	
	return true;
}






