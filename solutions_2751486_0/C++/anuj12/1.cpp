#include<stdio.h>
#include<iostream>
unsigned long long int out;

void print_sub(char *arr,int pos,int len,int *set)
{
	static int j;
	if(pos==len)
	{
		//print(set,len,arr);
		return ;
	}
	set[pos]=0;
	print_sub(arr,pos+1,len,set);
	set[pos]=1;
	print_sub(arr,pos+1,len,set);
}

void findAllSubstrings(char *s,int n)
{
    while(*s)
    {
        int x=0,f,t;
        while(*(s + x))
        {
		t=0;
            for(int y = 0; y <= x; y++)
	{
                if(s[y] != 'a' && s[y] != 'e' && s[y] != 'i' && s[y] != 'o' && s[y]!='u')
			t++;
		else
			t=0;
		if(t>=n)
		{
			out++;
			break;
		}
	}
            x++;
        }
        s++;
    }
}

int main()
{
	int t,i,n;	
	char str[1000001];
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%s%d",str,&n);
		out = 0;
		findAllSubstrings(str,n);		
		printf("Case #%d: %llu\n",i,out);
	}
	return 0;
}
