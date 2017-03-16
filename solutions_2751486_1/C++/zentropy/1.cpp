#include <stdio.h>
#include <vector>
#include <string.h>
#include <assert.h>

using std::vector;

int main()
{
	static const size_t buff_size = 1000000;
	unsigned int nCases = 0;scanf("%d",&nCases);
	char* data = new char[buff_size+1];
	for(unsigned int iCases = 1;iCases <= nCases;++iCases)
	{
		memset(data,0,sizeof(char)*(buff_size+1));
		unsigned int n = 0;
		scanf("%s%d",data,&n);
		//if(67 == iCases)
		//{
		//	printf("%s %u\n",data,n);
		//}
		//else
		//{
		//	continue;
		//}
		size_t len = strlen(data);
		vector<size_t> counts(len,0);						// 到当前位置有多少个连续的辅音字母
		for(size_t i = 0;i < len;++i)
		{
			if(data[i] == 'a' || data[i] == 'e' || data[i] == 'i' || data[i] == 'o' || data[i] == 'u') continue;
			if(0 == i) counts[i] = 1;
			else counts[i] = counts[i-1] + 1;
		}
		//printf("len = %u\n",len);
		//for(size_t i = 0;i < len;++i) printf("%d ",counts[i]);
		//printf("\n");

#if 1
		vector<size_t> first(len,len);
		size_t p = 0;
		for(;p < len && counts[p] != n;++p);
		if(p != len) first[0] = p;

		for(size_t i = 1;i < len;++i)
		{
			size_t u = first[i-1];
			assert(u >= i - 1 && u <= len);
			if(i + n <= u + 1) first[i] = u;
			else
			{
				if(u == len) break;
				if(u + 1 == len) break;						// 到末尾
				if(counts[u+1] == counts[u]+1) first[i] = (u == len)?len:(u+1);
				else
				{
					size_t p = u + 1;
					for(;p < len && counts[p] != n;++p);
					if(p == len) break;
					first[i] = p;
				}
			}
			assert(first[i] >= i && first[i] <= len);
		}
#else
		vector<size_t> first(len,len);
		for(size_t i = 0;i < len;++i)
		{
			size_t p = i;
			for(int k = 0;p < len;++p)
			{
				if(counts[p] != 0) ++k;
				else k = 0;
				if(k == n) break;
			}
			if(p == len) break;
			first[i] = p;

		}
#endif
		//for(size_t i = 0;i < len;++i) printf("%d ",first[i]);
		//printf("\n");

		unsigned long long ans = 0;
		for(size_t i = 0;i < len;++i)
		{
			ans += len - first[i];
		}
		printf("Case #%u: %I64u\n",iCases,ans);
	}
	delete[] data;
	return 0;
}