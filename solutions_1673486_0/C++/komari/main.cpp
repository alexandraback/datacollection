/*
PROG: A
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <iomanip>
using namespace std;

#define SUBMIT
#define _DSP(X) X
#   define DV(Var) #Var<<"="<<Var<<' '
#ifdef SUBMIT
    ofstream fout ("A.out");ifstream fin ("A.in");
#   define cin fin
#   define cout fout
#endif

const int MAXN=100000;
double unp[MAXN];

int main()
{
    int T;
    cin>>T;cin.ignore();
    for(int t=1;t<=T;++t)
    {int i;
        int A,B;
        cin>>A>>B;
        for(i=0;i<A;++i)
        {
            cin>>unp[i];
        }
        std::partial_sum(unp,unp+A,unp,std::multiplies<double>());

        _DSP(std::copy(unp,unp+A,std::ostream_iterator<double,char>(cerr,","));
        cerr<<endl;)

        double ans=B+2;
        for(i=0;i<A;++i)
        {
            double temp=B-A+2*i+1+(1-unp[A-i-1])*(B+1);
            if(ans>temp)ans=temp;
            _DSP(cerr<<DV(temp)<<endl;)
        }

        cout<<"Case #"<<t<<": "
            <<setprecision(6)<<fixed<<ans<<endl;
    }

    return 0;
}
