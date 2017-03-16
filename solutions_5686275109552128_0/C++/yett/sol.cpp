#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <iomanip>
#include <list>
using namespace std;


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
        vector<int> ar;
        ifs>>a;
        int max=0;
        for(int j=0;j<a;j++){
            ifs>>b;
            max=max>b?max:b;
            ar.push_back(b);
        }
        int min=1000;
        for(int eat=1;eat<=max;eat++){
            int sp=0;
            for(int j=0;j<ar.size();j++){
                sp+=(ar[j]-1)/eat;    
            }
            min=min<eat+sp?min:eat+sp;
        }
        ofs<<"Case #"<<i+1<<": "<<min<<endl;
    }
    ifs.close();
    ofs.close();
    return 0;
}
