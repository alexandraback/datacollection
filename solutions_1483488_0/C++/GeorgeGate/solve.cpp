#include <fstream>
#include <strstream>
#include <vector>

using namespace std;

const long MAXL=100;
vector<long> mUsed;

inline bool find(long m)
{
     for (long i=mUsed.size()-1;i>=0;--i)
         if (mUsed[i]==m) return true;
     return false;
}

int main()
{
    const char filename[256]="C-small-attempt0";
    char input[256]="data\\";
    char output[256]="data\\";
    strcat(strcat(input,filename),".in");
    strcat(strcat(output,filename),".out");
    ifstream fin (input);
    ofstream fout (output);
    
    long T,A,B,n,m,len;
    long long counter;
    char tmp[MAXL];
    fin >>T;
    for (long i=1;i<=T;++i)
    {
        fin >>A >>B;
        counter=0;
        for (n=A;n<B;++n)
        {
            memset (tmp,0,sizeof(tmp));
            mUsed.clear();
            ostrstream strout (tmp,MAXL);
            strout <<n <<n;
            len=strlen(tmp)/2;
            for (long j=len-1;j>0;--j)
            {
                istrstream strin (tmp+j,len);
                strin >>m;
                if (n<m&&m<=B && !find(m))
                {
                   ++counter;
                   mUsed.push_back(m);
                }
            }
        }
        fout <<"Case #" <<i <<": " <<counter <<endl;
    }
    return 0;
}

