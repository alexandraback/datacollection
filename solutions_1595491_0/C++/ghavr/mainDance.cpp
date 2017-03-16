#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<string> split(string sent)
{
	if(sent.size() < 1)
		return vector<string>();
	vector<string> answer;
//	answer.resize(3);
	
	int start = 0, end = 0;
	char delim = ' ';
	
	while( (end = sent.find(delim, start)) != string::npos)
	{
		answer.push_back(sent.substr(start, end-start));
		start = end + 1;
	}
	answer.push_back(sent.substr(start, sent.size()-start));
	return answer;
}

bool mysort(pair<int, int> p1, pair<int, int> p2)
{
	return (p1.second < p2.second);
}

int main()
{
	freopen("input.in", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	
	string wrkLine;
	
	int testNumb;
	getline(cin, wrkLine);
	testNumb = atof(wrkLine.c_str());
	
	for(int i = 0; i < testNumb; ++i)
	{
		int N;
		int s;
		int p;

		getline(cin, wrkLine);
		vector<string> splited = split(wrkLine);
		N = atof(splited[0].c_str());
		s = atof(splited[1].c_str());
		p = atof(splited[2].c_str());

		vector<int> sums;
		for(int i = 3; i < splited.size(); ++i)
			sums.push_back(atof(splited[i].c_str()));

		sort(sums.begin(), sums.end());

		int count = 0;
		int curInd;
		for(curInd = sums.size() - 1; curInd >= 0; --curInd, ++count)
		{
			if(sums[curInd] < 3 * p - 2)
				break;
		}

		int surpLeft = s;
		for(; surpLeft > 0 && curInd >= 0; --curInd, --surpLeft, ++count)
		{
			if( (sums[curInd] < 3 * p - 4) || (sums[curInd] < 2))
				break;
		}

		cout << "Case #" << i+1 << ": " << count << endl;
		
	}
	
	return 0;
}