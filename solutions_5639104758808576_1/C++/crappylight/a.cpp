#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
fstream inputf("A-large.in");
fstream outputf("output.txt");

string cc;
int n,i,j,k,l,x,cases;
int main(){
    inputf >> cases;
    for (int cur = 1; cur <= cases; cur++) {
        inputf >> n;
        inputf >> cc;
        x = 0;
        l = 0;
        for (int i=0;i<=n;i++)
        {
            if (l+x<i) x = i-l;
            l += cc[i]-'0';
        }
        outputf << "Case #" << cur << ": " << x << endl;
    }
    inputf.close();
    outputf.close();
}
