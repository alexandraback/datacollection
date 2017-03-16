#include<stdio.h>

int is_valid(char t_board[5][5],char p)
{
	int i,j,r=0,c1=0,c2=0,c3=0,c4=0,d1=0,d2=0;
	for(i=0;i<4;i++)
	{
		r=0;
		for(j=0;j<4;j++)
		{
			r += t_board[i][j];
			if(i==j)
				d1 += t_board[i][j];
			if((i+j)==3)
				d2 += t_board[i][j];
		}
		if((r==p*4) || r==(p*3+'T'))
			return 1;
		c1 += t_board[i][0]; 
		c2 += t_board[i][1]; 
		c3 += t_board[i][2]; 
		c4 += t_board[i][3]; 
	}
	if((c1==p*4) || c1==(p*3+'T'))
			return 1;
	if((c2==p*4) || c2==(p*3+'T'))
			return 1;
	if((c3==p*4) || c3==(p*3+'T'))
			return 1;
	if((c4==p*4) || c4==(p*3+'T'))
			return 1;
	if((d1==p*4) || d1==(p*3+'T'))
			return 1;
	if((d2==p*4) || d2==(p*3+'T'))
			return 1;		
	return 0;
}

int main()
{
	int t,i,j,k,d;
	char t_board[5][5];
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		d = 0;
		scanf("%s",t_board[0]);
		scanf("%s",t_board[1]);
		scanf("%s",t_board[2]);
		scanf("%s",t_board[3]);
		for(j=0;j<4;j++)
		{
			for(k=0;k<4;k++)	
				if(t_board[j][k]=='.')	
				{
					d=1;
					break;
				}
			if(d==1)
				break;
		}	
		if(is_valid(t_board,'X'))
			printf("Case #%d: X won\n",i);
		else if(is_valid(t_board,'O'))
			printf("Case #%d: O won\n",i);
		else if(d==1)
			printf("Case #%d: Game has not completed\n",i);
		else
			printf("Case #%d: Draw\n",i);		
		getchar();
	}
	return 0;
}
