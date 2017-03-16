#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <iomanip>
#include <list>
using namespace std;
#define MAX_INT 2147483647

int solve(string s,int n){
    int invite=0;
    int stand=s[0]-'0';
    for(int shy=1;shy<=n;shy++){
        if(shy>stand){
            invite+=shy-stand;
            stand=shy+s[shy]-'0';
        }else{
            stand=stand+s[shy]-'0';
        }
    }
    return invite;
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
    string s;
    for(int i=0;i<t;i++){
        ifs>>a;
        ifs>>s;
        int m=solve(s,a);
        ofs<<"Case #"<<i+1<<": "<<m<<endl;
    }
    ifs.close();
    ofs.close();
    return 0;
}
