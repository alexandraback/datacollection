#include<fstream>
#include<cmath>
#include<string.h>
using namespace std;
//const int M = 2000010;
//bool mark[M];
bool find(int* e,int l,int n);
int check(int A,int B);
int main()
{
    ifstream fin("C-small-attempt0.in");
	ofstream fout("out.txt");
	int T;
	fin>>T;
	for(int i=0;i!=T; ++i)
	{   int A,B;
	    fin>>A>>B;
		int ans = check(A,B);
		fout<<"Case #"<<i+1<<": "<<ans<<endl;
	}
	return 0;
}

int check(int A,int B)
{
    int tmp=A,len=0;
	int ans=0;
	while(tmp)
	{   ++len;
	    tmp/=10;
	}
	int exist[8];
	int cur=0;
    for(int i=A; i!=B; ++i)
	{   cur=0;
	    for(int j=1;j!=len;++j)
	    {   int base = (int)pow(float(10),j);
		    int low = i%base;
			int high = i/base;
		    int num = low*(int)pow(float(10),len-j)+high;
			if(num>i && num<=B && !find(exist,cur,num))
			{   ++ans;
			    exist[cur++] = num;
			}
		}
	}
	return ans;
}
bool find(int* e,int l,int n)
{
    for(int i=0; i!=l;++i)
	{   if(e[i]==n)
	        return true;
	}
	return false;
}