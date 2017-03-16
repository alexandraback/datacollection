#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

int reqd(int k, int ar[])
{
    int total = 0;
    int fren = 0;
    for(int i=0; i<k; i++)
    {
        if(i>total)
        {
            fren += i-total;
            total += ar[i] + (i-total);
        }
        else total = total + ar[i];
    }
    return fren;
}

int main()
{
    ifstream in;
    ofstream out;
    string s;
    int ar[2000];
    char c,x;
    in.open("A-small-attempt0.in");
    out.open("output.txt");
    int T,k;
    in>>T;
    for(int i=0; i<T; i++)
    {
        in>>k;
        getline(in,s);
        string str = s.c_str();
        for(int j=0; str[j+1]!=0 && str[j+1]!=10; j++) ar[j] = str[j+1]-'0';
        out<<"Case #"<<i+1<<": "<<reqd(k+1,ar)<<endl;
    }
}
