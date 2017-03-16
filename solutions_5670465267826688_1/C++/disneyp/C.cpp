#include <iostream>
#include<cstdio>
#include<string>
using namespace std;
string s;
int a[10][10],b[10][10]; //b = sign
int l[100010],r[100010],lsign[100010],rsign[100010];
pair <int,int> mul(int aa,int bb,int cc,int dd)
{
	return make_pair(a[aa][cc],bb*dd*b[aa][cc]);
}
int main()
{
	freopen("C.in","r",stdin);
	freopen("C.txt","w",stdout);
	pair <int,int> z;
	int C= 1 , D=-1,xx,yy,xxx,yyy;
	int t;
	for(int i=1;i<=4;i++)
	{
		a[1][i]=i;b[1][i]=1;
	}
	a[2][1]=2;b[2][1]=1;
	a[2][2]=1;b[2][2]=-1;
	a[2][3]=4;b[2][3]=1;
	a[2][4]=3;b[2][4]=-1;
	
	a[3][1]=3;b[3][1]=1;
	a[3][2]=4;b[3][2]=-1;
	a[3][3]=1;b[3][3]=-1;
	a[3][4]=2;b[3][4]=1;
	
	a[4][1]=4;b[4][1]=1;
	a[4][2]=3;b[4][2]=1;
	a[4][3]=2;b[4][3]=-1;
	a[4][4]=1;b[4][4]=-1;
	
	
	long long L,X,Y;
	cin >> t;
	int ch,now,sign;
	int p,q;
	for(int i=0;i<t;i++)
	{
		ch = 0;
		cin >> L >> X;
		cin >> s;
		now = 1;sign =1;
		for(int j=0;j<L;j++)
		{
			z = mul(now,sign, s[j]-'i'+2,1);
			l[j] = z.first;
			lsign[j]=z.second;
			//cout << "-------" << l[j] << " " << lsign[j] << endl;
			
			z = make_pair(l[j],lsign[j]);
			now = z.first;
			sign = z.second;
		}
		now = 1;sign =1;
		for(int j=L-1;j>=0;j--)
		{
			z = mul(s[j]-'i'+2,1,now,sign);
			r[j]=z.first;
			rsign[j]=z.second;
			
			z = make_pair(r[j],rsign[j]);
			now = z.first;
			sign = z.second;
		}
		Y = X%4;
		now = 1;sign = 1;
		p = l[L-1];q=lsign[L-1];
		for(int j=0;j<Y;j++)
		{
			z = mul(now,sign, p,q);
			now = z.first;
			sign = z.second;
		}
		//cout << "====" << p << " " << q << endl;
		if(now!=1 or sign!=-1)
		{
			//ijk != product
			cout << "Case #" << i+1 << ": " << "NO" << endl;
			continue;
		}
		now = 1;sign=1;
		xx=-1;yy=-1;
		for(int k=0;k<4;k++)
		{
			for(int j=0;j<L;j++)
			{
				if( make_pair(2,1) == mul(now,sign, l[j],lsign[j]) )
				{
					xx=k;yy=j;
					break;
				}
			}
			if(xx>-1) break;
			z = mul(now,sign,p,q);
			now = z.first;
			sign = z.second;
		}
		
		now=1;sign=1;
		xxx=-1;yyy=-1;
		for(int k=0;k<4;k++)
		{
			for(int j=L-1;j>=0;j--)
			{
				if(make_pair(4,1) == mul(r[j],rsign[j],now,sign))
				{
					xxx = k;
					yyy= j;
					break;
				}
			}
			if(xxx>-1) break;
			z = mul(p,q,now,sign);
			now = z.first;
			sign = z.second;
		}
		//cout << "=============" << xx << " " << yy << " " << xxx << " " << yyy << endl;
		if(xx==-1 or xxx==-1)
		{
			//cannot make i,k
			cout << "Case #" << i+1 << ": " << "NO" << endl;
			continue;
		}
		if(yy < yyy)
		{
			if(xx + xxx + 1 <=X)
			{
				//yes
				cout << "Case #" << i+1 << ": " << "YES" << endl;
			}
			else
			{
				//not enough
				cout << "Case #" << i+1 << ": " << "NO" << endl;
			}
		}
		else
		{
			if(xx+xxx+2 <=X)
			{
				cout << "Case #" << i+1 << ": " << "YES" << endl;
			}
			else cout << "Case #" << i+1 << ": " << "NO" << endl;
		}
		
	}
}