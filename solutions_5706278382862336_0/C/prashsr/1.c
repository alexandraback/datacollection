#include<stdio.h>
int gcd(int n, int m);

main()
{
	int i,t,cnt;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		cnt=maina();
		if(cnt>=0)
		printf("Case #%d: %d\n",i,cnt);
		else
		printf("Case #%d: impossible\n",i);
	}

}
maina()	
{
int p,q,i,count,flag,r;
scanf("%d/%d",&p,&q);
flag=gcd(p,q);
p=p/flag;
q=q/flag;
if(q==1||q==2||q==4||q==8||q==16||q==32||q==64||q==128||q==256||q==512)
	{count=0;
	while(q>p)
	{
		p=p*2;
		count++;

	}
return count;
	}



else
return -1;


}


int gcd(int m, int n)
{
    int r;

    /* Check For Proper Input */
    if((m == 0) || (n == 0))
        return 0;
    else if((m < 0) || (n < 0))
        return -1;

    do
    {
        r = m % n;
        if(r == 0)
            break;
        m = n;
        n = r;
    }
    while(1);

    return n;
}
