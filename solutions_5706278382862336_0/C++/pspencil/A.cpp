#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>

using namespace std;




int main()
{
	int T;
	scanf("%d\n",&T);
	for(int i=0;i<T;i++)
	{
		printf("Case #%d: ",i+1);
		int a,b;
		scanf("%d/%d",&a,&b);
		int b1 = b;

		while(b1%2==0){
			b1/=2;
		}
		int n = 0;
		if(b1!=1){
			if(a%b1==0)
				{
					a/=b1;
					b/=b1;
				}
			else
			{
				printf("impossible\n");
				continue;
			}
		}
			while(a<b)
			{
				//printf("%d %d\n",a,b);

				a*=2;
				n+=1;
			}
		printf("%d\n",n);
		

	}
	return 0;
}