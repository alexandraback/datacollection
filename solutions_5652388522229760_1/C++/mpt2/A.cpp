#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <sstream>
#include <stack>
#include <queue>
#include <map>
#include <climits>
#include <cstdio>
#include <set>
#include <unordered_map>
#include <iomanip>
using namespace std;
#define db(a) (cout << (#a) << " = " << (a) << endl)
typedef long long ll;

bool A[16];

bool foo(ll r)
{	
	while(r != 0)
	{
		int d = r % 10;
		r /= 10;		
		A[d] = true;
	}
	int erg = 0;
	for(int i=0;i<10;i++) if(A[i]) erg++;
	if(erg >= 10) return true;
	return false;
}

int main()
{
  ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	for(int t=0;t<T;t++)
	{
		for(int i=0;i<16;i++) A[i] = false;
		ll N;
		cin>>N;
		ll r = N;
		if(r != 0)
		{
			while(!foo(r)) r += N;		
			cout << "Case #" << t+1 << ": " << r << "\n";
		}
		else cout << "Case #" << t+1 << ": INSOMNIA\n";
	}
  return 0;
}
