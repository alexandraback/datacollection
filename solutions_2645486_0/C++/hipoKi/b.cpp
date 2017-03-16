#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int acts[10000];
int n, e, r;

int resolver(int eA, int posA)
{
	if(posA == n)
		return 0;
	int eN = eA;
	int parcial = resolver(min(eA+r,e), posA + 1);
	for(int i = 0; i < eN; i++)
	{
		parcial = max(parcial, resolver(min(eA-1-i+r, e), posA + 1) + acts[posA] * (1+i));
	}
	return parcial;
}

int main()
{
	//freopen("in.txt","r",stdin);
	freopen("b-s.in","r",stdin);
	freopen("b-s.out","w",stdout);
	
	int t;
	cin >> t;
	
	for(int s = 0; s < t; s++)
	{
		cin >> e >> r >> n;
		for(int i = 0; i < n; i++)
		{
			int act;
			cin >> act;
			acts[i] = act;
		}
	
		cout << "Case #" << s+1 << ": " << resolver(e, 0) << endl;
	}
	
	return 0;
	
}
