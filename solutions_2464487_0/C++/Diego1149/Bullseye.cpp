#include<iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main() {
    long long T, caso=0, r, t, imp, sumar, sum; //Opciones es la cantiad de respuestas posibles.
    string pos[100]; //Las distintas respuestas que hay.
    ofstream myfile;
    ifstream myReadFile;
    myReadFile.open("A-small.in");
    myfile.open ("Aoutput.txt");
    myReadFile>>T;
    while(T--) {
        myReadFile>>r;
        myReadFile>>t;
        sum=r*(r-1)/2;
        cout<<sum<<" ";
        imp=(-1+sqrt(1+8*(t+sum)))/(2);
        cout<<imp<<endl;
        sumar=(-1+sqrt(1+8*sum))/(2);
        cout<<sumar<<" ";
        caso++;
        myfile<<"Case #"<<caso<<": "<<(imp-sumar)/2<<endl;
    }
    myfile.close();
    return 0;
}
