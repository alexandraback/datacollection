#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <iomanip>
#include <map>

using namespace std;

ifstream in;
ofstream out;

int T;
int N;
vector<double> Naomi;
vector<double>  Ken;


int main ()
{
    
    // Create input/Output Streams
    in.open("A.in");
    out.open("A.out");
    
    //Read N
    in >> T;
    
    for (int t = 0; t < T; t++)
    {
        
        //Read Data
        //M - Number of blocks
        in >> N;
        double input;
        
        for(int i = 0; i < N; ++i)
        {
            in >> input;
            Naomi.push_back(input);
        }
        
        for(int i = 0; i < N; ++i)
        {
            in >> input;
            Ken.push_back(input);
        }
        
        sort(begin(Naomi), end(Naomi));
        sort(begin(Ken), end(Ken));

        vector<double> NaomiV(Naomi);
        vector<double> KenV(Ken);
        
        //Deceitful War
        double dScore = 0;
        
        for(int i = 0; i < N; ++i)
        {
            //Kens best block
            double k = KenV[N-1-i];
            double n = NaomiV[N-1-i];
            
            if(k > n)
            {
                NaomiV.erase(NaomiV.begin());
            }
            else
            {
                ++dScore;
                NaomiV.erase(NaomiV.end()-1);
            }
        }
        
        
        
        //Normal War Play
        int score = 0;
        
        for(int i = 0; i < N; ++i)
        {
            double n = Naomi[i];
            
            int x = 0;
            for(; x < Ken.size(); ++x)
            {
                if(Ken[x] > n)
                    break;
            }
            
            if(x == Ken.size())
            {
                //Naomi Won
                ++score;
            
                //Remove Kens lowest index
                Ken.erase(Ken.begin());
            }
            else
            {
                //Ken Won
                Ken.erase(Ken.begin()+x);
            }
        }
        
        out << "Case #" << t+1 << ": " << dScore << " " << score << endl;
        cout << "Case #" << t+1 << ": " << dScore << " " << score << endl;
        
        Naomi.clear();
        Ken.clear();
    }
    
    return 0;
}
