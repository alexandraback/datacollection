#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int T;
    double D, x_i, t_i, a_i;
    double dist;
    double deltaT;
    double vel;
    int N, A;
    vector<double> distances;
    vector<double> times;
    
    ofstream os;
    
    ifstream fin("B-small-attempt1.in");
    os.open("out.txt");
    
    os.precision(7);
    os.setf(ios::fixed,ios::floatfield);
    
    fin>>T;
    
    for (int i = 0; i < T; i++)
    {
        fin>>D;
        fin>>N;
        fin>>A;
        //cout<<i<<" "<<D<<" "<<N<<" "<<A<<endl;
        distances.clear();
        times.clear();
        
        os<<"Case #"<<i+1<<": "<<endl;
        
        for (int j = 0; j < N; j++)
        {
            fin>>t_i;
            fin>>x_i;
            distances.push_back(x_i);
            times.push_back(t_i);
        }
        
        for (int j = 0; j < A; j++)
        {
            fin>>a_i;
            
            if (N == 1)
            {
                deltaT = sqrt(2.0 * D / a_i);
                os<<deltaT<<endl;
            }
            
            if (N == 2)
            {
               vel = (distances[1] - distances[0]) / (times[1] - times[0]);
               deltaT = sqrt(2.0 * D / a_i);
               if (distances[0] + deltaT * vel > D)
                  os<<deltaT<<endl;
               else
                  os<<(D - distances[0]) / vel<<endl;
            }
        }
    }
    
    os.close();
    
    return 0;
}
