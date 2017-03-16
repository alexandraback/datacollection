#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <iomanip>
#include <list>
using namespace std;

bool solve(int a,int b,int c){
    int l=b>c?b:c;
    int w=b<c?b:c;
    if(l<a) return false;
    if(l*w%a!=0) return false;
    if(a<3) return true;
    if(a>6) return false;
    switch(a){
        case 3:return w>1;
        case 4:return w>2;
        case 5:return w>2;
        case 6:return w>3;
    }
    return false;
}

int main(int argc, char* argv[]){
    int t,a,b,c;
    ifstream ifs;
    if(argc!=2){
        cout<<"file not found"<<endl;
        return 1;
    }
    ifs.open(argv[1]);
    ofstream ofs("result.out");
    ifs>>t;
    for(int i=0;i<t;i++){
        ifs>>a>>b>>c;
        int num=solve(a,b,c);
        string text=num?"GABRIEL":"RICHARD";
        ofs<<"Case #"<<i+1<<": "<<text<<endl;
    }
    ifs.close();
    ofs.close();
    return 0;
}
