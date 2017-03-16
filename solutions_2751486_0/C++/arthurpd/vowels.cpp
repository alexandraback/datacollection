#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool cons(char c)
{
	if(c == 'a'|| c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return false;
	return true;
}
int
main(void)
{
	int T,k, i, j, n, c;
	scanf("%d", &T);
	for(k = 0; k < T; k++)
	{
		string s;
		vector< pair<int,int> > inter;
		cin >> s;
		int ans = 0;
		scanf("%d", &n);
		for(i = 0, c = 0, j = 0; i < s.size(); i++)
		{
			if(cons(s[i]))
				c++;
			else
			{	c = 0; j = i+1; }
			if(c == n)
			{
//				printf("%d %d ", j, i);
				inter.push_back(pair<int,int> (j, i));
				j++;
				c--;
			}
		}
		for(i = (int) s.size() - 1, j = inter.size() - 1; i >= 0; i--)
		{
			while(j >= 0 && inter[j].first >= i)
				j--;
			if(j != inter.size() - 1)
{			j++;
			ans += s.size() - inter[j].second;}
		}
		printf("Case #%d: %d\n", k+1, ans);
	}
	return 0;
}
