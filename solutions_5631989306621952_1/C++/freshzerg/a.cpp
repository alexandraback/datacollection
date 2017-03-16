#include <iostream>
#include <list>
using namespace std;
char inStr[10000];
int main()
{
	int T; cin >> T;
	for (int TT = 1; TT <= T; ++TT)
	{
		printf("Case #%d: ", TT);
		scanf("%s", inStr);
		list<char>ans;
		ans.push_back(inStr[0]);
		for (int i = 1; inStr[i]; ++i)
		{
			if(inStr[i] < ans.front())
			{
				ans.push_back(inStr[i]);
			} 
			else 
			{
				ans.push_front(inStr[i]);
			}
		}
		list<char>::iterator ptr;
		for(ptr = ans.begin(); ptr != ans.end(); ++ptr)
		{
			printf("%c",*ptr);
		}
		printf("\n");
	}
	return 0;
}