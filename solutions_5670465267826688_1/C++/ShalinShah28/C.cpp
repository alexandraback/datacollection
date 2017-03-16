#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
using namespace std;
#define llu long long unsigned int
#define lli long long int
#define li long int
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define mod 1000000007
int scan()    {int ip=getchar_unlocked(),ret=0,flag=1;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
li scanli()    {int ip=getchar_unlocked(),flag=1;li ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
lli scanlli()    {int ip=getchar_unlocked(),flag=1;lli ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
llu scanllu()    {int ip=getchar_unlocked();llu ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked());for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return ret;}
void print(int n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=10;char output_buffer[10];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<10);}
void printli(li n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=11;char output_buffer[11];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<11);}
void printlli(lli n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<21);}
void printllu(llu n)     {int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<21);}

lli a[1000001],b[1000001];
lli matrix[5][5];
string s;

int main()
{
	matrix[1][1]=1;
	matrix[2][1]=2;
	matrix[3][1]=3;
	matrix[4][1]=4;
	matrix[1][2]=2;
	matrix[1][3]=3;
	matrix[1][4]=4;
	matrix[2][2]=-1;
	matrix[2][3]=4;
	matrix[2][4]=-3;
	matrix[3][2]=-4;
	matrix[3][3]=-1;
	matrix[3][4]=2;
	matrix[4][2]=3;
	matrix[4][3]=-2;
	matrix[4][4]=-1;
	lli t=scanlli(),i,j,k;
	for(k=1;k<=t;k++)
	{
		lli l=scanlli(),x=scanlli();
		if(x>8)
			x=x%4+8;
		cin>>s;
		lli len=l*x,current=1,minus=1;
		for(i=0;i<len;i++)
		{
			a[i]=matrix[abs(current)][(s[i%l]-'i'+2)];
		
		//	cout<<"minus : "<<minus<<" "<<"a[3] : "<<a[i]<<" "<<"current : "<<current<<endl;
			
			if(a[i]<0)
			{
				a[i]=a[i]*minus;
				minus*=-1;
			}
			else
				a[i]=a[i]*minus;
			
				

			current=a[i];
			
			//cout<<a[i]<<" ";
		}
	//cout<<endl;
		current=1,minus=1;
		b[len-1]=s[l-1]-'i'+2;
		current=b[len-1];
		for(i=len-2;i>=0;i--)
		{
			b[i]=matrix[s[i%l]-'i'+2][abs(current)];
			//current=minus*b[i];
			if(b[i]<0)
			{
				b[i]*=minus;
				minus*=-1;
			}
			else
				b[i]*=minus;
			
			current=b[i];
		}
	//	for(i=0;i<len;i++)
	//		cout<<b[i]<<" ";
		
		lli flag=0;
		for(i=0;i<len-2;i++)
		{
			if(a[i]==2)
			{
				//cout<<"hello1"<<endl;
				for(j=i+2;j<len;j++)
				{
					if(b[j]==4)
					{
						if(a[j-1]>0 and a[i]>0 and matrix[a[j-1]][a[i]]==3)
						{
							flag=1;
							break;
						}
					}
				}
			}
			if(flag==1)
				break;
		}
		if(flag==0)
			cout<<"Case #"<<k<<": "<<"NO"<<endl;
		else if(flag==1)
			cout<<"Case #"<<k<<": "<<"YES"<<endl;

	}
	return 0;
}	