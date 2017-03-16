#include<stdio.h>

int main()
{
 int t;
 int i,tr,max,c,need;
 char s[1005];
 for(scanf("%d",&t),tr=1;tr<=t;tr++)
 {
	 scanf("%d %s",&max,s);
	 //printf("%d %s\n",max,s);
	 for(i=0,c=0,need=0;s[i]!='\0';i++)
		 if(c>=i)
			 c+=s[i]-48;
		 else if(s[i]>'0')
			 need+=i-c,c=i+s[i]-48;
	//printf("%d %d %c\n",c,i,s[i]);
	 printf("Case #%d: %d\n",tr,need);
 }
 return 0;
}