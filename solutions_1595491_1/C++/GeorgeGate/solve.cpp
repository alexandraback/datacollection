#include <fstream>

using namespace std;


int main()
{
    const char filename[256]="B-large";
    char input[256]="data\\";
    char output[256]="data\\";
    strcat(strcat(input,filename),".in");
    strcat(strcat(output,filename),".out");
    ifstream fin (input);
    ofstream fout (output);
    
    long T,N,S,p;
    fin >>T;
    for (long i=1;i<=T;++i)
    {
        fin >>N >>S >>p;
        long tj,ans=0;
        for (long j=0;j<N;++j)
        {
            fin >>tj;
            switch (tj%3)
            {
                   case 1:
                          if ((tj+2)/3>=p) ++ans;
                          break;
                   case 2:
                          if ((tj+1)/3>=p) 
                             ++ans;
                          else if ((tj+4)/3>=p)
                               if (S>0)
                               {
                                  --S;++ans;
                               }
                          break;
                   case 0:
                          if (tj/3>=p)
                             ++ans;
                          else if (tj>=3 && (tj+3)/3>=p)
                               if (S>0)
                               {
                                  --S;++ans;
                               }
                          break;
            }
        }
        fout <<"Case #" <<i <<": " <<ans <<endl;
    }
    return 0;
}

