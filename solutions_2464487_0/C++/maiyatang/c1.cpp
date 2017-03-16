#include<fstream>
using namespace std;
ifstream fin ("temp.in");
ofstream fout ("temp.out");
void find (long long int r,long long int t,long long int begin,long long int end)
{
     if (begin==end) {fout<<begin<<endl;return;}
     if (begin==end-1)
     {
         long long int temp=end*end*2+(2*r-1)*end;
         //fout<<temp<<" "<<t<<endl;
         if (temp>t) {fout<<begin<<endl;return;}
         else {fout<<end<<endl;return;}
     }
     long long int middle=(begin+end)/2;
     long long int temp=middle*middle*2+(r*2-1)*middle;
     //fout<<middle<<" "<<temp<<" "<<t<<endl;
     if (temp>t|temp<0) find(r,t,begin,middle-1);
     else find (r,t,middle,end);
 }
int main ()
{
    int t;
    fin>>t;
    int i;
    long long int end;
    for (i=0;i<t;i++)
    {
        fout<<"Case #"<<i+1<<": ";
        long long int r,m;
        fin>>r>>m;
        long long int begin=1;
        long long int end1=(long long int)sqrt (m/2.0);
        long long int end2=(long long int)(m/(2*r-1.0));
        if (end1>end2) end=end2;
        else end=end1;
        //fout<<begin<<" "<<end<<endl;
        find (r,m,begin,end);
    }
    return 0;
}
