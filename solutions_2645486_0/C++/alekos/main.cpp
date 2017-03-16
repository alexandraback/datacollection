#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <iomanip>

using namespace std;

int TEST_CASES;

int E,R,N;
int value[10];
int res;

int calcola(int e, int l)
{
	if (l == N)
		return 0;
	int max = 0;
	if (e > E) e = E;
	for (int i = 0; i <= e; i++)
	{
		int s = i*value[l] + calcola(e - i + R, l+1);
		//cout << i << " - " << l << ")" << s << endl; 
		if (s > max)
			max = s;
	}
	//cout << "max " << max << endl;
	return max;
}
	
int main()
{
    cin >> TEST_CASES;
    for (int c = 0; c < TEST_CASES; c++)
    {
		cin >> E >> R >> N;
		for (int i = 0; i < N ; i++)
			cin >> value[i];
		res = calcola(E,0);
		cout << "Case #" << c+1 << ": "<< res << endl ;
    }
    return 0;
}
