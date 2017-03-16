#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;

int main(){

    int T;
    ifstream din;
    ofstream dout;

    din.open("B-small-attempt0.in", ifstream::in);
    dout.open("B-small-attempt0.out", ofstream::out);

    din>>T;
    cout<<T<<endl;
    for(int t=1; t<=T; t++){
        int N;
        din>>N;
        map<int, int> cnt;
        for(int i=0; i<2*N-1; i++){
            for(int j=0; j<N; j++){
                int num;
                din>>num;
                cnt[num]++;
            }
        }
        vector<int> vals;
        for(map<int,int>::iterator it=cnt.begin(); it!=cnt.end(); it++){
            int c = it->second;
            if(c%2 ==1)
                vals.push_back(it->first);
        }
        sort(vals.begin(), vals.end());
        dout<<"Case #"<<t<<":";
        for(vector<int>::iterator it=vals.begin(); it!=vals.end(); it++)
            dout<<" "<<(*it);
        dout<<endl;
    }

    din.close();
    dout.close();
    return 0;
}
