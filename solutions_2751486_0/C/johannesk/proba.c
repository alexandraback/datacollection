#include <stdio.h>
#include <string.h>
#include <assert.h>

int checkstring(char *s, int num)
{
	int i;
	
	for (i=0;i<num;i++)
	{
		if(s[i] == 'a')
			return 0;
		else if(s[i] == 'e')
			return 0;
		else if(s[i] == 'i')
			return 0;
		else if(s[i] == 'o')
			return 0;
		else if(s[i] == 'u')
			return 0;
	}
	return 1;
}


int checksub(char *s, int sublen, int num)
{
	int i,j;
	for(i=0;i<=(sublen-num);i++)
	{
		if(checkstring(&s[i],num) == 1)
			return 1;
	}
	return 0;
}

int sub(char *s, int len, int sublen, int num)
{
	int i,j,count;
	count=0;
	
	for(i=0;i<=(len-sublen);i++)
	{
		//printf("  Solve substring %s \n",&s[i]);
	    count += checksub(&s[i],sublen,num);
	}
	return count;
}


int solve(char *s, int num)
{
    int len, i;
	int count=0;
	
    len = strlen(s);
    for(i=len;i>=num;i--)
	{
		//printf("Solve for [%s] sublen %d\n",s,i);
		count+=sub(s,len,i,num);
	} 	
	return count;	
}


int main(int argc, char **argv)
{
    int t,i,j,count;
	int num;
	char s[1000000];
	
    assert (scanf("%d ",&t) == 1); //Number of testcases
    for(i=1;i<=t;i++)
    {
        assert (scanf("%s %d ",s, &num) == 2);
	 	
        count = solve(s,num);		
		printf("Case #%d: %d\n",i,count);

    }
    return 0;
}
