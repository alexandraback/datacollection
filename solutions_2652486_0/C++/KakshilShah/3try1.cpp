#include <cstdio>
#include <cstring>
#include <algorithm>
#include<iostream>
#include<fstream.h>
using namespace std;
//Define Global Variables Here
int main() {
   ofstream myfile;
    myfile.open ("3newsma33l66l1.txt");
        myfile<<"Case #1:"<<endl;
        
    int t,r,m,n,k;
    int sub[8];
    cin>>t;
    cin>>r>>m>>n>>k;
    int count = 0;
    for (int q = 0; q<r; q++) {
        int check[7];
        int max = -1;
        for (int y=0; y<7; y++) {
            cin>>check[y];
        }
        for (int k = 0; k<7; k++) {
            max = check[k]>max?check[k]:max;
        }
        
        
        
        switch (max) {
            case 100:
                myfile<<"552"<<endl;
                break;
            case 60:
                myfile<<"435"<<endl;
                break;
            case 48:
                myfile<<"443"<<endl;
                break;
            case 50:
                myfile<<"552"<<endl;
                break;
            case 32:
                myfile<<"442"<<endl;
                break;
            case 18:
                myfile<<"332"<<endl;
                break;
            case 40:
                myfile<<"452"<<endl;
                break;
            case 25:
                myfile<<"553"<<endl;
                break;
            case 30:
                myfile<<"352"<<endl;
                break;
            case 45:
                myfile<<"533"<<endl;
                break;
            case 8:
                myfile<<"222"<<endl;
                break;
            case 80:
                myfile<<"544"<<endl;
                break;
            case 125:
                myfile<<"555"<<endl;
                break;
            case 64:
                myfile<<"444"<<endl;
                break;
            case 20:
                myfile<<"522"<<endl;
                break;
            default:
                myfile<<"234"<<endl;
                break;
        }
        
    }

    
    return 0;
}
