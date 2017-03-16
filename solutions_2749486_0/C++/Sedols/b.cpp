#include<iostream>
#include<fstream>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<sstream>
using namespace std;

int main()
{
    ifstream in("in.txt");
    ofstream out("out.txt");
    int T;
    in >> T;
    for(int t = 1; t <= T; t++)
    {
        int x, y;
        in >> x >> y;
        string ret = "";
        if(y > 0)
        {
            for(int i = 0; i < y; i++)
            {
              ret += "SN";   
            }
        }
        else
        {
            for(int i = 0; i < -y; i++)
            {
              ret += "NS";   
            }
        }
        if(x > 0)
        {
            for(int i = 0; i < x; i++)
            {
              ret += "WE";   
            }
        }
        else
        {
            for(int i = 0; i < -x; i++)
            {
              ret += "EW";   
            }
        }
        
       out<<"Case #"<<t<<": "<<ret<<endl;   
    }
}
