#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#include <stdio.h>

using namespace std;

int main()
{
	int tc;
	int count=1;
	cin>>tc;
	while (tc--)
	{
		int n;
		cin>>n;
		vector<pair<string, int> > v(n);
		for (int i=0;i<n;i++) 
		{
			string temp;
			cin>>temp;
			v[i] = make_pair(temp,i);
		}
		
		for (int i=0;i<v.size();i++)
		{
			string temp = v[i].first;
			string te = "";
			char cu = temp[0];
			te += cu;
			for (int j=1;j<temp.length();j++)
			{
				if (cu==temp[j]) continue;
				else
				{
					cu = temp[j];
					te+=cu;
				}
			}
			v[i].first = te;
		}
		
		long long ans = 0;
		do {
			int salah = 0;
			string s = "";
    		for (int i=0;i<v.size();i++)
    		{
    			s+=v[i].first;
    		}
    		int arr[30] = {0};
    		char cur = s[0];
    		arr[cur-'a'] = 1;
			for (int i=1;i<s.length();i++)
    		{
    			if (cur==s[i]) continue;
    			else
    			{
    				cur = s[i];
    				if (arr[cur-'a']==1)
					{
						salah = 1;
						break;
					} 
    				arr[cur - 'a'] = 1;
    			}
    		}
    		if (salah == 0) ans++;
    		
  		} while ( next_permutation(v.begin(),v.begin()+n) );
  		
  		ans = ans%1000000007;
  		
		cout<<"Case #"<<count++<<": "<<ans<<endl;
	}
	return 0;
}

