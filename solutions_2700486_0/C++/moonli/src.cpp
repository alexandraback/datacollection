#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<cmath>
using namespace std;

typedef long long ll;

ll cnm(ll n, ll m){
    if(m==0) return 1;
    if(n==m) return 1;
    if(n<m) return 0;

    return cnm(n-1, m) + cnm(n-1,m-1);
}


int count(int level){
    if(level%2==0) return -1;

    return (1+level)*level/2;
}


bool inscope(int X, int Y, int level){
    int levelX = level-Y;
    if(levelX<=0) return false;

    if(Y%2==0){
        if(X%2!=0) return false;
        if(abs(X)>(levelX+1)/2) return false;
    }else{
        if(X%2==0) return false;
        if(abs(X)>levelX/2) return false;
    }

    return true;
}

bool inner(int X, int Y, int level){
    if(level-1==0) return ((X==0)&&(Y==0));

    return inscope(X,Y,level-1);
}



int main(int argc, char* argv[]){
    if(argc!=2){
        printf("%s data-file\n", argv[0]);
        return 0;
    }

    fstream file(argv[1]);
    char line[1024];
    file.getline(line, 1024);
    int T = atoi(line);

    for(int c=1;c<=T;c++){
        file.getline(line, 1024);
        stringstream ss(line);
        int N, X, Y;
        ss>>N>>X>>Y;

        double res = 0;

        //find max level
        int level = 1;
        while(count(level)<N) level+=2;

        if(level==1){
            if(X!=0||Y!=0){
                res = 0;
                cout<<"Case #"<<c<<": "<<res<<endl;
                continue;
            }
            res = 1;
            cout<<"Case #"<<c<<": "<<res<<endl;
            continue;
        }


        if(!inscope(X, Y, level)){
            res = 0;
            cout<<"Case #"<<c<<": "<<res<<endl;
            continue;
        }

        if(inner(X,Y,level)){
            res = 1;
            cout<<"Case #"<<c<<": "<<res<<endl;
            continue;
        }


        int left = N - count(level-2);
//        cout<<"N:"<<N<<" level:"<<level<<" left:"<<left<<endl;

        if(left - level + 1 > Y){
            res = 1;
            cout<<"Case #"<<c<<": "<<res<<endl;
            continue;
        }

        if(left <= Y){
            res = 0;
            cout<<"Case #"<<c<<": "<<res<<endl;
            continue;
        }

        for(int i=Y+1;i<level;i++){
            res += cnm(left, i);
        }

        double base = 0;

        int minl = left - (level-1);
        if(minl<0) minl=0;
        int maxl = min(left, level-1);

        for(int i=minl; i<=maxl; i++) base += cnm(left, i);

        res /= base;

        cout<<"Case #"<<c<<": "<<res<<endl;

    }
    return 0;
}
