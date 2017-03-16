#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<set>
using namespace std;

int main()
{
	int t;
	cin  >> t;
	for(int i=0;i<t;i++)
	{
		cout << "Case #" << i+1 << ": ";
		int n;
		cin >> n;
		string s[n];
		string n1;
		for(int j=0;j<n;j++)
		{
			cin >> n1;
			int r= n1.length();
			s[j] = "";
			s[j] = s[j]+n1[0];
			for(int k=0;k<r-1;k++)
			{
				if(n1[k] != n1[k+1])
					s[j] = s[j]+n1[k+1];
			}
		}
		set<char> set1;
		bool istrue = true;
		for(int j=0;j<n;j++)
		{
			int r = s[j].length();
			for(int k = 1;k<r-1;k++)
			{
				set1.insert(s[j][k]);	
			}
			for(int k=0;k<n;k++)
			{
			  if(k!=j)
			  {
			     r = s[k].length();
			     for(int p=0;p<r;p++)
			     {
				if(set1.count(s[k][p])>0)	
 				 {
				  istrue = false;
				  break;
				 }
    			     }
			  }
			  if(!istrue)
			    break;
			}
			set1.clear();
			if(!istrue)
				break;
		}
		if(!istrue)
		{
			cout << 0 << endl;
			continue;
		}
		int prem[n];
		for(int j=0;j<n;j++)
			prem[j] = j;
		int rp = 0,ans = 0,count = 0;
		do{
			count = 1;
			vector<int> a(26,0);
			char prev = 'Z';
			for(int j=0;j<n;j++)
			{
//			   cout << s[prem[j]];
			   for(int k=rp;k<s[prem[j]].length();k++)
			   {
				if(s[prem[j]][k] != prev)
				{
				    prev = s[prem[j]][k];
				    a[prev-'a']++;
				}
			   }
			}
			
			for(int j=0;j<26;j++)
			{
			   if(a[j] > 1)
			   {
				count = 0;
				break;
			   }
			}	
			ans += count;
//			cout << endl << count << endl;
			
		}while (next_permutation(prem,prem+n) );
		cout << ans << endl;
	}
	return 0;
}
