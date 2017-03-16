#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int solve(string name, int n);
char vowels[] = {'a','e','i','o','u'};
bool is_cons(char ch);

int main()
{
    int T;
    cin >> T;
    for(int i=1; i<=T; ++i)
    {
	string str;
	int n;

	cin >> str >> n;

	cout << "Case #" << i << ": " << solve(str, n) << endl;
    }
    
    return 0;
}



int solve(string name, int n)
{
    int count = 0;

    vector<int> n_val(name.length());
    int cons_cons = 0;
    if(n == 1 && is_cons(name[0]))
    {
	n_val[0] = 1;
    }

    if(is_cons(name[0]))
    {
	cons_cons++;
    }


    for(int i=1; i<name.length(); ++i)
    {
	if(is_cons(name[i]))
	{
	    cons_cons++;
	    if(cons_cons >= n)
	    {
		n_val[i] = i - n + 2;
	    }
	    else
	    {
		n_val[i] = n_val[i-1];
	    }
	}
	else
	{
	    n_val[i] = n_val[i-1];
	    cons_cons = 0;
	}
    }

    int sum=0;
    for(int i=0; i<name.length();++i)
    {
	sum += n_val[i];
    }

    return sum;
}


bool is_cons(char ch)
{
    for(int i=0; i<5; ++i)
    {
	if(ch == vowels[i])
	    return false;
    }

    return true;
}
