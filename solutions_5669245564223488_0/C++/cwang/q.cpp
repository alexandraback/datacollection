#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <assert.h>
#include <time.h>

#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <set>
#include <bitset>
#include <exception>
#include <memory>
#include <numeric>
#include <limits>
#include <functional>
#include <stack>
#include <iterator>
#include <random>
#include <unordered_map>
#include <unordered_set>

#include <cctype>
#include <cstddef>
#include <cstring>
#include <ctime>

#define NOMINMAX
#include <windows.h>

#define	SAFE_DELETE(ptr) if(ptr){delete ptr; ptr=NULL;}
#define	SAFE_DELETE_ARRAY(ptr) if(ptr){delete [] ptr; ptr=NULL;}

using namespace std;

int glbtimes = 0;


void str_pattern( const string& si, string& Sip, vector<int>& Sinumber ) 
{
	char c = si[0];
	int num = 1;
	int i;
	for (i=1; i<si.size(); i++)
	{
		if (si[i] == c)
			num++;
		else
		{
			Sinumber.push_back(num);
			Sip += c;
			c = si[i];
			num = 1;
		}
	}

	Sinumber.push_back(num);
	Sip += c;
}

bool check(vector<string>& A)
{
	string aa;
	for (int i=0; i<A.size(); i++)
	{
		aa += A[i];
	}

	string pp;
	vector<int> nn;
	str_pattern(aa, pp, nn);
	
	vector<int> hashtable(26, 0);
	for (int i=0; i<pp.size(); i++)
	{
		hashtable[pp[i] - 'a']++;
	}

	for (int i=0; i<26; i++)
	{
		if (hashtable[i] > 1)
			return false;
	}

	return true;
}

void generate_permutation(vector<string>& A, int i)
{
	int n = A.size();
	if (i == n-1)
	{
		if ( check(A) )
			glbtimes++;
		
		return;
	}
	else
	{
		for (int k = i; k < n; ++k)
		{
			swap(A[k], A[i]);
			generate_permutation(A, i + 1);
			swap(A[k], A[i]);
		}
	}
}

int main()
{
	freopen("datain.txt", "r", stdin);
	freopen("dataout.txt", "w", stdout);

	int T; cin >> T;

	for (int i=0; i<T; i++)
	{
		glbtimes = 0;
		int N;
		cin >> N;
		
		vector<string> Allsets;
		string s;
		for (int k=0; k<N; k++)
		{
			cin >> s;
			Allsets.push_back(s);
		}

		generate_permutation(Allsets, 0);

		stringstream ss;
		ss << "Case #" << (i+1) << ": " << (glbtimes%1000000007) << endl;
		cout << ss.str();
	}

	fclose(stdout);
	fclose(stdin);
	return 1;
}