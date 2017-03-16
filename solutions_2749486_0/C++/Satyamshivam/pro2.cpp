#include <stdio.h>
int main()
{
	freopen("input.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int T, x, y, i, j, xpos, ypos, distx, disty, n;
	scanf("%d", &T);
	for(i=1; i<=T; i++)
	{
		scanf("%d%d", &x, &y);
		printf("Case #%d: ", i);
		xpos = 0; ypos = 0; distx = 0; disty = 0; n = 1;
		
		
	if(x<=y)
	{
		//printf("AREA x<y \n ");
		if(x>=0)
		{
			//printf("AREA x>=0\n");
			while(xpos<x)
			{
				//printf("xpos = %d   ypos =%d\n", xpos, ypos);
				xpos = xpos + n;
				printf("E");
				n++;
			}
			
			distx = xpos-x;
			//printf("distx = %d\n", distx);
			for(j=1; j<=distx; j++)
			{
				printf("EW");
				n=n+2;
			}
		}
		
		else
		{
			//printf("AREA x<0\n");
			while(xpos>x)
			{
				xpos = xpos - n;
				printf("W");
				n++;
			}
			
			distx = x-xpos;
			for(j=1; j<=distx; j++)
			{
				printf("WE");
				n=n+2;
			}
		}
		
		//for y
		if(y>=0)
		{
			//printf("AREA y>=0\n");
			while(ypos<y)
			{
				//printf("xpos = %d   ypos =%d\n", xpos, ypos);
				ypos = ypos + n;
				printf("N");
				n++;
			}
			
			disty = ypos-y;
			for(j=1; j<=disty; j++)
			{
				printf("NS");
				n=n+2;
			}
		}
		
		else
		{
			while(ypos>y)
			{
				ypos = ypos - n;
				printf("S");
				n++;
			}
			
			disty = y-ypos;
			for(j=1; j<=disty; j++)
			{
				printf("SN");
				n=n+2;
			}
		}
	
	}//x less than y if ends here
		
		
		
	else // that is y is less than x
	{
		//printf("AREA x>y \n ");
		//for y
		if(y>=0)
		{
			while(ypos<y)
			{
				ypos = ypos + n;
				printf("N");
				n++;
			}
			
			disty = ypos-y;
			for(j=1; j<=disty; j++)
			{
				printf("NS");
				n=n+2;
			}
		}
		
		else
		{
			while(ypos>y)
			{
				ypos = ypos - n;
				printf("S");
				n++;
			}
			
			disty = y-ypos;
			for(j=1; j<=disty; j++)
			{
				printf("SN");
				n=n+2;
			}
		}
		
		//for x
		if(x>=0)
		{
			while(xpos<x)
			{
				xpos = xpos + n;
				printf("E");
				n++;
			}
			
			distx = xpos-x;
			for(j=1; j<=distx; j++)
			{
				printf("EW");
				n=n+2;
			}
		}
		
		else
		{
			while(xpos>x)
			{
				xpos = xpos - n;
				printf("W");
				n++;
			}
			
			distx = x-xpos;
			for(j=1; j<=distx; j++)
			{
				printf("WE");
				n=n+2;
			}
		}
		
		
	
	}//x greater than y if ends here
		
		printf("\n");
	}
}
