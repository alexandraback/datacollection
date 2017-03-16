#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>

#define Ari using
#define ganteng namespace
#define banget std

#define ll long long
#define ul unsigned long long
#define pb push_back
#define mp make_pair
#define lcm(a,b) a*b/__gcd(a,b)
#define lsb(a) (a & (-a))
#define ft first
#define sc second
#define inf 10000000

#define STRtoINT(a,b) istringstream(a)>>b
#define INTtoSTR(a,b) b=static_cast<ostringstream*>(&(ostringstream()<<a))->str()

//set -> pair <set<int>::iterator,bool> pa; pa=set.insert(x); pa.second return bool;

template<typename t>
t getnum()
{
 t res=0;
 char c;
 int sign=1;
 while(1){
	c=getchar();
	if(c==' '||c=='\n')continue;
	else break;}
 if(c=='+'){}
 else if(c=='-')sign=-1;
 else res=c-'0';
 while(1){
	c=getchar();
	if(c>='0'&&c<='9')res=res*10+c-'0';
	else break;}
return res*sign;
}

Ari ganteng banget;

int row,col,mine;
bool found;

void cek(int baris, int sisa, int pindah)
{
	int id=pindah;
	if(found==true)return;
	if(baris<0)return;
	if(baris==1 && id==-1)id=1;
	//cout<<baris<<" "<<sisa<<" "<<id<<endl;
	if(baris==2 && sisa==col+1 && col>4)
	{
		found=true;
	//	cout<<"hai"<<baris<<" "<<sisa<<" "<<id<<endl;
		printf("c");
		for(int x=1;x<(col-2);x++)printf("."); printf("**\n");
		for(int x=0;x<(col-2);x++)printf("."); printf("**\n");
		for(int x=0;x<(col-2);x++)printf("."); printf("**\n");
		for(int x=3;x<row;x++)
		{
			for(int y=0;y<col;y++)
			{
				printf("*");
			}
			printf("\n");
		}
		return;
	}
	if(id==-1)
	{
		if(col>=sisa)
		{
			if(col==sisa+1){ 
			if(baris==2 && col>3)
			{
				found=true;
				printf("c");
				for(int x=1;x<(col-1);x++)printf("."); printf("*\n");
				for(int x=0;x<(col-1);x++)printf("."); printf("*\n");
				for(int x=0;x<3;x++)printf(".");
				for(int x=3;x<col;x++)printf("*"); printf("\n");
				for(int x=3;x<row;x++)
				{
					for(int y=0;y<col;y++)
					{
						printf("*");
					}
					printf("\n");
				}
			}
			cek(baris-1,sisa-col+2,baris);
			return;}
			if(baris==1)return;
			found=true;
			for(int x=0;x<row;x++)
			{
				for(int y=0;y<col;y++)
				{
					if(x==0 && y==0)printf("c");
					else if(x>baris)printf("*");
					else if(x<baris)printf(".");
					else
					{
						if(y<(col-sisa))printf(".");
						else printf("*");
					}
				}
				printf("\n");
			}
		}
		else
		{
			cek(baris-1,sisa-col,id);
			cek(baris-1,sisa-col+2,baris);
		}
	}
	else
	{
		if(col-2>=sisa)
		{
			if(baris==0 && col-sisa!=2)return;
			if(baris==1)return;
			found=true;
		//	cout<<"hai "<<baris<<" "<<sisa<<" "<<pindah<<endl;
			for(int x=0;x<row;x++)
			{
				for(int y=0;y<col;y++)
				{
					if(x==0 && y==0)printf("c");
					else if(x<baris)printf(".");
					else if(x>id)printf("*");
					else
					{
						if(x==baris)
						{
							if(y<(col-sisa))printf(".");
							else printf("*");
						}
						else
						{
							if(y<2)printf(".");
							else printf("*");
						}
					}
				}
				printf("\n");
			}
		}
		else cek(baris-1,sisa-col+2,id);
	}
}

void cek2(int kolom, int sisa, int pindah)
{
	int id=pindah;
	if(found==true)return;
	if(kolom<0)return;
	if(kolom==1 && id==-1)id=1;
	//cout<<kolom<<" "<<sisa<<" "<<pindah<<endl;
	if(id==-1)
	{
		if(row>=sisa)
		{
			if(row==sisa+1){ 
			if(kolom==2 && row>3)
			{
				found=true;
				for(int x=0;x<row;x++)
				{
					for(int y=0;y<col;y++)
					{
						if(x==0 && y==0)printf("c");
						else if(x==row-1)printf("*");
						else if(x<(row-sisa+2))
						{
							if(y<=kolom)printf(".");
							else printf("*");
						}
						else
						{
							if(y<kolom)printf(".");
							else printf("*");
						}
					}
					printf("\n");
				}
			}
			cek2(kolom-1,sisa-row+2,kolom);
			return;}
			if(kolom==1)return;
			found=true;
			//cout<<"hai "<<kolom<<" "<<sisa<<" "<<pindah<<endl;
			for(int x=0;x<row;x++)
			{
				for(int y=0;y<col;y++)
				{
					if(x==0 && y==0)printf("c");
					else if(y>kolom)printf("*");
					else if(y<kolom)printf(".");
					else
					{
						if(x<(row-sisa))printf(".");
						else printf("*");
					}
				}
				printf("\n");
			}
		}
		else
		{
			cek2(kolom-1,sisa-row,id);
			cek2(kolom-1,sisa-row+2,kolom);
		}
	}
	else
	{
		if(row-2>=sisa)
		{
			if(kolom==0 && row-sisa!=2)return;
			if(kolom==1)return;
			found=true;
			//cout<<"hai "<<kolom<<" "<<sisa<<" "<<pindah<<endl;
			for(int x=0;x<row;x++)
			{
				for(int y=0;y<col;y++)
				{
					if(x==0 && y==0)printf("c");
					else if(y<kolom)printf(".");
					else if(y>id)printf("*");
					else
					{
						if(y==kolom)
						{
							if(x<(row-sisa))printf(".");
							else printf("*");
						}
						else
						{
							if(x<2)printf(".");
							else printf("*");
						}
					}
				}
				printf("\n");
			}
		}
		else cek2(kolom-1,sisa-row+2,id);
	}
}

int main()
{
	freopen("C-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	int testcase=getnum<int>();
	for(int tc=1;tc<=testcase;tc++)
	{
		row=getnum<int>();
		col=getnum<int>();
		mine=getnum<int>();
		
		found=false;
		printf("Case #%d:\n",tc);
		if(mine==(row*col)-1)
		{
			for(int x=0;x<row;x++)
			{
				for(int y=0;y<col;y++)
				{
					if(x==0 && y==0)printf("c");
					else printf("*");
				}
				printf("\n");
			}
		}
		else if(mine==0)
		{
			for(int x=0;x<row;x++)
			{
				for(int y=0;y<col;y++)
				{
					if(x==0 && y==0)printf("c");
					else printf(".");
				}
				printf("\n");
			}
		}
		else
		{
			cek(row-1,mine,-1);
			if(found==false)cek2(col-1,mine,-1);
			if(found==false)printf("Impossible\n");
		}
		
	}

  return 0;
}

