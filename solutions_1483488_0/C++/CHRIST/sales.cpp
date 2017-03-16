#include<iostream>
#include<fstream>
#include<conio.h>
//#include<inttypes.h>
#include<iomanip>
#include<assert.h>
#include<ctype.h>
#include<errno.h>
#include<float.h>
#include<limits.h>
#include<locale.h>
#include<math.h>
#include<string.h>
#include<stdarg.h>
#include<stddef.h>
#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<wchar.h>
#include<wctype.h>
#include<queue>
#include<vector>
#include<list>
//#include<E:\gcj\header\BigInt\BigInt.h>
//#include<E:\gcj\header\BigInt\BigInt.cpp>
#define bigint CBigInt
#define max(a,b) a>b?a:b
#define min(x,y) x>y?y:x
//#include<E:\gcj\header\ritwik.H>
using namespace std;	
/*long long int smooth(int *a,int n,int k,int d,int i,int m)
{
	int j,x;
	long long int ans=0;
	if(k==1)
		return 0;
	else
	{
		ans=smooth(a,n,k-1,d,i,m);
		if(abs(a[k-1]-a[k])<=m)
		{
			return ans;
		}
		else
		{

		}
	}
}*/
/*class CPolygon {
  private:
    int width, height;
  public:
    void set_values (int a, int b)
      { width=a; height=b;}
  };

class CRectangle: public CPolygon {
  public:
    int area ()
      { return (width * height); }
  };

class CTriangle: public CPolygon {
  public:
    int area ()
      { return (width * height / 2); }
  };*/
int valid(long long int n)
{
	char str[10];
	int i=0;
	while(n!=0)
	{
		str[i++]=n%10+'0';
		n/=10;
	}
	str[i]='\0';
	for(i=0;i<strlen(str)-1;i++)
	{
		if(str[i]<str[i+1])
			return 0;
	}
	return 1;
}
int allsame(long long int n)
{
	int digit=n%10;
	while(n!=0)
	{
		if(n%10!=digit)
			return 0;
		n/=10;
	}
	return 1;
}
long long int cycle(long long int n,int l)
{
	int str[10],i,len,first,temp;
	long long int sum=0;
	i=0;
	while(n!=0)
	{
		str[i++]=n%10;
		n/=10;
	}
	len=i;
	while(l--)
	{
		first=str[0];
		for(i=0;i<len-1;i++)
			str[i]=str[i+1];
		str[len-1]=first;
	}
	for(i=0;i<len;i++)
	{
		sum+=str[i]*pow(10.0,i);
	}
	return sum;
}
int samedig(long long int n1,long long int n2)
{
	int l1,l2;
	l1=l2=0;
	while(n1!=0)
	{
		l1++;
		n1/=10;
	}
	while(n2!=0)
	{
		l2++;
		n2/=10;
	}
	if(l1==l2)	return 1;
	else	return 0;
}
void main()
{
	int test;
	//cout<<cycle(120,1);
	long long int a,b,i,j,ans,count,x;
	int flag[3010],f,digits;
	ifstream fin("C-small-attempt0.in",ios::binary|ios::in);
	ofstream fout("outputCs.out",ios::out);
	fin>>test;
	for(int t_c=0;t_c<test;t_c++)
	{
		fin>>a>>b;
		ans=0;
		for(i=0;i<3010;i++)
			flag[i]=0;
		for(i=a;i<=b;i++)
		{
			if(!allsame(i))
			{
				//cout<<"i="<<i<<endl;
				/*if(i<100)
					ans+=1;
				else if(i<1000)
					ans+=3;
				else if(i<10000)
					ans+=6;*/
				x=i;
				count=1;
				f=0;
				digits=0;
				while(x!=0)
				{
					digits++;
					x/=10;
				}
				x=i;
				//cout<<digits<<endl;
				for(j=1;j<digits;j++)
				{
					x=cycle(i,j);
					if(x<=b&&x>=a&&samedig(x,i)&&flag[x]==0)
					{
						count++;
						//cout<<x<<" ";
					}
					if(flag[x]==1)
					{
						f=1;
						break;
					}
					else	flag[x]=1;
				}
				if(f==1)	continue;
				else	flag[i]=1;
				//cout<<endl;
				if(count==2)
					ans+=1;
				else if(count==3)
					ans+=3;
				else if(count==4)
					ans+=6;
				else if(count==5)
					ans+=10;
				//cout<<"ans="<<ans<<endl;
			}
		}
		fout<<"Case #"<<t_c+1<<": "<<ans<<endl;
		cout<<"Case #"<<t_c+1<<": "<<ans<<endl;
	}
	//cout<<sizeof(int)<<" "<<sizeof(long int)<<" "<<sizeof(long long int);
	fin.close();
	fout.close();
	/*CRectangle rect;
	CTriangle trgl;
	rect.set_values (4,5);
	trgl.set_values (4,5);
	cout << rect.area() << endl;
	cout << trgl.area() << endl;*/
	getch();
}
