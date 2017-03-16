#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

int ntest;
int A, B;
set<pair<int, int> > seen;

int main()
{
	scanf("%d", &ntest);
	for(int test = 1;test <= ntest;++test)
	{
		seen.clear();
		scanf("%d %d", &A, &B);
		for(int i = A;i <= B;++i)
		{
			char num[10];
			int numdigit;
			sprintf(num, "%d", i);
			numdigit = strlen(num);
			for(int j = 1;num[j];++j)
			{
				char mun[10];
				int mundigit = 0;
				for(int k = j;num[k];++k)
					mun[mundigit++] = num[k];
				for(int k = 0;k < j;++k)
					mun[mundigit++] = num[k];
				mun[mundigit] = '\0';
				if(mundigit == 0)
					continue;
				int ii;
				sscanf(mun, "%d", &ii);
				if(i != ii && ii >= A && ii <= B)
				{
					if(i > ii)
					{
						seen.insert(make_pair(ii, i));
					//	printf("%d %d\n", ii, i);
					}
					else
					{
						seen.insert(make_pair(i, ii));
					//	printf("%d %d\n", i, ii);
					}
				}
			}
		}
		printf("Case #%d: %d\n", test, seen.size());
	}
}
