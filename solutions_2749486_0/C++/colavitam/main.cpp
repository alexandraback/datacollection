#include <iostream>
#include <fstream>
#include <vector>
#define LEN 501

using namespace std;
int rat(int a) {
    return a+250;
}
int main() {
    ifstream in("str.in");
    ofstream out("str.out");
    int T;
    in>>T;
    pair<int,int> map[LEN][LEN];
    int len[LEN][LEN];
    for(int i=0;i<LEN;i++)
        for(int i2=0;i2<LEN;i2++)
            len[i][i2]=100000;
    vector<pair<int,int> > toAdd;
    toAdd.push_back(pair<int,int>(rat(0),rat(0)));
    len[rat(0)][rat(0)]=1;
    while(!toAdd.empty()) {
        pair<int, int> at=toAdd.back();
        toAdd.pop_back();
        int length=len[at.first][at.second];
        if(at.first-length>0 && length+1<len[at.first-length][at.second]) {
            map[at.first-length][at.second]=at;
            len[at.first-length][at.second]=length+1;
            toAdd.push_back(pair<int,int>(at.first-length,at.second));
        }
        if(at.second-length>0 && length+1<len[at.first][at.second-length]) {
            map[at.first][at.second-length]=at;
            len[at.first][at.second-length]=length+1;
            toAdd.push_back(pair<int,int>(at.first,at.second-length));
        }
        if(at.first+length<LEN && length+1<len[at.first+length][at.second]) {
            map[at.first+length][at.second]=at;
            len[at.first+length][at.second]=length+1;
            toAdd.push_back(pair<int,int>(at.first+length,at.second));
        }
        if(at.second+length<LEN && length+1<len[at.first][at.second+length]) {
            map[at.first][at.second+length]=at;
            len[at.first][at.second+length]=length+1;
            toAdd.push_back(pair<int,int>(at.first,at.second+length));
        }
    }/*
    for(int i=0;i<LEN;i++) {
        for(int i2=0;i2<LEN;i2++)
            cout<<len[i][i2]<<" ";
        cout<<"\n";
    }*/
    for(int cases=1;cases<=T;cases++) {
        int x,y;
        in>>x>>y;
        string st="";
        int xon=rat(y);
        int yon=rat(x);
        while(xon!=250 || yon!=250) {
            pair<int,int> to=map[xon][yon];
            if(to.first<xon && to.second==yon) {
                st="N"+st;
            }
            else if(to.first==xon && to.second<yon) {
                st="E"+st;
            }
            else if(to.first==xon && to.second>yon) {
                st="W"+st;
            }
            else {
                st="S"+st;
            }
            xon=to.first;
            yon=to.second;
        }
        out<<"Case #"<<cases<<": "<<st<<"\n";
    }
}