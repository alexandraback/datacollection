#include <fstream>
using namespace std;
ifstream f("problemA.in");
ofstream g("problemA.out");
int T,i,j,N,n,ok,value,length,start,stop,x;
int A[101];
char c;
int main()
{
    f>>T;
    for(i=1;i<=T;i++)
    {
        value=0;
        N=0;ok=1;
        do
        {
            f>>noskipws>>c;
            x=int(c);
            if(x!=10)
            {
                if(x==97 || x==101 || x==105 || x==111 || x==117)
                A[++N]=0;
                else if(x==32)
                ok=0;
                else
                A[++N]=1;
            }
        }
        while(ok);
        f>>n;
        for(start=1;start<=N-n+1;start++)
        {
            for(stop=start+n-1;stop<=N;stop++)
            {
                ok=1;
                for(j=start;j<stop && ok;j++)
                {
                    if(A[j]==1 && A[j+1]==1)
                    {
                        length=1;
                        while(A[j]==A[j+1] && j+1<=stop)
                        {
                            ++j;
                            ++length;
                        }
                        if(length>=n)
                        {
                            ok=0;
                            value++;
                        }
                    }
                }
            }
        }
        g<<"Case #"<<i<<": "<<value<<"\n";
    }
    return 0;
}
