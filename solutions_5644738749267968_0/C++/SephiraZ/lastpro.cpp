#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
    int num;
    int size = 0;
    int y=0,z=0;
  ifstream myfile ("D-small-attempt1.in");
  ofstream myfile2 ("output.txt");
    myfile >> num;
    for(int aa=1;aa<=num;aa++)
{
    myfile >> size;
    //cout << size << endl;
    y =0;
    z =0;
    double a[size];
    double b[size];
    double c[size];
    double d[size];
    for(int i =0;i<size;i++)
    {
    myfile >> a[i];
    c[i] = a[i];
    }
    for(int i=0;i<size;i++)
    {
    myfile >> b[i];
    d[i] = b[i];
    }
    sort(a,a+size);
    sort(b,b+size);
        sort(c,c+size);
    sort(d,d+size);
    /*    for(int i=0;i<size;i++)
    myfile2 << a[i] << " ";
    myfile2 << endl;
        for(int i=0;i<size;i++)
    myfile2 << b[i] << " ";
    myfile2 << endl;*/
    
    for(int i=0;i<size;i++)
    {
    for(int j=0;j<size;j++)
            {
            if(d[i] < c[j])
                 {
            d[i] = 0;
            c[j] = 0;
            y++;
            break;
                 }
            }
    }
    //
    for(int i=0;i<size;i++)
    {
    for(int j=0;j<size;j++)
            {
            if(a[i] < b[j])
                 {
            b[j] = 0;
            a[i] = 0;
            z++;
            break;
                 }
            }
    }
    myfile2 << "Case #" << aa << ": "<< y << " " << size-z << endl;
}
    //system("PAUSE");
    return EXIT_SUCCESS;
}
