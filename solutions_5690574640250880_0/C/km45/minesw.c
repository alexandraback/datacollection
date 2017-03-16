#include<stdio.h>      
#include<stdlib.h>      
#include<math.h>  

int main() { 
	
	int T,i,j,k;
	scanf("%d",&T);
	
	for (i=1; i<=T; i++)
	{
		int R, C, M;
		scanf("%d", &R);
		scanf("%d", &C);
		scanf("%d", &M);
		
		char array[R+2][C+2];
		for (j=0;j<=R+1;j++)
			for (k=0;k<=C+1;k++)
				array[j][k]='.';
		
		int r=R, c=C;
		while (((M>=r)||(M>=c))&&(r>0)&&(c>0))	{	
			if (r>c){ 
				for (j=1;j<=c;j++)
					array[r][j]='*';

				M=M-c;
				r--;
			}
			else {
				for (j=1;j<=r;j++)
					array[j][c]='*';
		
				M=M-r;
				c--;		
			}
		}

		if ((r<c) && (M<r-1)) {
			for (j=r-M+1;j<=r;j++) 
				array[j][c]='*';
		}
		else if ((r>=c) && (M<c-1)) {
			for (j=c-M+1;j<=c;j++)
				array[r][j]='*';
		}
		else if ((M==r-1) && (M!=c-1)){
			for (j=c-M+1;j<=c;j++)
				array[r][j]='*';
		}
		else if ((M!=r-1) && (M==c-1)){
			for (j=r-M+1;j<=r;j++) 
				array[j][c]='*';
		}
		else {
			for (j=c-M+2;j<=c;j++) 
				array[r][j]='*';
			array[r-1][c]='*';
		}
		
		
		char copy[R+1][C+1];
		for (j=0;j<=R+1;j++)
			for (k=0;k<=C+1;k++)
				copy[j][k]=array[j][k];
		
		for (j=1;j<=R;j++)
			for (k=1;k<=C;k++)
				if (copy[j][k]=='.')
					if ((copy[j-1][k]!='*')&&(copy[j-1][k-1]!='*')&&(copy[j][k-1]!='*')&&(copy[j-1][k+1]!='*')&&(copy[j][k+1]!='*')&&(copy[j+1][k+1]!='*')&&(copy[j+1][k-1]!='*')&&(copy[j+1][k]!='*'))
						copy[j][k]='0';
					else copy[j][k]='1';
					
		int flag=0;
		for (j=1;j<=R;j++)
			for (k=1;k<=C;k++)
				if (copy[j][k]=='1')
					if ((copy[j-1][k]!='0')&&(copy[j-1][k-1]!='0')&&(copy[j][k-1]!='0')&&(copy[j-1][k+1]!='0')&&(copy[j][k+1]!='0')&&(copy[j+1][k+1]!='0')&&(copy[j+1][k-1]!='0')&&(copy[j+1][k]!='0'))
						flag=1;
					
		
		
		if (flag==0) array[1][1]='c';
		printf("Case #%d:\n",i);
		if (flag==1) 
			printf("Impossible\n");
		else {
			for (j=1;j<=R;j++){
				for (k=1;k<=C;k++)
					printf("%c",array[j][k]);
				printf("\n");
			}
			
		}
	}
	
	return 0;
}

