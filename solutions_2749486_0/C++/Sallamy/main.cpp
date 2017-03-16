#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream in;
    in.open("B-small-attempt0 (1).in");
    ofstream out;
    out.open("out.txt");
    int t,x,y;
    string s;
    in>>t;
    for(int o=1; o<=t; o++)
    {
        s="";
        in>>x>>y;
        if(x>0)
        {
            for(int i=0; i<x; i++)
            {
                s+="WE";
            }
        }
        else
        {
            for(int i=0; i>x; i--)
            {
                s+="EW";
            }
        }
        if(y>0)
        {
            for(int i=0; i<y; i++)
            {
                s+="SN";
            }
        }
        else
        {
            for(int i=0; i>y; i--)
            {
                s+="NS";
            }
        }

        out<<"Case #"<<o<<": "<<s<<endl;
    }
    return 0;
}
