/*
*/

//#pragma comment(linker, "/STACK:16777216")
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

const int INF = 1e9;

const int N = 1000;

int tests;
int ts;
string st;
int cnt[1000];
vector<int> avec;
int found;
vector<string> words;
int have[1000][1000];

void rem(string st)
{
	for (int i = 0; i < st.size(); i++)
		cnt[st[i]]--;
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	freopen("F:/in.txt", "r", stdin);
	freopen("F:/out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> tests;
	for (; tests; --tests)
	{
		string st;
		cin >> st;
		++ts;
		for (int i = 'A'; i <= 'Z'; i++)
			cnt[i] = 0;

		for (int i = 0; i < st.size(); i++)
		{
			cnt[st[i]]++;
		}

		avec.clear();

		while (cnt['Z'])
		{
			avec.push_back(0);
			rem("ZERO");
		}

		while (cnt['W'])
		{
			avec.push_back(2);
			rem("TWO");
		}

		while (cnt['G'])
		{
			avec.push_back(8);
			rem("EIGHT");
		}

		while (cnt['X'])
		{
			avec.push_back(6);
			rem("SIX");
		}
		while (cnt['S'])
		{
			avec.push_back(7);
			rem("SEVEN");
		}
		while (cnt['V'])
		{
			avec.push_back(5);
			rem("FIVE");
		}

		while (cnt['U'])
		{
			avec.push_back(4);
			rem("FOUR");
		}

		while (cnt['O'])
		{
			avec.push_back(1);
			rem("ONE");
		}
		while (cnt['R'])
		{
			avec.push_back(3);
			rem("THREE");
		}
		while (cnt['N'])
		{
			avec.push_back(9);
			rem("NINE");
		}

		sort(avec.begin(), avec.end());
		cout << "Case #" << ts << ": ";
		for (int i = 0; i < avec.size(); i++)
			cout << avec[i];
		cout << endl;
		cerr << "Case #" << ts << ": ";
		for (int i = 0; i < avec.size(); i++)
			cerr << avec[i];
		cerr << endl;
	}

	cin.get(); cin.get();
	return 0;
}