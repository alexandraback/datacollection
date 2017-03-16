#include <stdio.h>
#include <functional>
#include <bitset>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <string.h>
#include <numeric>
using namespace std;

 typedef vector<int> vi; 
 typedef vector<vi> vvi; 
 typedef pair<int,int> ii; 
 typedef long long ll;
 #define sz(a) int((a).size()) 
 #define pb push_back 
 #define all(c) (c).begin(),(c).end() 
 #define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
 #define present(c,x) ((c).find(x) != (c).end()) 
 #define cpresent(c,x) (find(all(c),x) != (c).end()) 

string word[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE'", "SIX", "SEVEN", "EIGHT", "NINE"};
char id[] = {'Z', 'O', 'W', 'H', 'F', 'V', 'X', 'S', 'G', 'I'};
int sorted[] = {0,2,8,6,7,5,3,4,1,9};

int countandremove (int num , map <char,int> &chars)
{
	int ret = chars[id[num]];
	
	for (int i=0 ; i < sz(word[num]) ; i++)
	{
		char c = word[num][i];
		chars[c] -= ret;
	}
	
	return ret;
}

bool checkempty (map <char,int> chars)
{
	for (char c='A' ; c <= 'Z' ; c++)
		if (chars[c] > 0) return 0;
	return 1;
}

int main ()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	
	int TC;
	cin >> TC;
	int CC = 1;
	while (TC--)
	{
		printf("Case #%d: ",CC++);
		
		string s;
		cin >> s;
		
		map <char,int> chars;
		for (int i=0 ; i<sz(s) ; i++)
			chars[s[i]]++;
		
		vi ret;
		for (int i=0 ; i<10 ; i++)
		{
			if (checkempty(chars)) break;
			int count = countandremove(sorted[i], chars);
			for (int j=0 ; j<count ; j++)
				ret.pb(sorted[i]);
		}
		
		sort(all(ret));
		
		for (int i=0 ; i<sz(ret) ; i++) cout << ret[i];
		cout << endl;
	}
	
}
