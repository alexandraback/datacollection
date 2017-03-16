#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <stack>
#include <list>
#include <algorithm>
#include <string>
using namespace std;

int dfs(long long p, long long q, int k)
{
    if(k > 40) 
	return -1;
    if(p == q)
	return 0;
    if( p < q && q % 2 == 0)
    {
	int s = dfs(p, q/2, k+1);
	if(s == -1)
	    return -1;
	else
	    return dfs(p, q/2, k+1) + 1;
    }
    if( p > q && dfs(p-q, q, k+1) != -1)
	return 0;
    return -1;

}
int main()
{
    int num, n, l;
    ifstream fin;
    ofstream fout;
    string input;
    fin.open("elfsmall.in", std::ifstream::in);
    fout.open("elfsmall.out", std::ofstream::out);
    fin>>num;
    for(int i = 0; i < num; i++)
    {
	long long p, q;
	string input;
	fin>>input;
	p = input[0] - '0';
	int j = 1;
	while(input[j] != '/')
	{
	    p = p*10;
	    p += input[j] - '0';
	    j++;
	}
	j++;
	q = input[j++] - '0';
	while(j < input.size())
	{
	    q = q * 10;
	    q += input[j] - '0';
	    j++;
	}
	cout<<p<<' '<<q<<endl;
	int result = dfs(p, q, 0);
	if(result != -1)
	    fout<<"Case #"<<i+1<<": "<<result<<endl;
	else
	    fout<<"Case #"<<i+1<<": impossible"<<endl;
    }
    fin.close(); fout.close(); 
    return 0; 
}
