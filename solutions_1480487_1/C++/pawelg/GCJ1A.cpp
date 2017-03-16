#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    int T, N, s, sum, k, sum2;
    vector<int> w;
    double res;
    ofstream os;
    
    os.setf(ios::fixed,ios::floatfield);            
    os.precision(6);
    
    ifstream fin("A-large.in");
    fin>>T;
    
    os.open("out.txt");
    
    for (int i = 0; i < T; i++)
    {
        os<<"Case #"<<i+1<<": ";
        //cout<<"Case #"<<i+1<<": ";
        w.clear();
        sum = 0;
        sum2 = 0;
        k = 0;
        fin>>N;
        for (int j = 0; j < N; j++)
        {
            fin>>s;
            w.push_back(s);
            sum += s;    
        }
        for (int j = 0; j < N; j++)
        {
            if (((double)(2 * sum) / (double) N) > w[j]) 
            {
                 k++;
                 sum2 += w[j];
            }
        }
        
        for (int j = 0; j < N; j++)
        {
            if (w[j] >= ((double) (2 * sum) / (double) N)) 
               res = 0.0;
            else
               res = 100.0 * (((double) ((double) sum + (double) sum2) / (double) k) - (double) w[j]) / ((double) sum);
            os<<res<<" ";
            //cout<<res<<" ";
        }
        os<<endl;
        //cout<<endl;
    }
    os.close();
    
    return 0;
}
