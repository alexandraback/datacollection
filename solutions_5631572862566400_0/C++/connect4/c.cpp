#include <string.h>       
#include <vector>       
#include <set>       
#include <map>       
#include <algorithm>       
#include <math.h>       
#include <sstream>       
#include <ctype.h>       
#include <queue>       
#include <stack>       
#include <iostream> 
#include <gmp.h>	// if GMP is not allowed, I apologize
#include <fstream>
using namespace std;


int main(int argc, char** argv)
{

string fName = argv[1];
fstream In((fName+".in").c_str(), ios::in);
fstream Out((fName + ".out").c_str(), ios::out);

int tests;

In >> tests;


for(int h=0; h<tests; h++)
{
	int N;

	In >> N;

	vector<int> nextKid(N+1, 0);

	for(int i=1; i<=N; i++)
		In >> nextKid[i];

	vector<int> kidOrder(N);
	for(int i=0; i<N; i++)
		kidOrder[i] = i+1;
	int ret = 0;
	cout << "Case " << h+1 << endl;
	do
	{
		int i = 0;
		for(i=1; i<=kidOrder.size(); i++)
		{
			if(i==kidOrder.size() )
			{
				if(nextKid[kidOrder[0]]==kidOrder[1] || nextKid[kidOrder[0]] == kidOrder[kidOrder.size()-1])
					break;
				i = -5;
				break;

			}
			if(nextKid[kidOrder[i]]==kidOrder[i-1] || 
				(i+1 < kidOrder.size() && nextKid[kidOrder[i]]==kidOrder[i+1]))
				continue;
			if(nextKid[kidOrder[i]]!=kidOrder[0])
			{	i= -5; 
				break;
			}
			if(nextKid[kidOrder[0]]==kidOrder[1] || nextKid[kidOrder[0]]==kidOrder[i])
			{
				i++;
				break;
			}
			else
			{
				i= -5;
				break;
			}
		}
		if(i > ret)
		{
			for(int j=0; j<i; j++)
				cout << kidOrder[j] << " ";
			cout << endl;
		}
		ret = max(ret, i);

	}while(next_permutation(kidOrder.begin(), kidOrder.end() ));

	Out << "Case #" << h+1 << ": " << ret << endl;


}

In.close();

Out.close();

return 0;

}
 
