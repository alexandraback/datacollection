#include <stdio.h>
#include <string.h>


char str[2005];

int count[200];

int num[20];

int main()
{
	int cas;
	scanf("%d",&cas);
	for(int T=1; T<=cas; T++){
		scanf("%s",str);
		memset(count,0,sizeof(count));
		memset(num,0,sizeof(num));
		for(int i=0; str[i]; i++)
			count[str[i]]++;
		num[0]=count['Z'];
		count['E']-=count['Z'];
		count['R']-=count['Z'];
		count['O']-=count['Z'];
		count['Z']-=count['Z'];
		num[6]=count['X'];
		count['S']-=count['X'];
		count['I']-=count['X'];
		count['X']-=count['X'];
		num[8]=count['G'];
		count['E']-=count['G'];
		count['I']-=count['G'];
		count['H']-=count['G'];
		count['T']-=count['G'];
		count['G']-=count['G'];
		num[7]=count['S'];
		count['E']-=count['S'];
		count['V']-=count['S'];
		count['E']-=count['S'];
		count['N']-=count['S'];
		count['S']-=count['S'];
		num[5]=count['V'];
		count['F']-=count['V'];
		count['I']-=count['V'];
		count['E']-=count['V'];
		count['V']-=count['V'];
		num[4]=count['F'];
		count['O']-=count['F'];
		count['U']-=count['F'];
		count['R']-=count['F'];
		count['F']-=count['F'];
		num[9]=count['I'];
		count['E']-=count['I'];
		count['N']-=count['I'];
		count['N']-=count['I'];
		count['I']-=count['I'];
		num[3]=count['H'];
		count['E']-=count['H'];
		count['E']-=count['H'];
		count['T']-=count['H'];
		count['R']-=count['H'];
		count['H']-=count['H'];
		num[2]=count['T'];
		count['W']-=count['T'];
		count['O']-=count['T'];
		count['T']-=count['T'];
		num[1]=count['N'];
		count['O']-=count['N'];
		count['E']-=count['N'];
		count['N']-=count['N'];
		printf("Case #%d: ",T);
		for(int i=0; i<10; i++){
			while(num[i]--)
				printf("%d",i);
		}
		puts("");
	}
	return 0;
}
