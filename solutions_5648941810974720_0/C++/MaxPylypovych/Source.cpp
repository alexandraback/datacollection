#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define EPS 0.0001
#define INF 1000000000



int gauss(vector < vector<double> > a, vector<double> & ans) {
	int n = (int)a.size();
	int m = (int)a[0].size() - 1;

	vector<int> where(m, -1);
	for (int col = 0, row = 0; col<m && row<n; ++col) {
		int sel = row;
		for (int i = row; i<n; ++i)
		if (abs(a[i][col]) > abs(a[sel][col]))
			sel = i;
		if (abs(a[sel][col]) < EPS)
			continue;
		for (int i = col; i <= m; ++i)
			swap(a[sel][i], a[row][i]);
		where[col] = row;

		for (int i = 0; i<n; ++i)
		if (i != row) {
			double c = a[i][col] / a[row][col];
			for (int j = col; j <= m; ++j)
				a[i][j] -= a[row][j] * c;
		}
		++row;
	}

	ans.assign(m, 0);
	for (int i = 0; i<m; ++i)
	if (where[i] != -1)
		ans[i] = a[where[i]][m] / a[where[i]][i];
	for (int i = 0; i<n; ++i) {
		double sum = 0;
		for (int j = 0; j<m; ++j)
			sum += ans[j] * a[i][j];
		if (abs(sum - a[i][m]) > EPS)
			return 0;
	}

	for (int i = 0; i<m; ++i)
	if (where[i] == -1)
		return INF;
	return 1;
}












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

	//string ans;
	int len;
	for (int t = 0; t < T; ++t)
	{
		input >> s;

		len = s.length();
		
		int nums[10] = { 0 };
		
		/*
		nums[0] = count(s.begin(), s.end(), 'Z');
		nums[2] = count(s.begin(), s.end(), 'W');
		nums[4] = count(s.begin(), s.end(), 'U');
		nums[6] = count(s.begin(), s.end(), 'X');
		nums[8] = count(s.begin(), s.end(), 'G');
		*/

		vector < vector<double> > a;
		vector<double> row;
		row.assign(11, 0);
		row[0] = 1;
		row[10] = count(s.begin(), s.end(), 'Z');

		a.push_back(row);


		int myints[] = { 1, 1, 0, 2, 0, 1, 0, 2, 1, 1, count(s.begin(), s.end(), 'E') };
		row.assign(myints, myints + 11);
		a.push_back(row);

		row.assign(11, 0);
		row[0] = 1; row[3] = 1; row[4] = 1;
		row[10] = count(s.begin(), s.end(), 'R');
		a.push_back(row);

		row.assign(11, 0);
		row[0] = 1; row[1] = 1; row[2] = 1; row[4] = 1;
		row[10] = count(s.begin(), s.end(), 'O');
		a.push_back(row);

		row.assign(11, 0);
		row[1] = 1; row[7] = 1; row[9] = 2;
		row[10] = count(s.begin(), s.end(), 'N');
		a.push_back(row);

		row.assign(11, 0);
		row[2] = 1; row[3] = 1; row[8] = 1;
		row[10] = count(s.begin(), s.end(), 'T');
		a.push_back(row);

		row.assign(11, 0);
		row[2] = 1;
		row[10] = count(s.begin(), s.end(), 'W');
		a.push_back(row);

		row.assign(11, 0);
		row[3] = 1; row[8] = 1;
		row[10] = count(s.begin(), s.end(), 'H');
		a.push_back(row);

		row.assign(11, 0);
		row[4] = 1; row[5] = 1;
		row[10] = count(s.begin(), s.end(), 'F');
		a.push_back(row);

		row.assign(11, 0);
		row[4] = 1;
		row[10] = count(s.begin(), s.end(), 'U');
		a.push_back(row);

		row.assign(11, 0);
		row[5] = 1; row[6] = 1; row[8] = 1; row[9] = 1;
		row[10] = count(s.begin(), s.end(), 'I');
		a.push_back(row);

		row.assign(11, 0);
		row[5] = 1; row[7] = 1;
		row[10] = count(s.begin(), s.end(), 'V');
		a.push_back(row);

		row.assign(11, 0);
		row[6] = 1; row[7] = 1;
		row[10] = count(s.begin(), s.end(), 'S');
		a.push_back(row);

		row.assign(11, 0);
		row[6] = 1;
		row[10] = count(s.begin(), s.end(), 'X');
		a.push_back(row);

		row.assign(11, 0);
		row[8] = 1;
		row[10] = count(s.begin(), s.end(), 'G');
		a.push_back(row);


		vector<double> ans;
		
		gauss(a, ans);
		/*for (int i = 0; i < 10; ++i)
		if (ans[i] < EPS)
			ans[i] = 0;*/

		output << "Case #" << t + 1 << ": ";
		
		for (int i = 0; i < 10;++i)
		for (int j = 0; j < (int)(round(ans[i])); ++j)
			output << i;
		
		output << endl;

		//cout << ans;

	}
	//	fclose(input);
	input.close();
	output.close();
	//	system("pause");
	return 0;
}
