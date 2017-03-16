#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("B-small-attempt0.in");
    ofstream fout("B-small-attempt0.out");
    int n;
    fin>>n;
    for(int t=1;t<=n;t++){
        double C,F,X,ans=0,in=2;
        fin>>C>>F>>X;
        while((X-C)/in>X/(in+F)){
            ans+=C/in;
            in+=F;
        }
        ans+=X/in;
        char ansstr[500];
        sprintf(ansstr,"Case #%d: %.7lf",t,ans);
        fout<<ansstr<<endl;
    }
    return 0;
}
