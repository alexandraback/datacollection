#include <iostream>
#include <fstream>
using namespace std;



int main (){
    ifstream in("Al.in");
    ofstream out("aloutput.txt");
    int testcases;
    in >> testcases;
    int testcasses = testcases;
    char k=in.get();
    while (testcasses -->0){
        char eind[3000];
        for(int i=0;i<3000;i++){
            eind[i]='.';
        }
        int i=0;
        char eerste='A';
        int imin=1500;
        int imax=1501;
        while(true){
            k=in.get();
            if(k=='\n')break;
            if(k>=eerste){
                eind[imin]=k;
                imin--;
                eerste=k;
                continue;
            }
            eind[imax]=k;
            imax++;
            i++;
        }
        out<<"Case #"<<testcases-testcasses<<": ";
        for(int i=0;i<3000;i++){
            if(eind[i]!='.'){
                out<<eind[i];
            }
        }
        out<<endl;
    }
    return 0;
}
