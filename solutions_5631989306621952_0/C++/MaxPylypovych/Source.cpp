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

	string s;

	int n;

	string ans;
	int len;
	for (int t = 0; t < T; ++t)
	{
		input >> s;

		len = s.length();
		/*vector<char> v(len);
		for (int i = 0; i < len; ++i)
		{
			v[i] = s[i];
		}
		sort(v.begin(), v.end());*/
		ans = "";
		for (int i = 0; i < len; ++i)
		{
			ans = max(ans + s[i], s[i] + ans);
		}

		output << "Case #" << t + 1 << ": " << ans << endl;
		
		//cout << ans;

	}
	//	fclose(input);
	input.close();
	output.close();
	//	system("pause");
	return 0;
}
