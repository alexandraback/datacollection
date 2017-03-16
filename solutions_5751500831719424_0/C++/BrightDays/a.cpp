#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <math.h>
#include <utility>
#include <string>
#include <cstring>

using namespace std;

void print(int q, int ans)
{
	if (ans==-1)
	cout << "Case #" << q << ": " << "Fegla Won" << endl; else
	cout << "Case #" << q << ": " << ans << endl;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin >> t;
	for (int q = 1; q <= t; q++)
	{
		int temp;
		cin >> temp;
		string s1,s2;
		cin >> s1;
		cin >> s2;
		if (s1==s2) 
		{
			print(q,0);
			continue;
		}
		int i = 0;
		int ans=0;
		bool p =false;
		while (true)
		{
			if (i==s1.length() || i==s2.length())
				{
					if (s1.length()==s2.length())
					{
						p = true;
						break;
					}
					if (i==s1.length())
					{
						bool e= true;
						for(int j=s1.length();j<s2.length();j++)
							if (s2[j]==s1[i-1]) ans++; else
							{
								e = false;
								print(q,-1);
								break;
							}
							if (e)
							{
								p = true;
								break;
							} else
								break;
					} else
					{	
						bool e=true;
						for(int j=s2.length();j<s1.length();j++)
							if (s1[j]==s2[i-1]) ans++; else
							{
								e = false;
								print(q,-1);
								break;
							}
						if (e)
							{
								p = true;
								break;
							} else
								break;
					}
					
				}	
			if (s1[i]==s2[i])
			{
				i++;
				continue;
			}
			if (i==0)
			{
				print(q,-1);
				break;
			}
			if (s1[i]==s1[i-1])
			{
				s2=s2.substr(0,i) + s1[i] + s2.substr(i);
				ans++;
			} else
			if (s2[i]==s2[i-1])
			{
				s1=s1.substr(0,i) + s2[i] + s1.substr(i);
				ans++;
			} else				
			{
				print(q,-1);
				break;
			}
			
		}
		if (p) print(q,ans);
	}
	return 0;
}