#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");

#define cin in
#define cout out

int main()
{
    int t;
    cin>>t;
    for (int i=0;i<t;i++)
    {
        cout<<"Case #"<<i+1<<": ";
        int a,b,k;
        cin>>a>>b>>k;
        int sch=0;
            for (int j=0;j<a;j++)
                for (int h=0;h<b;h++)
                    if ((j&h)<k)
                        sch++;
        cout<<sch<<endl;

    }
}