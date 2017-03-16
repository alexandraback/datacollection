#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool check(int k, int ar[])
{
    for(int i=0; i<k; i++)
    {
        if(ar[i]>1) return false;
    }
    return true;
}

int min_time(int k, int ar[])
{
    if(check(k,ar)) return 1;
    int temp1=0,z;
    int max1=0;
    int ar1[k];
    int ar2[k+1];
    for(int i=0; i<k; i++) ar1[i] = ar[i]-1;
    for(int i=0; i<k; i++) ar2[i] = ar[i];
    for(int i=0; i<k; i++)
    {
        if(ar2[i]>=max1) {max1=ar2[i]; temp1=i;}
    }
    z = ar2[temp1]/2;
    ar2[temp1] -= z;
    ar2[k] = z;
    return min(1+min_time(k,ar1), 1+min_time(k+1,ar2));
}

int main()
{
    ifstream in;
    ofstream out;
    in.open("B-small-attempt0.in");
    out.open("output.txt");
    int T,D,P[1001];
    in>>T;
    for(int i=0; i<T; i++)
    {
        in>>D;
        for(int j=0; j<D; j++) in>>P[j];
        out<<"Case #"<<i+1<<": "<<min_time(D,P)<<endl;
    }
}
