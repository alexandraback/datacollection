#include <stdio.h>
int abs(int x)
{
	if(x<0)
		return -x;
	return x;
}
char a[20],b[20];
void doe(int x)
{
	int i,len,i2,min=999999999,aa,bb;
	scanf("%s %s",a,b);
	for(len=0;a[len]!=0;len++);
	printf("Case #%d: ",x);
	if(len==1)
	{
		if(a[0]=='?'&&b[0]=='?')
		printf("0 0\n");
		else if(a[0]=='?')
			printf("%c %c\n",b[0],b[0]);
		else
			printf("%c %c\n",a[0],a[0]);
		
	}
	else if(len==2)
	{
		for(i=0;i<=9;i++)
			for(i2=0;i2<=9;i2++)
				for(int i3=0;i3<=9;i3++)
					for(int i4=0;i4<=9;i4++)
						if((i+48==a[0]||a[0]=='?')&&(i2+48==a[1]||a[1]=='?')&&(i3+48==b[0]||b[0]=='?')&&(i4+48==b[1]||b[1]=='?'))
						{
							//printf("%d%d %d%d %d",i,i2,i3,i4,abs(i*10+i2-i3*10-i4));
							if(abs(i*10+i2-i3*10-i4)<min)
							{
								//printf("OO");
								min=abs(i*10+i2-i3*10-i4);
								aa=i*10+i2;
								bb=i3*10+i4;
							}
							//printf("%d",min);
							//printf("\n");
						}
		//printf("%d\n",min);
		printf("%02d %02d\n",aa,bb);
	}
	else
	{
		for(i=0;i<=9;i++)
			for(i2=0;i2<=9;i2++)
				for(int i3=0;i3<=9;i3++)
					for(int i4=0;i4<=9;i4++)
					for(int i5=0;i5<=9;i5++)
					for(int i6=0;i6<=9;i6++)
						if((i+48==a[0]||a[0]=='?')&&(i2+48==a[1]||a[1]=='?')&&(i3+48==a[2]||a[2]=='?')&&(i4+48==b[0]||b[0]=='?')&&(i5+48==b[1]||b[1]=='?')&&(i6+48==b[2]||b[2]=='?'))
						{
							if(abs(i*100+i2*10+i3-i4*100-i5*10-i6)<min)
							{
								min=abs(i*100+i2*10+i3-i4*100-i5*10-i6);
								aa=i*100+i2*10+i3;
								bb=i4*100+i5*10+i6;
							}
						}
		printf("%03d %03d\n",aa,bb);
	}
}
int main()
{
	freopen("B.in","r",stdin);
	freopen("Bout.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		doe(i);
	return 0;
}
