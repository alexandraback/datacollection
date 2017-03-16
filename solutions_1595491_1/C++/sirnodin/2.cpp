#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define REP(i,n) for(int i = 0;i<(n);++i)

using namespace std;

int N,T,S,P;
int ans;
int temp;

int main()
{
    ifstream fin("B-large.in");
    ofstream fout("B-large.out");

    fin>>N;

    REP(C,N)
    {
        ans = 0;
        fin>>T>>S>>P;
        if(P==0)
        {
            ans+=T;
            REP(i,T)
            {
                fin>>temp;
            }
        }
        else if(P==1)
        {
            REP(i,T)
            {
                fin>>temp;
                if(temp>0)
                    ans++;
            }
        }
        else
        {
            int min = P+P-2+P-2;
            REP(i,T)
            {
                fin>>temp;
                if(temp>=min+2)
                    ans++;
                else if(temp>=min && S-->0)
                    ans++;
            }
        }
        fout<<"Case #"<<C+1<<": "<<ans<<endl;
    }

    return 0;
}
