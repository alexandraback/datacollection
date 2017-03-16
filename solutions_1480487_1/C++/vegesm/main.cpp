#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

double szamol(vector<int>& p, double m, int sum)
{
    double ret=0;
    for(int i=0; i<p.size(); i++)
    {
        if(m>p[i]) ret+=m-p[i];
    }
    return ret-sum;
}

void megold(istream& in, ostream &out)
{
    int n, sum=0;
    in>>n;
    vector<int> p;
    for(int i=0;i<n;i++)
    {
        int t;
        in>>t;
        p.push_back(t);
        sum+=t;
    }
    //out<<sum<<endl;
    /*for(int i=0; i<n; i++)
    {
        double r=2*sum/((double)n);
        r=(r-p[i])/sum*100;
        out<<(r<0? 0: r)<<' ';
    }*/
    for(int i=0; i<n; i++)
    {
        double a=0, b=2*sum;
        int it=0;
        while(abs(b-a)>0.00000001 && it<=1000) {
            double c=(a+b)/2.0;
            double cy=szamol(p, c, sum);
            //cout<<cy<<endl;
            if(cy<0) a=c;
            else b=c;

            it++;
        }
        a=(a-p[i])/((double)sum);
        if(a<0) a=0;
        out<<a*100<<' ';
    }
}

int main()
{
    ifstream in("A-large.in");
    ofstream out("reality.out");
    int n;
    in>>n;
    out<<setprecision(9);
    for(int i=1; i<=n; i++)
    {
        out<<"Case #"<<i<<": ";
        megold(in, out);
        out<<endl;
    }
    in.close();
    out.close();
    return 0;
}
