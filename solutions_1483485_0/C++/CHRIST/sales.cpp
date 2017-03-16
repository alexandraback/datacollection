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
void main()
{
	int test,i,len;
	char str[200];
	ifstream fin("A-small-attempt0.in",ios::binary|ios::in);
	ofstream fout("outputAs.out",ios::out);
	fin>>test;
	fin.getline(str,200);
	//fflush(NULL);
	for(int t_c=0;t_c<test;t_c++)
	{
		fin.getline(str,200);
		len=strlen(str);
		for(i=0;i<len;i++)
		{
			switch(str[i])
			{
			case 'a':
				str[i]='y';
				break;
			case 'b':
				str[i]='h';
				break;
			case 'c':
				str[i]='e';
				break;
			case 'd':
				str[i]='s';
				break;
			case 'e':
				str[i]='o';
				break;
			case 'f':
				str[i]='c';
				break;
			case 'g':
				str[i]='v';
				break;
			case 'h':
				str[i]='x';
				break;
			case 'i':
				str[i]='d';
				break;
			case 'j':
				str[i]='u';
				break;
			case 'k':
				str[i]='i';
				break;
			case 'l':
				str[i]='g';
				break;
			case 'm':
				str[i]='l';
				break;
			case 'n':
				str[i]='b';
				break;
			case 'o':
				str[i]='k';
				break;
			case 'p':
				str[i]='r';
				break;
			case 'q':
				str[i]='z';
				break;
			case 'r':
				str[i]='t';
				break;
			case 's':
				str[i]='n';
				break;
			case 't':
				str[i]='w';
				break;
			case 'u':
				str[i]='j';
				break;
			case 'v':
				str[i]='p';
				break;
			case 'w':
				str[i]='f';
				break;
			case 'x':
				str[i]='m';
				break;
			case 'y':
				str[i]='a';
				break;
			case 'z':
				str[i]='q';
				break;
			}
		}
		fout<<"Case #"<<t_c+1<<": "<<str<<endl;
		cout<<"Case #"<<t_c+1<<": "<<str<<endl;
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
