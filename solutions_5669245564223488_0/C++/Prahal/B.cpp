#include <fstream>
#include <string>
#include <utility>
#include <algorithm>

#define MAX_N 10

using namespace std;

ifstream fin("D:\\Input.txt");
ofstream fout("D:\\Output.txt");

int T;

bool check_string(string s)
{
	int visited['z' + 10] = {0};
	visited[s[0]] = 1;
	for(int i = 1; i < s.length(); i++)
		if(visited[s[i]] && s[i - 1] != s[i])
			return false;
		else
			visited[s[i]] = 1;
	return true;
}

int main(int argc, const char* argv[])
{
	fin >> T;
	for(int i = 0; i < T; i++)
	{
		int N;
		long long answer = 0;
		string train = "";
		pair<string, int> strings[MAX_N];
		for(int j = 0; j < MAX_N; j++)
			strings[j] = pair<string, int>("", 0);

		fin >> N;
		for(int j = 0; j < N; j++)
			fin >> strings[j].first, strings[j].second = j + 1;
		for(int j = 0; j < N; j++)
		{
			if(check_string(strings[j].first))
			{
				string::iterator it = unique(strings[j].first.begin(), strings[j].first.end());
				strings[j].first.resize(distance(strings[j].first.begin(), it));
			}
			else
				goto end;
		}
		sort(strings, strings + N);

		do
		{
			for(int j = 0; j < N; j++)
				train += strings[j].first;
			if(check_string(train))
				answer = (answer + 1) % 1000000007;
			train = "";
		}
		while(next_permutation(strings, strings + N));
end:
		fout << "Case #" << i + 1 << ": " << answer << "\n";
	}
	return 0;
}