#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	for(int j=1;j<=t;j++)
	{
		int segment=0;
		int n;
		printf("Case #%d: ",j);
		int l[27]={},r[27]={},m[27]={},solo[27]={},k=0,count[26]={};
		char left[200]={},right[200]={};
		int middle[200]={};
		scanf("%d",&n);
		int flag=0;
		for(int i=0;i<n;i++)
		{
			char s[1000]={};
			scanf("%s",s);
			left[k]=s[0];
			right[k]=s[strlen(s)-1];
			
			int g=0;
			for(int i=0;i<strlen(s);i++)
			{
				int h=0;
				if(count[s[i]-'a']==0)
					count[s[i]-'a']=1;
				else
					g=1;
					
				if(i==0)
				{
					l[s[i]-'a']++;
					h=1;
				}
				if(i==strlen(s)-1&&strlen(s)!=1)
					r[s[i]-'a']++;
				
				while(s[i+1]==s[i]&&i+1<strlen(s))
					i++;
				if(i>0&&i<strlen(s)-1&&h==0)
				{
					m[s[i]-'a']++;
					middle[k]++;
				}
				if(i==strlen(s)-1&&h==1)
					solo[s[i]-'a']++;
			}
			if(middle[k]!=0&&left[k]==right[k])
			{
				flag=1;
				printf("0\n");
				break;
			}
			k++;
			if(g==0)
				segment++;
		}
	//	if(j==1)
//		for(int i=0;i<26;i++)
	//		cout<<l[i]<<" "<<r[i]<<" "<<solo[i]<<" "<<m[i]<<endl;
	
		if(flag==0)
		for(int i=0;i<26;i++)
		{
			if((m[i]!=0&&(l[i]!=0||r[i]!=0))||(l[i]-solo[i]>1)||r[i]>1||m[i]>1)
			{
				flag=1;
				printf("0\n");
				break;
			}
		}
		if(flag==0)
		{
			long long ans=1;
			for(int i=0;i<26;i++)
				if(solo[i]!=0)
					for(int q=2;q<=solo[i];q++)
					{
						ans*=q;
						ans%=1000000007;
					}
			int s=1;
			int c[26]={};
			char seg[200][2]={};
			int mark[200]={};
		/*	for(int i=0;i<n;i++)
			{
				if(left[i]==right[i]&&l[left[i]-'a']-solo[left[i]-'a']==0&&r[left[i]-'a']==0&&c[left[i]-'a']==0)
				{
					c[left[i]-'a']=1;
					s++;
				}
				if(left[i]==right[i]&&l[left[i]-'a']-solo[left[i]-'a']==1)
					
			}*/
			for(int l=2;l<=segment;l++)
			{
				ans*=l;
				ans%=1000000007;
			}
			printf("%lld\n",ans);
		}
			
	}
	return 0;
}
