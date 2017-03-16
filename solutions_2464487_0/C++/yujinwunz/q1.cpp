//#include <iostream>
#include <fstream>
using namespace std;

ifstream cin("input.in");
ofstream cout("output1.txt");

double pi = 3.14159265358979323;

long long cases;
long long radius, paint;

int main(){
    cin>>cases;
    for(int c = 1; c <= cases; c++){
        cin>>radius>>paint;
        int total = 0;
        while(true){
            long long needed = 2*radius + 1;
            if(needed > paint) break;
            total++;
            paint -= needed;
            radius += 2;

        }
        cout<<"Case #"<<c<<": "<<total<<"\n";
    }
}
