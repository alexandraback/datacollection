#include <stdio.h>
#include <map>

std::map<long long, long long> m, m2;
int t, n;
long long s[500];

int jump(long long v)
{
	if (!v) return 0;
	if (jump(v-m2[v])) printf(" ");
	printf("%lld", m2[v]);
	return 1;
}

int main()
{
	scanf(" %d", &t);
	for(int cs=1; cs<=t; cs++)
	{
		scanf(" %d", &n);
		for(int i=0; i<n; i++) scanf(" %lld", s+i);
		printf("Case #%d:\n", cs);
		m.clear(); m[0]=0;
		for(int i=0; i<n; i++)
		{
			m2=m;
			std::map<long long, long long>::iterator it=m2.begin();
			while(it!=m2.end())
			{
				if (m2.find((*it).first+s[i])!=m2.end())
				{
					jump((*it).first+s[i]); printf("\n");
					if (jump((*it).first)) printf(" ");
					printf("%lld\n", s[i]);
					goto weiter;
				}
				m[(*it).first+s[i]]=s[i];
				it++;
			}
		}
		printf("Impossible\n");
	weiter:;
	}
	return 0;
}
