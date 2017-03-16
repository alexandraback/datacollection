
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;




int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	
	int T;cin>>T;
	for (int qq=1;qq<=T;qq++)
	{
		cout <<"Case #"<<qq<<": "<<endl;
		int r,n,m,k;
		cin>>r>>n>>m>>k;
		int t[10]={0};
		int a[8005][15]={0};
		for (int i=0;i<r;i++)
		{
			for (int j=0;j<k;j++)
			{
				cin >>a[i][j];
			}
		}
		for (int i=0;i<10;i++)
		{
			t[i]=0;
		}
		if (n==0)
		{
			cout <<endl;
		}
		if (n==1)
		{
			int num=0;
			for (int i=0;i<r;i++)
			{
				for (int j=0;j<k;j++)
				{
					if (a[i][j]!=1) num=a[i][j];
					break;
				}
				if (num!=0) break;
			}
			cout << num<<endl;
		}
		if (n==2)
		{
			for (int i=0;i<r;i++)
			{
				for (int j=0;j<k;j++)
				{
					if (a[i][j]!=1 && a[i][j]<6 && a[i][j]!=4) t[a[i][j]]=1;
					if (a[i][j]==6) {t[2]=1;t[3]=1;}
					if (a[i][j]==8) {t[2]=1;t[4]=1;}
					if (a[i][j]==9) {t[3]=2;}
					if (a[i][j]==16) {t[4]=2;}
					if (a[i][j]==25) {t[5]=2;}
					if (a[i][j]==10) {t[2]=1;t[5]=1;}
					if (a[i][j]==12) {t[3]=1;t[4]=1;}	
					if (a[i][j]==15) {t[3]=1;t[5]=1;}
					if (a[i][j]==20) {t[4]=1;t[5]=1;}
				}
			}
			for (int i=2;i<6;i++)
			{
				//if (t[i]==1) cout <<i;
				for (int j=0;j<t[i];j++)
				{
					cout <<i;
				}
			}
			cout<<endl;
		}
		if (n==3)
		{
			for (int i=0;i<r;i++)
			{
				for (int j=0;j<k;j++)
				{
					if (a[i][j]!=1 && a[i][j]<6 && a[i][j]!=4) t[a[i][j]]=1;
					if (a[i][j]==6) {t[2]=1;t[3]=1;}
					if (a[i][j]==8) {t[2]=1;}
					if (a[i][j]==9) {t[3]=2;}
					//if (a[i][j]==16) {t[4]=1;}
					if (a[i][j]==25) {t[5]=2;}
					if (a[i][j]==10) {t[2]=1;t[5]=1;}
					//if (a[i][j]==12) {t[3]=1;t[4]=1;}	
					if (a[i][j]==15) {t[3]=1;t[5]=1;}
					//if (a[i][j]==20) {t[4]=1;t[5]=1;}
					if (a[i][j]==27) {t[3]=3;}
					if (a[i][j]==125) {t[5]=3;}
					if (a[i][j]==64) {t[4]=3;}
					if (a[i][j]==36) {t[3]=2;t[4]=1;}
					if (a[i][j]==120) {t[3]=1;t[4]=1;t[5]=1;}
					if (a[i][j]==40) {t[2]=1;t[4]=1;t[5]=1;}
					if (a[i][j]==24) {t[2]=1;t[3]=1;t[4]=1;}
					if (a[i][j]==30) {t[2]=1;t[3]=1;t[5]=1;}
					if (a[i][j]==80) {t[4]=2;t[5]=1;}
					if (a[i][j]==100) {t[4]=1;t[5]=2;}
					if (a[i][j]==75) {t[3]=1;t[5]=2;}
					if (a[i][j]==50) {t[5]=2;t[2]=1;}
					if (a[i][j]==48) {t[4]=2;t[3]=1;}
					if (a[i][j]==32) {t[4]=2;t[2]=1;}
					if (a[i][j]==18) {t[3]=2;t[2]=1;}
				}
			for (int i=2;i<6;i++)
			{
				//if (t[i]==1) cout <<i;
				for (int j=0;j<t[i];j++)
				{
					cout <<i;
				}
			}
			cout<<endl;
			}
		}

		
	}



	
	return 0;
}