#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cstdlib>
using namespace std;

typedef __int64 LL;
char str[20];
vector<LL> save;
bool palindrom(LL num)
{
	LL i=0,j;
	bool flag=true;
	while(num>0)
	{
		str[i++]=(num%10)+'0';
		num/=10;
	}
	j=0;
	i--;
	while(j<i)
	{
		if(str[j]==str[i])
		{
			j++;
			i--;
		}
		else
		{
			flag=false;
			break;
		}
	}
	return flag;
}
LL bs(LL value)
{
	LL l=0,r=save.size()-1,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(save[mid]==value){return mid+1;}
		if(value<save[mid]){r=mid-1;}
		else{l=mid+1;}
	}
	return r+1;
}
int main()
{
	LL i,t,cas=0,id1,id2,a,b/*,v*/;
	bool istrue;
	for(i=1;i<=10000000;i++)
	{
		istrue=palindrom(i);
		if(istrue==false){continue;}
		istrue=palindrom(i*i);
		if(istrue==false){continue;}
		save.push_back(i*i);
	}
/*	cout<<save.size()<<endl;
	for(i=0;i<39;i++)
	{
		v=save[i];
		printf("%I64d ",v);
	}*/
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%I64d",&t);
	while(t--)
	{
		scanf("%I64d%I64d",&a,&b);
		id1=bs(a-1);
		id2=bs(b);
		printf("Case #%I64d: %I64d\n",++cas,id2-id1);
	}
	return 0;
}