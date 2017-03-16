#include<cstdio>
#include<vector>
#include<map>
#include<math.h>
using namespace std;
char ch[1001];
char ans[2004];
int main()
{
int ntc; scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{
		printf("Case #%d: ",tc);
		scanf("%s",&ch);
		int s = 1000,e=1000;
		char sc,ec;
		ans[s] = ch[0]; ec = sc = ans[s];
		for(int i =1;ch[i]!='\0';i++)
		{
			char cc = ch[i];
			//printf("cc is %c sc = %c  ec = %c\n",cc,sc,ec);
			if(cc<sc)
			{
			//	printf("entered\n");
				e++;
				ans[e] =cc;
				ec = cc;
			}
			else
			{
				s--;
			    ans[s] = cc;
				sc = cc;	
			}
		}
		
	//	printf("s = %d and e= %d\n",s,e);
		for(int i=s;i<=e;i++) printf("%c",ans[i]);
		printf("\n");
	}	
}
