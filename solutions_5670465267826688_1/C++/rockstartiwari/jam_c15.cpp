#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
string s;
int arr[5][5];
int cast[200];
int main()
{
	int t;
	freopen("C:\\Users\\Gaurav\\Desktop\\cl.in","r",stdin);
    freopen("C:\\Users\\Gaurav\\Desktop\\output.txt","w",stdout);
	scanf("%d",&t);
	int ca=0;
	arr[1][1]=1;arr[2][2]=arr[3][3]=arr[4][4]=-1;
	arr[1][2]=2;arr[1][3]=3;arr[1][4]=4;
	arr[2][1]=2;arr[3][1]=3;arr[4][1]=4;
	arr[2][3]=4;arr[2][4]=-3;
	arr[3][2]=-4;arr[3][4]=2;
	arr[4][2]=3;arr[4][3]=-2;
	cast[(int)('i')]=2;
	cast[(int)('j')]=3;
	cast[(int)('k')]=4;
	while(t--)
	{
		ca++;
		long long int l,x;
		cin>>l>>x;
		cin>>s;
		int si=1;
		int i;
		string st="";
		if(x<=10)
		{
			for(i=0;i<x;i++)
			{
				st=st+s;
			}
			int in=cast[(int)(st[0])];
			int pos=-1;
			if(in==2&&si==1&&pos==-1)
					pos=0;
			for(i=1;i<l*x;i++)
			{
				
				int a=cast[(int)(st[i])];
				int res=arr[in][a];
				//cout<<res<<" "<<a<<endl;
				if(res<0)
				{
					si=si*-1;
					res=res*-1;
					in=res;
				}
				else
					in=res;
				if(in==2&&si==1&&pos==-1)
					pos=i;
			}
			in=cast[(int)(st[l*x-1])];
			int pos2=-1;
			si=1;
			if(in==4&&si==1&&pos2==-1)
					pos2=l*x-1;
			for(i=l*x-2;i>=0;i--)
			{
				int a=cast[(int)(st[i])];
				int res=arr[a][in];
				if(res<0)
				{
					si=si*-1;
					res=res*-1;
					in=res;
				}
				else
					in=res;
				if(res==4&&si==1&&pos2==-1)
					pos2=i;
			}
			if(in==1&&si==-1&&pos<pos2&&pos!=-1&&pos2!=-1)
				printf("Case #%d: YES\n",ca);
			else
				printf("Case #%d: NO\n",ca);
		}
		else
		{
			long long int X=x;
			x=10;
			int fir,sif;
			for(i=0;i<x;i++)
			{
				st=st+s;
			}
			int in=cast[(int)(st[0])];
			int pos=-1;
			if(in==2&&si==1&&pos==-1)
					pos=0;
			for(i=1;i<l*x;i++)
			{
				
				int a=cast[(int)(st[i])];
				int res=arr[in][a];
				//cout<<res<<" "<<a<<endl;
				if(res<0)
				{
					si=si*-1;
					res=res*-1;
					in=res;
				}
				else
					in=res;
				if(in==2&&si==1&&pos==-1)
					pos=i;
				if(i==l-1){
					fir=in;
					sif=si;
				}
			}
			in=cast[(int)(st[l*x-1])];
			long long int pos2=-1;
			si=1;
			if(in==4&&si==1&&pos2==-1)
					pos2=l*x-1;
			for(i=l*x-2;i>=0;i--)
			{
				int a=cast[(int)(st[i])];
				int res=arr[a][in];
				if(res<0)
				{
					si=si*-1;
					res=res*-1;
					in=res;
				}
				else
					in=res;
				if(res==4&&si==1&&pos2==-1)
					pos2=i;
			}
			if(pos2>-1)
			pos2=l*X-(l*x-pos2);
			if(fir==1)
			{
				if((X%2)==0)
					sif=1;
			}
			else if(X%2==0){
				fir=1;
				if(X%4==0)
					sif=1;
				else
					sif=-1;
			}
			else
			{
				int si1=sif;
				X=X-1;
				if(X%4==0)
					sif=1;
				else
					sif=-1;
				
				//cout<<sif<<" "<<si1<<" "<<X<<endl;
				sif=sif*si1;

			}
			//printf("%d %d %d %d \n",fir,sif,pos,pos2);
			if(fir==1&&sif==-1&&pos<pos2&&pos!=-1&&pos2!=-1)
				printf("Case #%d: YES\n",ca);
			else
				printf("Case #%d: NO\n",ca);
		}
	}
	return 0;
}