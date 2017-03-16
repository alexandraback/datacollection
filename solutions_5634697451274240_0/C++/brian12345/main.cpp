#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;
bool done(string str, int length)
{
    for (int i=0;i<length;i++)
    {

    }
}
int main()
{
    ifstream fin;
    fin.open("B-small-attempt0.in");
    if (!fin.is_open())
    {
        cout<<"error! "<<endl;
        return -1;
    }
    ofstream fout;
    fout.open("answer");
    int cases=0;
    fin>>cases;
    fin.get();
    string str;
    for (int i=0;i<cases;i++)
    {
        getline(fin,str);
        cout<<str<<endl;
        int count=0,times=0;
        while (count!=-1)
        {
            count=0;
            while (str[count]=='-')
            {
                str[count]='+';
                count++;
            }

            if (count!=0)
            {
                times++;
            }
            count=0;
            while (str[count]=='+')
            {
                count++;
            }
            if (count==str.length())
            {
                count=-1;
            }
            else if (count<str.length())
            {
                for (int j=0;j<count;j++)
                {
                    str[j]='-';
                }
                times++;
            }
        }
        fout<<"Case #"<<i+1<<": "<<times<<endl;
    }
}
