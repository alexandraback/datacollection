#include<stdio.h>
#include<string.h>

int count[256];
int main(void)
{
	int pp,ppp,n,i,j,k;
	char a[2005];
	int ans[12];
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&ppp);
	for(pp=1;pp<=ppp;pp++)
	{
		scanf("%s",&a[1]);
		n=strlen(&a[1]);
		for(i=1;i<=n;i++)
			count[a[i]]++;
		
		ans[0]=count['Z'];
		count['Z']-=ans[0];
		count['E']-=ans[0];
		count['R']-=ans[0];
		count['O']-=ans[0];
		
		ans[6]=count['X'];
		count['S']-=ans[6];
		count['I']-=ans[6];
		count['X']-=ans[6];
		
		ans[2]=count['W'];
		count['T']-=ans[2];
		count['W']-=ans[2];
		count['O']-=ans[2];
		
		ans[8]=count['G'];
		count['E']-=ans[8];
		count['I']-=ans[8];
		count['G']-=ans[8];
		count['H']-=ans[8];
		count['T']-=ans[8];
		
		ans[3]=count['T'];
		count['T']-=ans[3];
		count['H']-=ans[3];
		count['R']-=ans[3];
		count['E']-=ans[3];
		count['E']-=ans[3];

		ans[7]=count['S'];
		count['S']-=ans[7];
		count['E']-=ans[7];
		count['V']-=ans[7];
		count['E']-=ans[7];
		count['N']-=ans[7];

		ans[4]=count['R'];
		count['F']-=ans[4];
		count['O']-=ans[4];
		count['U']-=ans[4];
		count['R']-=ans[4];

		ans[1]=count['O'];
		count['O']-=ans[1];
		count['N']-=ans[1];
		count['E']-=ans[1];
		
		ans[5]=count['F'];
		count['F']-=ans[5];
		count['I']-=ans[5];
		count['V']-=ans[5];
		count['E']-=ans[5];

		ans[9]=count['I'];
		count['N']-=ans[9];
		count['I']-=ans[9];
		count['N']-=ans[9];
		count['E']-=ans[9];

		printf("Case #%d: ",pp);
		for(i=0;i<=9;i++)
		{
			for(j=1;j<=ans[i];j++)
				printf("%d",i);
		}
		printf("\n");
	}
}
