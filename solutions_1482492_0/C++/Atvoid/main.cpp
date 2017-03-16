#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>


using namespace std;

ifstream fin;
ofstream fout;
double t[2002];
double x[2002];

double A[2002];

void solve(int num)
{
    double length;
    int n,total;
    fin>>length>>n>>total;

    t[0] = x[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        fin>>t[i]>>x[i];
    }
    for (int i = 0; i < total; ++i)
    {
        fin>>A[i];
    }

    fout<<"Case #"<<num<<": "<<endl;
    for (int i = 0; i < total; ++i)
    {
        double time = 0;
        double speed = 0;
        double len = 0;
        double acc = A[i];
        for (int j = 1; j <= n; ++j)
        {
            double otherSpeed;
            if (t[j]-t[j-1]==0)
                continue;
            else
                otherSpeed = (x[j]-x[j-1])/(t[j]-t[j-1]);
            double tt = ((otherSpeed-speed)+sqrt((speed-otherSpeed)*(speed-otherSpeed)-2*acc*(len-x[j-1])))/acc;


            if (tt>t[j])
            {
                if (x[j]>=length)
                {
                    time = time + (-speed+sqrt(speed*speed-2*acc*(len-length)))/acc;
//                cout<<setiosflags(ios::fixed)<<setprecision(6)<<sqrt(speed*speed-2*acc*(len-length))<<endl;
                    break;
                }
                time = t[j];
                len = len + speed*(t[j]-t[j-1]) + acc*(t[j]-t[j-1])*(t[j]-t[j-1])/2;
                speed = speed + acc*(t[j]-t[j-1]);
            }
            else
            {
                if (x[j]>=length)
                {
                    time = time + (length-x[j-1])/otherSpeed;
                    break;
                }
                time = t[j];
                len = x[j];
                speed = otherSpeed;
            }
        }
        fout<<setiosflags(ios::fixed)<<setprecision(7)<<time<<endl;
//        cout<<endl;
    }

}

int main()
{
    int total;
    fin.open("input.txt");
    fout.open("output.txt");

    fin>>total;
    for (int i=1;i<=total;++i)
    {
        solve(i);
    }

    fin.close();
    fout.close();
    return 0;
}
