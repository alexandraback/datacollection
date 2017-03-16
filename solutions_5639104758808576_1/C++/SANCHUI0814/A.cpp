#include<cstdio>

#define MAX_LEVEL 1024

class Audience
{
public:
	int Input()
	{
		scanf("%d %s", &smax, level_str);
		for(int i=0; i<=smax; i++)
			level[i] = level_str[i]-'0';
		return 0;
	}
	int getMinImplies()
	{
		invited = 0;
		getMin(0, 0);
		return invited;
	}
	
	int getMin(int k, int stand)
	{
		if(k > smax)
			return 0;
		
		//printf("invited:%d stand:%d k:%d\n", invited, stand, k);
		if(stand >= k || level[k] == 0)
		{
			stand += level[k];
			getMin(k+1, stand);
		}
		else
		{
			int persons = k - stand;
            invited += persons;
			getMin(k+1, stand+level[k]+persons);
		}
		
		return 0;
	}
private:
	char level_str[MAX_LEVEL];
	int level[MAX_LEVEL];
	int smax;
	int invited;
};

int main(int argc, char* argv[])
{
	Audience testObj;

	int T=0;
	scanf("%d", &T);
	
	for(int i=0; i<T; i++)
	{
		testObj.Input();
		printf("Case #%d: %d\n", i+1, testObj.getMinImplies());
	}
	return 0;
}
