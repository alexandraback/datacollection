#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int Solver(int Emax,int E,int R,int *energy_act,int N,int n,int val_prev,int *maxval)
{
    if(n == N-1)
    {
        int val_curr = E*energy_act[n];
        if(val_curr + val_prev> *maxval)
        {
            *maxval = val_prev + val_curr;
        }
        return val_curr;
    }
    int val_curr;
    for(int i=0;i<=E;i++)
    {
        val_curr = i * energy_act[n];
        int E_after = (E-i+R > Emax)? Emax:E-i+R;
        val_curr += Solver(Emax,E_after,R,energy_act,N,n+1,val_prev+val_curr,maxval);
        if(val_curr+val_prev > *maxval)
            *maxval = val_curr+val_prev;
    }
    return val_curr;
}

int main()
{
    ifstream input("B-small-attempt1.in");
    ofstream output("B-small.out");
    int T;
    input>>T;
    int energy_act[10];
    for(int c=1;c<=T;c++)
    {
        int E,R,N;
        input>>E>>R>>N;
        for(int i=0;i<N;i++)
        {
            input>>energy_act[i];
        }
        int maxval = 0;
        Solver(E,E,R,energy_act,N,0,0,&maxval);
        output<<"Case #"<<c<<": "<<maxval<<endl;
    }
    return 0;
}
