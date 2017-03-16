#include<stdio.h>
unsigned long long int ans;

void substrings(char *s,int n)
{
    while(*s)
    {
        int x=0,f,t,y;
        while(*(s + x))
        {
		t=0;
            for(y = 0; y <= x; y++)
	{
                if(s[y] != 'a' && s[y] != 'e' && s[y] != 'i' && s[y] != 'o' && s[y]!='u')
			t++;
		else
			t=0;
		if(t>=n)
		{
			ans++;
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
		ans = 0;
		substrings(str,n);		
		printf("Case #%d: %llu\n",i,ans);
	}
	return 0;
}
