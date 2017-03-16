#include <stdio.h>
#include <string.h>

int main()
{
	static const size_t charset_size = 26;
	static const char econvert[charset_size] = { 'y','n','f','i','c','w','l','b','k','u','o','m','x','s','e','v','z','p','d','r','j','g','t','h','a','q' };
	static const char dconvert[charset_size] = { 'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q' };

	static const size_t buff_size = 0x100;
	char buff[buff_size] = { 0 };
	int nCases = 0;scanf("%d",&nCases);gets(buff);
	for(int iCases = 1;iCases <= nCases;++iCases)
	{
		gets(buff);
		size_t len = strlen(buff);
		for(size_t i = 0;i < len;++i)
		{
			char c = buff[i];
			if(c < 'a' || c > 'z') continue;
			buff[i] = dconvert[c-'a'];
		}
		printf("Case #%u: %s\n",iCases,buff);
	}

	return 0;
}