#include<fstream>
#include<cstdio>
#include<iomanip>

using namespace std;


int main()
{
    ifstream in("A-small-attempt0.in");
    ofstream out("out.txt");
    int T;
    in>>T;
    for(int i=0;i<T;i++)
    {
        out<<"Case #"<<i+1<<": ";
        long A,B;
        in>>A>>B;
        double p[A];
        for(long j=0;j<A;j++)
        in>>p[j];
        //1st
        double stroke1;
        double all=1;
        for(long j=0;j<A;j++)
        all*=p[j];
        stroke1=all*(B-A+1)+(1-all)*(B-A+1+B+1);
        //2nd
        double stroke2;
        double min=999999;
        for(long j=1;j<=A;j++)
        {
            double alll=1;
            for(long k=0;k<A-j;k++)
            alll*=p[k];
            //out<<alll<<endl;
            double a=alll*(j+B-A+j+1)+(1-alll)*(j+B-A+j+1+B+1);
            if(a<min) min=a;//out<<min<<endl;}
        }
        stroke2=min;
        //3rd
        double stroke3=B+2;
        double stroke;
        if(stroke1<stroke2)
        {
            if(stroke1<stroke3) stroke=stroke1;
            else stroke=stroke3;
        }
        else
        {
            if(stroke2<stroke3) stroke=stroke2;
            else stroke=stroke3;
        }
        out<<fixed<<setprecision(6)<<stroke;
        out<<endl;
    }
    return 0;
}
    
