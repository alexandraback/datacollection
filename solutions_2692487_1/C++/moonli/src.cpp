#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include<algorithm>
using namespace std;

int A, N;
vector<int> motes;

int maxMote = 1e6;

int mem[1000002][102];


int calc(int mote, int i){
    if(mote>maxMote) return 0;
    if(mem[mote][i]>=0) return mem[mote][i];
    if(i>=N) return 0;

    int res = 0;
    if(mote>motes[i]){
        res = calc(mote+motes[i], i+1);
    }else if(mote-1>0){
        res = calc(mote+mote-1, i) + 1;

        int tmp = calc(mote, i+1) + 1;

        if(tmp<res) res=tmp;
    }else{
        return N-i;
    }

    mem[mote][i]=res;

    return res;
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
        ss>>A>>N;
        memset(mem, -1, sizeof(mem));

        motes.clear();
        file.getline(line, 1024);
        stringstream ss1(line);
        for(int i=0;i<N;i++){
            int tmp;
            ss1>>tmp;
            motes.push_back(tmp);
        }

        sort(motes.begin(), motes.end());

        int cnt = calc(A, 0);

        cout<<"Case #"<<c<<": "<<cnt<<endl;
    }
    return 0;
}
