#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;

ifstream fin ("1.in");
ofstream fout("1.out");

struct pnt{int val,indx; bool mark;};

pnt a[210];

bool compare(pnt a,pnt b){return a.val>b.val;}
bool compare1(pnt a,pnt b){return a.indx<b.indx;}

int main()
{
  int t,n,k,i,nn;
  long double sum,num,nsum;
  fin >> t;
  for(k=1;k<=t;k++)
  {
    fin >> n;sum=0;
    for(i=1;i<=n;i++)
    {
      fin >> a[i].val;
      a[i].indx=i;a[i].mark=0;
      sum+=a[i].val;
    }
    nn=n;nsum=sum;
    sort(a+1,a+n+1,compare);
    fout << "Case #" << k << ": ";
    for(i=1;i<=n;i++)
    {
      num=100*(sum-nn*a[i].val+nsum)/(nn);
      if(num<0)
      {
	nn--;nsum-=a[i].val;
	a[i].mark=1;
      }
    }
    sort(a+1,a+n+1,compare1);
    for(i=1;i<=n;i++)
    {
      if(a[i].mark)
      {
	fout << 0 << " ";
	continue;
      }
      num=100*(sum-nn*a[i].val+nsum)/(nn*sum);
      fout << setprecision(9) << num << " ";
    }
    fout << endl;
  }
  return 0;
}