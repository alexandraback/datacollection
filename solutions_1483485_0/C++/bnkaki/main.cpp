#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <functional>
#include <set>
#include <map>
#include <sstream>

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const char translate[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
int T;
string Googlerese;

int main()
{
	cin>>T;
	getline(cin,Googlerese);
	for (int t = 1; t <= T; t++)
	{
		getline(cin,Googlerese);

		string res;
		for (int i = 0; i < Googlerese.length(); i++)
		{
			if (Googlerese[i]==' ') res+=' ';
			else res+=translate[Googlerese[i]-'a'];
		}

		cout<<"Case #"<<t<<": "<<res<<endl;
	}

	return 0;
}