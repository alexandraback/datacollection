#include <iostream>
#include <fstream>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <string>

#define MAX_N 10000000

using namespace std;

ifstream fin("D:\\Input.txt");
ofstream fout("D:\\Output.txt");

int T, K, L, S;
double answer;
string K_string, L_string;
int max_value, total;
string current_string;

void solve(int n)
{
	if(n == S)
	{
		int temp_total = 0;
		for(int i = 0; i < S; i++)
			if(current_string.substr(i, L) == L_string)
				temp_total++;
		max_value = max(max_value, temp_total);
		total += temp_total;
		return;
	}
	for(int i = 0; i < K; i++)
	{
		current_string += K_string[i];
		solve(n + 1);
		current_string.erase(current_string.end() - 1);
	}
}

int main(int argc, const char* argv[])
{
	fin >> T;
	fout.precision(7);
	fout << std::showpoint << std::fixed;
	for(int i = 0; i < T; i++)
	{
		K = L = S = answer = 0;
		max_value = total = 0;
		fin >> K >> L >> S >> K_string >> L_string;
		solve(0);
		answer = (double)max_value - (double)total / (pow((double)K, (double)S));
		fout << "Case #" << i + 1 << ": " << answer << "\n";
		cout << i + 1 << "\n";
	}
	return 0;
}