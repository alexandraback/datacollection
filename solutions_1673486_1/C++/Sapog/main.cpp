#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <utility>
#include <string>

class Found{};

using namespace std;

int main()
{
    ifstream in("C:\\Users\\Olexandr\\Desktop\\A-large.in");
    ofstream out("C:\\Users\\Olexandr\\Desktop\\output.txt");
    int T;
    in>>T;


    for(int t=0; t<T; t++)
    {
        out<<"Case #"<<(t+1)<<": ";
        int A,B;
        in>>A>>B;
        vector<double> prob(A), cProb(A+1);
        cProb[0]=1.f;
        for(int i=0; i<A; i++)
        {
            in>>prob[i];
            cProb[i+1]=cProb[i]*prob[i];
        }
        double val=double(B)+2;

        for(int i=0; i<=A; i++)
        {
            double v=cProb[i]*(B-A+1 +2*(A-i))+(1.f-cProb[i])*(B-A+1 +2*(A-i)+ B+1);
            val=min(val, v);
        }
        out.precision(6);
        out<<fixed;
        out<<val<<endl;
    }
    system("pause>nul");
    return 0;
}