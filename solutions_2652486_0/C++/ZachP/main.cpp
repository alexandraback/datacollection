#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cmath>
#include <vector>
#include <algorithm>

#define MAX 100
#define test(a) cout << "TEST " << a << endl;
#define go(a,b) for(int a=0; a<b; a++)
#define case(a) fout << "Case #"<< a << ": " <<
using namespace std;
ofstream fout ("output.txt");
ifstream fin ("input.txt");

void done(int a){
    int e, r, n;
    bool blah=false;
    fin >> e >> r >> n;
    vector<int> energy(n, e);
    vector<int> used(n, 0);
    vector<int> importance (n);
    go(b, n){
        fin >> importance[b];
    }
    int total=0;
    int max;
    int index;
    do{
        max=0;
    go(b, n){
        if(importance[b]>max&&used[b]==0){
            max=importance[b];
            index=b;
        }
    }
    total+=energy[index]*importance[index];
    cout << energy[index] << " * " << importance[index] << endl;
    used[index]=1;
    go(b, n){
        if(b!=0){
        if(index-b>=0){
            if(energy[index-b]==e){
                energy[index-b]-=energy[index]-min(b*r, energy[index]);
            }
            else{
                energy[index-b]-=energy[index];
                if(energy[index-b]<0)energy[index-b]=0;
            }
            //cout << energy[index-b] << "-=" << (e-((b)*r)) << endl;
        }
        if(index+b<n){
            if(energy[index+b]==e){
                energy[index+b]-=energy[index]-min(b*r, energy[index]);
            }
            else{
                energy[index+b]-=energy[index];
                if(energy[index+b]<0)energy[index+b]=0;
            }
            //cout << energy[index+b] << "-=" << (e-((b)*r)-energy[index]) << endl;
        }
        }
    }
    blah=false;
    go(b, n){
       if(used[b]==0){
        blah=true;
       }
    }
    }while(blah);

    case(a) total << endl;
    return;


}



/*void done(int a){
    int e, r, n, total;
    fin >> e >> r >> n;
    vector<int> energy(n);
    go(b, n){
        fin >> importance[b];
    }
    if(n==1){
        total=importance[0]*e;
    }
    if(e==r){
        total=0;
        go(b, n){
            total+=importance[b]*e;
        }
    }
    if(r==1){
        total=0;
    }
    case(a) total << endl;


}*/

int main()
{
    int cases;
    fin >> cases;
    go(a, cases){
        done(a+1);
    }
}
