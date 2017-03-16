#include <stdio.h>
#include <string.h>
#include <assert.h>


int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}


int solve(char *path, int targetx, int targety, int currentx, int currenty, int steps)
{	
	
	path[steps+1]='\0';
	//printf("path:[%s]\n",path);
	//printf("current x %d\n",currentx);
	
	if ((targetx == currentx) && (targety == currenty))
		return 1;
	if (currentx > 100)
		return 0;
	if (currenty > 100)
		return 0;
	if (currentx < -100)
		return 0;
	if (currenty < -100)
		return 0;	
	
	
    path[steps]='E';
	if (solve(path,targetx,targety,currentx+steps+1,currenty,steps+1) == 1)
		return 1;
	
    path[steps]='W';
	if(solve(path,targetx,targety,currentx-(steps+1),currenty,steps+1) == 1)
		return 1;
	
    path[steps]='N';
	if(solve(path,targetx,targety,currentx,currenty+steps+1,steps+1) == 1)
		return 1;
	
    path[steps]='S';
	if(solve(path,targetx,targety,currentx,currenty-(steps+1),steps+1) == 1)
		return 1;
		
	
}

int main(int argc, char **argv)
{
    int t, targetx, targety,i,j;
	char path[600];
	
    assert (scanf("%d ",&t) == 1); //Number of testcases
    for(i=1;i<=t;i++)
    {
        assert (scanf("%d %d ",&targetx, &targety) == 2);

	    path[0]='\0';
		
		if(targetx > 0)
		{
            for(j=0;j<targetx;j++)
			{
				strcat(path,"WE");
			}
		}		
		if(targetx < 0)
		{
            for(j=0;j>targetx;j--)
			{
				strcat(path,"EW");
			}
		}		
		if(targety > 0)
		{
            for(j=0;j<targety;j++)
			{
				strcat(path,"SN");
			}
		}		
		if(targety < 0)
		{
            for(j=0;j>targety;j--)
			{
				strcat(path,"NS");
			}
		}		
			
		
        //solve(path, targetx, targety, 0,0,0);
		
		printf("Case #%d: %s\n",i,path);

    }
    return 0;
}
