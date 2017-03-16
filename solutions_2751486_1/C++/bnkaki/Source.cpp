#include <iostream>
#include <sstream>
#include <climits>
#include <cstddef>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;


int T,n;
string name;

int main()
{
	cin>>T;

	vector<char> vowel;
	vowel.push_back('a');vowel.push_back('e');vowel.push_back('i');vowel.push_back('o');vowel.push_back('u');

	for (int CASE = 1; CASE <= T; CASE++)
	{
		cin>>name>>n;
		ll ans=0;

		vector<int> consecutive;
		int counter=0;
		
		for (int i = 0; i < name.length(); i++)
		{
			bool flag=true;
			for (int j = 0; j < vowel.size(); j++)
			{
				if (name[i]==vowel[j]) flag=false;
			}
			if (flag) counter++;
			else counter=0;

			if (counter>=n) consecutive.push_back(i-(n-1));
		}

		for (int i = 0; i < name.length(); i++)
		{
			int place=lower_bound(consecutive.begin(),consecutive.end(),i)-consecutive.begin();
			if (place<consecutive.size()) ans+=name.length()-(consecutive[place]+n-1);
		}

		cout<<"Case #"<<CASE<<": "<<ans<<endl;
	}

	return 0;
}