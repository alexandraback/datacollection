#include <iostream>
#include <fstream>
using namespace std;



int main (){
    ifstream in("Bs.in");
    ofstream out("bsoutput.txt");
    int testcases;
    in >> testcases;
    int testcasses = testcases;
    while (testcasses -->0){
        int N;
        in>>N;
        bool hoogte[3000];
        for(int i=0;i<3000;i++){
            hoogte[i]=false;
        }
        for(int i=0;i<2*N*N-N;i++){
            int j;
            in>>j;
            hoogte[j]=!hoogte[j];
        }
        out<<"Case #"<<testcases-testcasses<<": ";
        for(int i=0;i<3000;i++){
            if(hoogte[i])out<<i<<" ";
        }
        out<<endl;
    }
    return 0;
}
