#include<fstream>
#include<iomanip>
#include<string.h>
using namespace std;
const int M = 210;
int si[M];
double ans[M];
double sum;
int N;

void work();
double getMin(double total,int n,bool* b);
int main()
{
    ifstream fin("A-large.in");
	ofstream fout("out.txt");
	int T;
	fin>>T;
	for(int i=0;i!=T;++i)
	{   fin>>N;
	    sum = 0;
	    for(int j=0;j!=N;++j)
		{   fin>>si[j];
		    sum += si[j];
		}
		work();
		fout<<"Case #"<<i+1<<": ";
		for(int j=0;j!=N;++j)
		{   if(j!=N-1) fout<<setiosflags(ios::fixed)<<setprecision(6)<<ans[j]<<" ";
		    else fout<<setiosflags(ios::fixed)<<setprecision(6)<<ans[j]<<endl;
		}
	}
	return 0;
}

void work()
{
    bool b[M];
	memset(b,0,sizeof(b));
    double ave = getMin(2*sum,N,b);
	for(int i=0;i!=N;++i)
	{   if(si[i]>=ave) ans[i] = 0;
	    else ans[i] = (ave-si[i])/sum * 100;
	}
}
double getMin(double total,int n,bool* b)
{   
    double a = total/n;
    bool  bb = false;
    for(int i=0;i!=N;++i)
	{   if(!b[i]&&si[i]>=a)
	    {   ans[i] = 0;
		    total -= si[i];
			b[i] = true;
			--n;
			bb = true;
		}
	}
	if(bb) return getMin(total,n,b);
	else  return a;
}