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
#include <unordered_set>
#include <iomanip>
using namespace std;
#define db(a) (cout << (#a) << " = " << (a) << endl)
typedef long long ll;

int A[256];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin>>T;
  for(int tt=0;tt<T;tt++)
  {
  	string s;
		cin>>s;
		string erg;
		for(int i=0;i<256;i++) A[i] = 0;
		for(char c : s)
		{
			A[c]++;
		}
		while(A['Z'] > 0)
		{
			A['Z']--;
			A['E']--;
			A['R']--;
			A['O']--;
			erg.append(1,'0');
		}		
		while(A['W'] > 0)
		{
			A['T']--;
			A['W']--;
			A['O']--;
			erg.append(1,'2');
		}		
		while(A['U'] > 0)
		{
			A['F']--;
			A['O']--;
			A['U']--;
			A['R']--;
			erg.append(1,'4');
		}		
		while(A['F'] > 0)
		{
			A['F']--;
			A['I']--;
			A['V']--;
			A['E']--;
			erg.append(1,'5');
		}		
		while(A['X'] > 0)
		{
			A['S']--;
			A['I']--;
			A['X']--;
			erg.append(1,'6');
		}		
		while(A['V'] > 0)
		{
			A['S']--;
			A['E']--;
			A['V']--;
			A['E']--;
			A['N']--;
			erg.append(1,'7');
		}		
		while(A['G'] > 0)
		{
			A['E']--;
			A['I']--;
			A['G']--;
			A['H']--;
			A['T']--;
			erg.append(1,'8');
		}		
		while(A['I'] > 0)
		{
			A['N']--;
			A['I']--;
			A['N']--;
			A['E']--;
			erg.append(1,'9');
		}		
		while(A['H'] > 0)
		{
			A['T']--;
			A['H']--;
			A['R']--;
			A['E']--;
			A['E']--;
			erg.append(1,'3');
		}		
		while(A['O'] > 0)
		{
			A['O']--;
			A['N']--;
			A['E']--;
			erg.append(1,'1');
		}		
		
		
		sort(erg.begin(), erg.end());
		
		
		
		
		cout << "Case #" << tt+1 << ": " << erg << "\n";	
  }  
  
  return 0;
}

