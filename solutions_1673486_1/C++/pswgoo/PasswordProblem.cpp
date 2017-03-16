#include<fstream>
#include<iomanip>
using namespace std;
int T;
const int M=100010;
double wr[M];
double pA[M];
int len=0;

void countWR(int A);
double work(int A,int B);
int main()
{
    ifstream fin("A-large.in");
    ofstream fout("out1.txt");
	fin>>T;
	for(int i=0; i!=T;++i)
	{   int A,B;
	    fin>>A>>B;
		len = A;
		pA[0]=1;
		pA[A+1]=0;
		for(int j=0; j!=A; ++j)
		    fin>>pA[j+1];
		countWR(A);
		double ans = work(A,B);
		fout<<"Case #"<<i+1<<": "<<setiosflags(ios::fixed)<<setprecision(6);
		fout<<ans<<endl;
	}
	return 0;
}

void countWR(int A)
{
    double last = 1;
    for(int i=1;i!=A+2;++i)
	{   last *= pA[i-1];
		wr[i] = (1-pA[i])*last;
	}
}
double work(int A,int B)
{
    double ans;
	int rest = B-A+1;
	ans = wr[A+1]*rest+(1-wr[A+1])*(rest+B+1);
    if(ans>B+2) ans = B+2;
	double last = wr[A+1];
	for(int i=1; i!=A+1; ++i)
    {   double tmp,tmpA;
	    tmp = last + wr[A-i+1];
		last = tmp;
		tmpA = tmp*(B-A+2*i+1) + (1-tmp)*(2*B-A+2*i+2);
		if(tmpA<ans)
		    ans = tmpA;
	}
	return ans;
}
		    