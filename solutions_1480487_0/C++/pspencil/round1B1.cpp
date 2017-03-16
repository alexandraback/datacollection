#include<fstream>
#include<cmath>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;

int main()
{
    ifstream in("A-small-attempt6.in");
    ofstream out("out.txt");
    long T;
    in>>T;
    for(long i=0;i<T;i++)
    {
        out<<"Case #"<<i+1<<":";
        long n,n1;
        in>>n;n1=n;
        long sum=0, a[n];
        for(long k=0;k<n;k++)
        {
            long x;
            in>>x;
            sum+=x;
            a[k]=x;
        }
        long sum1=sum;
        double result[n];
        for(long k=0;k<n;k++)
        result[k]=1;
        for(long k=0;k<n1;k++)
        {
            double m=(double)((1/(double)n1)*(double)(2*sum)-(double)a[k])/(double)(sum);
            if(m<0) 
            {sum1-=a[k];n-=1;result[k]=0;}
        }
        for(long k=0;k<n1;k++)
        {
            if(result[k]==0) out<<" "<<fixed<<setprecision(6)<<result[k];
            else
            {
                result[k]=(double)((1/(double)n)*(double)(sum+sum1)-(double)a[k])/(double)(sum);
                out<<" "<<fixed<<setprecision(6)<<result[k]*100;
            }
        }
        out<<endl;
    }
        
    in.close();
    out.close();
    return 0;
}
