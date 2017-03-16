// CodeJam2015_1B.cpp : Defines the entry point for the console application.
//

#include "vector"
#include "string"
#include "set"
#include "map"
#include "sstream"
#include "algorithm"
#include "cmath"
#include "cassert"
#include "iostream"
#include "numeric"
#include "fstream"
#include "queue"
#include <functional>
#include  <climits>
#include <iomanip>

#ifdef __GNUC__
#include  <tr1/unordered_map>
#define unordered_map tr1::unordered_map
#else
#include <unordered_map>
#endif

using namespace std;

#define int64 long long
#define F(vec, index) for (int index = 0; index  < vec.size(); ++index)
#define F2(index, vec) for (int index = 0; index  < vec.size(); ++index)
#define F3(index, from, vec) for (int index = from + 1; index  < vec.size(); ++index)

string key;
string target;
int k,l,s;
double res;
int64 c;
int64 ideal;



void rec(string& curr)
{
	if (curr.size() == s)
	{
		assert(curr.size() == s);
		c++;
		int64 currRes = 0;
		//target = "ABA";
		//curr = "ABABA";
		int strPos = curr.find(target, 0);
		while (strPos != -1)
		{
			res++;
			currRes++;
			strPos = curr.find(target, strPos + 1);
		}
		ideal = max(currRes, ideal);
		return;
	}

	F2(i, key)
	{
		curr.push_back(key[i]);
		rec(curr);
		curr.pop_back();
	}
}


int main(int argc, char* argv[])
{
	int T; 
	fstream cin("input.txt");
	fstream cout("out.txt", fstream::out);
	cin >> T;
	

	for (int t = 0; t < T; ++t)
	{
		std::cout << t << endl;

		
		cin >> k >> l >> s;
	
		cin >> key;
		cin >> target;
		string curr = "";

		ideal = 0;
		
		res = 0;
		c = 0;
		rec(curr);

		res /= c; 
		//assert(ideal2 == ideal);
		cout <<  "Case #" << t + 1 << ": " << std::setprecision(10) << (ideal - res) << endl;
	}
	return 0;
}