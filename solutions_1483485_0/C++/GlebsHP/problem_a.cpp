#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const int size = 200;

string fn[size], st[size];
char way[size];
char buf[size];
bool used[size];
char mute[size];

int main() {
	freopen("problem_a.in", "r", stdin);
	freopen("problem_a.out", "w", stdout);
	/*
	int n = 3;
	for (int i = 0; i < n; i++)
	{
		fgets(buf, size, stdin);
		st[i] = string(buf);;
	}
	for (int i = 0; i < n; i++)
	{
		fgets(buf, size, stdin);
		fn[i] = string(buf);
	}
	for (int i = 0; i < size; i++)
		way[i] = 32;
	for (int i = 0; i < n; i++)
	{
		assert(st[i].length() == fn[i].length());
		for (int j = 0; j < st[i].length(); j++)
		{
			assert(way[st[i][j]] == 32 || way[st[i][j]] == fn[i][j]);
			assert(st[i][j] == ' ' ^ fn[i][j] == ' ' ^ 1);
			way[st[i][j]] = fn[i][j];
		}
	}
	for (int i = 0; i < 26; i++)
		used[way['a' + i]] = true;
	for (int i = 0; i < 26; i++)
		if (!used['a' + i])
			for (int j = 0; j < 26; j++)
				if (way['a' + j] == 32)
				{
					way['a' + j] = 'a' + i;
					used['a' + i] = true;
					break;
				}
	
	for (int i = 0; i < 26; i++)
		cout << "mute[" << int('a' + i) << "] = " << way['a' + i] << ";" << endl;
	*/
		mute[97] = 'y';
	mute[98] = 'h';
	mute[99] = 'e';
	mute[100] = 's';
	mute[101] = 'o';
	mute[102] = 'c';
	mute[103] = 'v';
	mute[104] = 'x';
	mute[105] = 'd';
	mute[106] = 'u';
	mute[107] = 'i';
	mute[108] = 'g';
	mute[109] = 'l';
	mute[110] = 'b';
	mute[111] = 'k';
	mute[112] = 'r';
	mute[113] = 'z';
	mute[114] = 't';
	mute[115] = 'n';
	mute[116] = 'w';
	mute[117] = 'j';
	mute[118] = 'p';
	mute[119] = 'f';
	mute[120] = 'm';
	mute[121] = 'a';
	mute[122] = 'q';
	 
	int n;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		fgets(buf, size, stdin);
		cout << "Case #" << i + 1 << ": ";
		for (int j = 0; j < strlen(buf); j++)
		{
			if (buf[j] != '\n' && buf[j] != ' ')
				cout << mute[buf[j]];
			if (buf[j] == ' ')
				cout << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}