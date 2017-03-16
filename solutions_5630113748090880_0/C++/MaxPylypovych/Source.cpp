#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ofstream output;
	ifstream input;
	input.open("input.txt");
	output.open("output.txt");

	//	FILE * input;
	//	input = fopen("input.txt","r");

	int T;

	//	fread(&n, sizeof(int), 1, input);cout<<n<<endl; char cc=getchar();

	input >> T;// cout<<n<<endl;
	//cin >> T;
	
	int n;

	int tmp;
	
	for (int t = 0; t < T; ++t)
	{
		input >> n;

		int* ent = new int[3000];
		for (int i = 0; i < 3000; ++i)
			ent[i] = 0;

		//vector<vector<int>> lists(2 * n - 1);
		for (int i = 0; i < 2 * n - 1; ++i)
		{
			//lists[i].resize(n);
			for (int j = 0; j < n; ++j)
			{
				//input >> lists[i][j];
				input >> tmp;
				ent[tmp]++;
			}
		}
				

		output << "Case #" << t + 1 << ": ";
		
		int count = 0;
		for (int i = 1; i < 3000 && count<n; ++i)
		{
			if (ent[i] % 2)
			{
				output << i << ' ';
				++count;
			}
		}

		output<< endl;

		//cout << ans;

	}
	//	fclose(input);
	input.close();
	output.close();
	//	system("pause");
	return 0;
}
