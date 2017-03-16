#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
#include<stdio.h>
#include<fstream>
using namespace std;
vector<int> paldome;
vector<int> pal;
bool ispal()
{
	int r=pal.size();
	for(int i=0;i<=(r-1)/2;i++)
	{
		if(pal.at(i)==pal.at(r-i-1))
		{
		}
		else
		{
			return false;
		}
	}
	return true;
}
void genpaldome(int size,long long A,long long B,int depth,int *count)
{
	if(depth==(size+1)/2)
	{	
		long long temp=0;
		for(int l=0;l<depth;l++)
		{
			temp=temp*10+paldome.at(l);
		}
		for(int l=size-depth-1;l>=0;l--)
		{
			temp=temp*10+paldome.at(l);
		}
		 // cout<<temp<<endl;
		    temp=temp*temp;
		    if(temp>=A&&temp<=B)
		    {
		    	while(temp>0)
		    	{
		    		pal.push_back(temp%10);
		    		temp=temp/10;
		    	}
		    	if(ispal())
		    	{
		    		*count=*count+1;
		    	}
		    }
		    pal.clear();
		    return;
	}
	int r=0;
	if(depth==0)
	{
		r=1;
	}
	for(int i=r;i<=9;i++)
	{
		paldome.push_back(i);
		genpaldome(size,A,B,depth+1,count);
		paldome.pop_back();
	}
}
int main()
{
	fstream fin("mow.txt");
	fstream fout("out.txt", ios::out);
	int T;
	fin>>T;
	for(int round=1;round<=T;round++)
	{
		int count=0;
		long long A,B;
		fin>>A>>B;
		long long sqA=(long long)(sqrt(A));
		long long sqB=(long long)(sqrt(B));
		int sizeA=0;
		int sizeB=0;
		long long temA=sqA;
		long long temB=sqB;
		while(temA>0)
		{
			sizeA++;
			temA=temA/10;
		}
			while(temB>0)
		{
			sizeB++;
			temB=temB/10;
		}
	//	fout<<sqA<<endl<<sqB<<endl;
		for(int i=sizeA;i<=sizeB;i++)
		{
			paldome.clear();
			genpaldome(i,A,B,0,&count);
		}
		fout<<"Case #"<<round<<": "<<count<<endl;
	}
}
