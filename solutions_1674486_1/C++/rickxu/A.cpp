#include <fstream>

using namespace std;

int main()
{
	ifstream in_file("inputA.txt");
	ofstream out_file("outputA.txt");
	int T;
	in_file >> T;

	for (int i=1; i<=T; i++)
	{
		char matrix[1000][1000] = {{0}};
		int N;
		in_file>>N;
		for (int j=0; j<N; j++)
		{
			int m;
			in_file>>m;
			for (int k=0; k<m; k++)
			{
				int x;
				in_file>>x;
				matrix[j][x-1] = 1;
			}
		}

		bool found = false;
		for (int j=0; j<N; j++)
		{
			for (int k=0; k<N; k++)
			{
				if (matrix[j][k] == 1)
				{
					for (int m=0; m<N; m++)
					{
						if (matrix[m][j] == 1)
						{
							if (matrix[m][k] == 1)
								found = true;
							else
								matrix[m][k] = 1;
						}
					}
				}
			}
		}

		out_file<<"Case #"<<i<<": "<<(found?"Yes":"No")<<endl;
	}

	in_file.close();
	out_file.close();
	return 0;
}
