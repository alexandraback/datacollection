#include <cstdio>
#include <list>

using namespace std;

int main()
{
char p[1001];
int T,t,r;
list<char> s;

	scanf("%d",&T);
	for (t = 0; t < T; t++)
	{
		s.clear();
		scanf("%s",p);

		s.push_front(p[0]);
		
		r = 1;		
		while (p[r])
		{
			if (*(s.begin()) <= p[r]) s.push_front(p[r]); else s.push_back(p[r]);
			r++;
		}
		
		printf("Case #%d: ",t+1);
		  for (list<char>::iterator it=s.begin(); it!=s.end(); ++it)
    		printf("%c",*it);
		printf("\n");

	}//t
	
	return 0;	
}
