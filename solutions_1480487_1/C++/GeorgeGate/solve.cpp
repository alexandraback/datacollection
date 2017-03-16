/*
参数二分搜索 
*/
#include <fstream>
#include <iomanip>

using namespace std;

const long MAXN=300;
long score[MAXN],X,N;

bool search(long id,double p);

int main()
{
    const char filename[256]="A-large";
    char input[256]="data\\";
    char output[256]="data\\";
    strcat(strcat(input,filename),".in");
    strcat(strcat(output,filename),".out");
    ifstream fin (input);
    ofstream fout (output);
    
    long T;
    fin >>T;
    for (long k=1;k<=T;++k)
    {
        fin >>N;
        X=0;
        for (long i=0;i<N;++i)
        {
            fin >>score[i];
            X+=score[i];
        }
        fout <<"Case #" <<k <<": ";
        for (long j=0;j<N;++j)
        {
            double l=0.0,r=1.0,mid;
            for (long i=0;i<200;++i)
            {
                mid=l+0.5*(r-l);
                if (search(j,mid))
                {
                   l=mid;
                }else{
                      r=mid;
                }
            }
            fout <<setiosflags(ios::fixed) <<setprecision(6) <<r*100;
            if (j!=N-1) fout <<" ";
        }
        fout <<endl;
    }
    return 0;
}

bool search(long id,double p)
{
     double target=score[id]+p*X;
     double remain=1.0-p;
     for (long i=0;i<N;++i)
         if (i!=id)
         {
            if (target<=score[i]) continue;
            remain-=(target-score[i])/X;
            if (remain<0.0) return false;
         }
     return true;
}
