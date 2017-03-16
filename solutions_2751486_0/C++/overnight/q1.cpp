#include "stdio.h"
#include "iostream"
#include "algorithm"
#include "vector"
#include "string"
#include "math.h"
bool isconstant(char a)
{
	if(a=='a'||a=='o'||a=='i'||a=='e'||a=='u')
		return false;
	return true;
}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	int cas=0;
	while(cas++<t)
	{
		std::string a;
		long long int b;
		std::cin>>a>>b;
		long long int count=0;
		long long int sum=0;
		long long int prevstart=-1;
		for (long long int i = 0; i < a.length(); ++i)
		{
			int flag=0;
			for (long long int j = i; j < i+b&&j<a.length(); ++j)
			{
				if(isconstant(a[j])) {flag++;}
			}
			if(flag>=b)
			{
				 sum += ((long long)(i) - prevstart)*(a.length()-(long long)(i+b-1));
				 prevstart=i;
			}
		}
		printf("Case #%d: %lld\n",cas,sum );
	}
	return 0;
}