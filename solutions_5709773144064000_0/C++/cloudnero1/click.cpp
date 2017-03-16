#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <string>
#include <stdlib.h>
using namespace std;

int main(){
    
    //ifstream infile("a.txt");
    ifstream infile("B-small-attempt2.in");
    if(!infile){
        cerr << "error read file";
        return -1;
    }
    ofstream out("bsmall.in");
    int t;
    infile >> t;
    for(int i = 1; i <= t; i++){
        double c, f, x, times = 0.0, speed = 2.0;

        infile >> setprecision(16) >> c >> f >> x;
        
        while(1){
            if(x / speed <= (x / (speed + f) + c / speed))
                break;
            times += c / speed;
            speed += f;
        }
        times += x / speed;
        //out << x << " " <<speed << "\n";
        char *str = new char[30];
        memset(str, 0, sizeof(str));
        sprintf(str, "%.7f", times);
        out << "Case #" << i << ": " << str << "\n";
    }
    infile.close();
    out.close();
    return 0;
}
