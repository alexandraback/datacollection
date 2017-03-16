#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;

#define MAX 100O

int num_googlers;
int max_surp;
int p;

int run(int casen)
{
	cin >> num_googlers;
	cin >> max_surp;
	cin >> p;

	int num_noSurp = 0;
	int num_surp = 0;

	int limit_noSurp = 3*p - 2;
	int limit_surp = 3*p - 4;
	if (p == 1)
		limit_surp = 1;

	int score;
	for (int i=0;i<num_googlers;i++) 
	{
		cin >> score;
		if (score >= limit_noSurp) {num_noSurp++;continue;}
		if (score >= limit_surp) num_surp++;
	}

	cout << "Case #" << casen << ": " << num_noSurp + min(num_surp,
		max_surp) << endl;	
}

int main()
{
	int test_n;
	cin >> test_n;
	for (int i=1;i<=test_n;i++)
		run(i);
}
