#include <cstdio>
#include <cstring>
#include <algorithm>
#include<iostream>
#include<fstream.h>
using namespace std;
//Define Global Variables Here

long long store[1048576];
long long str[1048576][20];
int main() {
   ofstream myfile;
   myfile.open ("1small.txt");
    int tc; scanf("%d\n", &tc);
    for(int g = 0; g < tc; g++) {
        long double r;
        long double t;
        long long count = 0;
        cin>>r;
        cin>>t;
        while (t>=0) {
            t = t - (2*r + 1);
            r+=2;
            count++;
        }
        count--;
        myfile<<"Case #"<<g+1<<": "<<count<<endl;
    }
    return 0;
}

