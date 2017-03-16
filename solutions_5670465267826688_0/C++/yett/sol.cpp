#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <iomanip>
#include <list>
#include <cmath>
using namespace std;

int mat[4][4]={{1,2,3,4},{2,-1,4,-3},{3,-4,-1,2},{4,3,-2,-1}};

int mul(int a,int b){
    int sign=1;
    if(a<0) {
    a=-a;sign=-sign;
    }
    if(b<0) {
    b=-b;sign=-sign;
    }
    return sign*mat[a-1][b-1];
}

bool solve(string s,int l,int m){
    int u=1;
    int ar[l];
    for(int i=0;i<l;i++){
        switch(s[i]){
            case 'i':ar[i]=2;break;
            case 'j':ar[i]=3;break;
            case 'k':ar[i]=4;break;
        }
        u=mul(u,ar[i]);
    }
    int uall=1;
    for(int i=0;i<m%4;i++){
        uall=mul(uall,u);
    }
    if(uall!=-1) return false;
    int left;
    int maxlen=m>4?4:m;
    int cha=1;
    for(left=0;left<l*maxlen;left++){
        cha=mul(cha,ar[left%l]);
        if(cha==2) break;
    }
    if(cha!=2) return false;
    cha=1;
    for(int i=0;i<l*maxlen;i++){
        cha=mul(ar[l-1-i%l],cha);
        if(cha==4){
            if(i+left+2<m*l) return true;
            else return false;
        }
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
    ofstream ofs("result.txt");
    ifs>>t;
    for(int i=0;i<t;i++){
        string s;
        ifs>>a>>b>>s;
        bool bo=solve(s,a,b);
        string text=bo?"YES":"NO";
        ofs<<"Case #"<<i+1<<": "<<text<<endl;
    }
    ifs.close();
    ofs.close();
    return 0;
}
