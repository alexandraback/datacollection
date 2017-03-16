#include <stdio.h>
int main()
{
	int c=1,t,R,C,M,temp,x,y,z,i,j,p,q,r,m;
	char ch[60][60];
	FILE *f1,*f2;
	f1=fopen("C-small-attempt1.in","r");
    f2=fopen("output3.txt","w");
    fscanf(f1,"%d",&t);
    getc(f1);
	while(c<=t)
	{
		fscanf(f1,"%d %d %d",&R,&C,&M);
		getc(f1);
        temp=R*C-M;

		if(temp==0)
		{
			fprintf(f2,"Case #%d:\nImpossible\n",c);
			c++;
			continue;
		}

		for (i = 1; i <= R ; ++i)
		{
			for (j = 1; j <= C ; ++j)
			{
				ch[i][j]='*';
			}
		}
		ch[1][1]='c';


		if(temp==1)
		{
			fprintf(f2,"Case #%d:\n",c);
			c++;
			for (i = 1; i <= R ; ++i)
			{
				for (j = 1; j <= C ; ++j)
				{
					fprintf(f2,"%c",ch[i][j]);
				}
				fprintf(f2,"\n");
			}
			continue;
		}


		if(R==1)
		{
			temp--;
			for (j = 2; temp ; ++j)
			{
				ch[1][j]='.';
				temp--;
			}	
		}
		else if(C==1)
		{
			temp--;
			for (i = 2; temp ; ++i)
			{
				ch[i][1]='.';
				temp--;
			}	
		}
		else if(R<=2 || C<=2)
		{
			if(temp==1)
			ch[1][1]='c';
			else if(temp%2!=0 || temp==2)
			{
				fprintf(f2,"Case #%d:\nImpossible\n",c);
				c++;
				continue;
			}
			else 
			{
				if(C==2){
				for (i = 1; i <= R ; ++i)
				{
					for (j = 1; j <= C ; ++j)
					{
   						ch[i][j]='.';
   						temp--;
   						if(temp==0)
   							break;
					}
					if(temp==0)
						break;
				}}
				else if(R==2)
				{
				for (i = 1; i <= C ; ++i)
				{
					for (j = 1; j <= R ; ++j)
					{
   						ch[j][i]='.';
   						temp--;
   						if(temp==0)
   							break;
					}
					if(temp==0)
						break;

				}}
				ch[1][1]='c';
			}
		}
		else
		{
			x=2*(R+C-2);
			ch[1][1]='c';
			if(temp==2 || temp==3 || temp==5 || temp==7) 
			{
				fprintf(f2,"Case #%d:\nImpossible\n",c);
				c++;
				continue;
			}
			ch[1][2]=ch[2][1]=ch[2][2]='.';
			if(temp<=x)
			{
				p=temp/2;
				p=p-2;
				q=p/2;
				i=j=3;
				m=q;
//				printf("%d %d %d\n",temp,p,q);
				while(i<=R && j<=C && m!=0)
				{
					ch[i][1]=ch[i][2]=ch[1][j]=ch[2][j]='.';
					i++;
					j++;
					m--;
				}
				while(m!=0 && i<=R)
				{
					ch[i][1]=ch[i][2]=ch[i+1][1]=ch[i+1][2]='.';
					i+=2;
					m--;
				}

				while(m!=0 && j<=C)
				{
					ch[1][j]=ch[2][j]=ch[1][j+1]=ch[2][j+1]='.';
					j+=2;
					m--;
				}

				if(p%2 && i<=R)
				{
					ch[i][1]=ch[i][2]='.';
					i+=1;
				}
				else if(p%2 && j<=C)
				{
					ch[1][j]=ch[2][j]='.';
					j+=1;
				}

				if(temp%2==1)
					ch[3][3]='.';
    			}
    			else
    			{
    				i=3;
    				j=3;
    				while(i<=R && j<=C)
    				{
    					ch[i][1]=ch[i][2]=ch[1][j]=ch[2][j]='.';
    					i++;
    					j++;
    				}
    			while(i<=R)
    			{
    				ch[i][1]=ch[i][2]='.';
    				i+=1;
    			}
    			while(j<=C)
    			{
    				ch[1][j]=ch[2][j]='.';
    				j+=1;
    			}
    			temp-=x;
    			for (i = 3; i <= R ; ++i)
    			{
    				for (j = 3; j <= C ; ++j)
    				{
    					ch[i][j]='.';
    					temp--;
    					if(temp==0)
    						break;
    				}
    				if(temp==0)
    					break;
    			}
    
    		}
    	}
		fprintf(f2,"Case #%d:\n",c);
		c++;
		for (i = 1; i <= R ; ++i)
		{
			for (j = 1; j <= C ; ++j)
			{
				fprintf(f2,"%c",ch[i][j]);
			}
			fprintf(f2,"\n");
		}

	}
	return 0;
}
