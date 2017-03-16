//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<string>
#include<map>
using namespace std;
map<string,int>mp;
int id[30];
int ok(char *s,int n)
{
	int i,j=strlen(s),k=0;
	for(i=0;i<j;i++)
	{
		if(!id[s[i]-'a'])
			k++;
		else
		{
			if(k>=n)
				return 1;
			k=0;
		}
	}
	return k>=n;
}
int main()
{
	char st[200],s[200];
	int t,cs=1,i,j,k,l,n,ans;
	FILE *f1,*f2;
	f1=fopen("in.txt","r");
	f2=fopen("out.txt","w");
	id['a'-'a']=id['e'-'a']=id['i'-'a']=id['o'-'a']=id['u'-'a']=1;
	fscanf(f1,"%d",&t);
	while(t--)
	{
		fscanf(f1,"%s%d",st,&n);
		l=strlen(st);
		for(i=ans=0;i<l;i++)
		{
			for(j=i,k=0;j<l;j++)
			{
				s[k++]=st[j];
				s[k]=0;
				if(ok(s,n))
					ans++;
			}
		}
		fprintf(f2,"Case #%d: %d\n",cs++,ans);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}