#include <iostream>
#include<fstream>
using namespace std;

double p[100000];
double rate[100000];
double corrate[100000];

int main()
{
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");
    int t;
    in>>t;

    for(int q=0;q<t;q++){
        int A,B;


        double min=10000000;

        in>>A>>B;

        p[0]=1;
        rate[0]=0;
        corrate[0]=1;
        for(int i=1;i<=A;i++){
            in>>p[i];
            rate[i]=corrate[i-1]*(1-p[i]);
            corrate[i]=corrate[i-1]-rate[i];

        }

        min=B+2;

        for(int i=0;i<=A;i++){
            int cor=2*(A-i)+B-A+1;
            int wro=2*(A-i)+2*B-A+2;

            double nw=cor*corrate[i]+wro*(1-corrate[i]);
            if(nw<min) min=nw;
            cout<<nw<<endl;
        }
        out.precision(7);
        out<<"Case #"<<q+1<<": "<<min<<endl;




    }
}
