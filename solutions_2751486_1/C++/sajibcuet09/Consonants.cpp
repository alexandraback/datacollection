//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
int id[30];
char st[1000005];
int main()
{
	int t,cs=1,i,j,k,l,m,n,ans,a,b;
	FILE *f1,*f2;
	f1=fopen("in.txt","r");
	f2=fopen("out.txt","w");
	id['a'-'a']=id['e'-'a']=id['i'-'a']=id['o'-'a']=id['u'-'a']=1;
	fscanf(f1,"%d",&t);
	while(t--)
	{
		fscanf(f1,"%s%d",st,&n);
		l=strlen(st);
		for(i=k=ans=j=0,m=1;i<l;i++)
		{
			if(!id[st[i]-'a'])
				k++;
			else
				k=0,m=1;
			if(k>=n)
			{
				a=i-n-j+1;
				b=l-i;
				ans+=(a*b)+b;
				j=i-n+2;
				m=0;
			}
		}
		fprintf(f2,"Case #%d: %d\n",cs++,ans);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}