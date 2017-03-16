#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <queue>
#include <cassert>
#include <cctype>
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main()
{
	//freopen("A-small-attempt0.in", "r", stdin);
	//freopen("A-small-attempt0.out", "w", stdout);
	int testcases;
	string s;
	string hash="yhesocvxduiglbkrztnwjpfmaq";
	cin>>testcases;
	getline(cin, s);
	for(int cases=1; cases<=testcases; cases++)
	{
	    getline(cin, s);
	    string res;
	    int l=s.length();
	    for(int i=0; i<l; i++)
	    {
	        if(s[i]==' ')res+=s[i];
	        else
	        {
	            int ind = s[i]-'a';
	        res += hash[ind];

	        }

	    }
	    cout<<"Case #"<<cases<<": "<<res<<endl;
	}
	return 0;
}

