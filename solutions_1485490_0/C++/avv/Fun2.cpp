#include "stdafx.h"
#include "stdafx.h"
#include "fstream"
#include "vector"
#include "algorithm"
#include "numeric"
#include "sstream"
#include "string"
#include "algorithm"
#include "unordered_map"
#include "unordered_set"
#include "cassert"
#include "iostream"

using namespace std;
using namespace tr1;



//#define long long long long


long long rec(vector<pair<long long, long long>> A, long long currA, vector<pair<long long, long long>> B,long long currB)
{

	if (A.size() <= currA || B.size() <= currB)
	{
		return 0;
	}
	long long result = 0;
	while (A[currA].second == B[currB].second)
	{
		if (A[currA].first > B[currB].first)
		{
			result += B[currB].first;
			A[currA].first -= B[currB].first;
			B[currB].first = 0;
			currB++;
		}
		else if  (A[currA].first < B[currB].first)
		{
			result += A[currA].first;
			B[currB].first -= A[currA].first;
			A[currA].first = 0;
			currA++;		 
		}
		else if  (A[currA].first == B[currB].first)
		{
			result += A[currA].first;
			B[currB].first = 0;
			A[currA].first = 0;
			currA++;
			currB++;	
		}

		if (A.size() <= currA || B.size() <= currB)
		{
			return result;
		}
	}

	long long resultRec1 = rec(A, currA + 1, B, currB + 0);
	long long resultRec2 = rec(A, currA + 0, B, currB + 1);
	//long long resultRec3 = rec(A, currA + 1, B, currB + 1);

	return result + max(resultRec1, resultRec2);

}

long long Run(fstream& f)
{
	long long aN, bN;
	f >> aN >> bN;

	//cout << aN << " "<< bN <<endl;

	vector<pair<long long, long long>> A(aN);
	vector<pair<long long, long long>> B(bN);

	for (long long i = 0; i < aN; ++i)
	{
		pair<long long , long long> v;
		f >> v.first;
		f >> v.second;

		A[i] = v;
	}
	for (long long i = 0; i < bN; ++i)
	{
		pair<long long, long long> v;
		f >> v.first;
		f >> v.second;
		
		B[i] = v;

	}

	long long result = rec(A, 0, B, 0);

	return result;
}

void main()
{


	fstream f("B.in");
	fstream r("result.txt");

	long long t;
	f >> t;

	for (long long j = 0; j < t; ++j)
	{
		auto result = Run(f);			
		r << "Case #" << j + 1 << ": " << result << endl;		
	}

	r.close();
	f.close();
	//return 0;
}
