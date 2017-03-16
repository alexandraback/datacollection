#include <fstream>
#include <string>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

char map1[] = {'y', 'n', 'f', 'i', 'c', 'w', 'l', 'b', 'k', 'u', 'o', 'm', 'x', 's', 'e', 'v', 'z', 'p', 'd', 'r', 'j', 'g', 't', 'h', 'a', 'q' };
char map[26];

void solve(string &inp)
{
	for (int i=0;i<26;++i)
	{
		map[map1[i]-'a']=i+'a';
	}
	for (unsigned i=0;i<inp.length();++i)
	{
		if (inp[i] >= 'a' && inp[i] <= 'z')
			fout << (char)(map[inp[i]-'a']);
		else
			fout << inp[i];
	}
}

int main()
{
	int T;
	fin >> T;
	string input;
	getline(fin,input);
	for (int i=0;i<T;++i)
	{
		getline(fin, input);
		fout << "Case #" << i+1 << ": ";
		solve(input);
		fout << endl;
	}
	return 0;
}