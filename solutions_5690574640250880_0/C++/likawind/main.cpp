//
//  main.cpp
//  C
//
//  Created by Zhou Sun on 4/12/14.
//  Copyright (c) 2014 Zhou Sun. All rights reserved.
//

#include <iostream>
using namespace std;
int f[100][100];
string itoc="*.c";
bool solve(int r,int c,int w){

    memset(f, 0, sizeof(f));
    if (w==1) {
        f[0][0]=2;
        return 1;
    }
    if (r>=3) {
        if (w<4) {
            return 0;
        }
        f[0][0]=f[0][1]=f[1][0]=f[1][1]=1;
        w-=4;
        if (w==1||w==3) {
            return 0;
        }
        if (!w) {
            f[0][0]=2;
            return 1;
        }
        int k=2;
        while (w!=3&&w&&k<r) {
            f[k][0]=f[k][1]=1;
            k++;
            w-=2;
        }
        if (!w) {
            f[0][0]=2;
            return 1;
        }
        int j=2;
        while (1) {
            if (w<=3) {
                for (int i=0; i<w; i++) {
                    f[i][j]=1;
                }
                f[0][0]=2;
                return 1;
            }
            for (int k=0; w&& k<r && (w!=2||r-k>=2);k++ ) {
                f[k][j]=1;
                w--;
            }
            j++;
        }
    }
    else{
        if (r==1) {
            for (int i=0; i<w; i++) {
                f[0][i]=1;
            }
        }
        if (r==2) {
            if (w%2||w==2) {
                return 0;
            }
            for (int i=0; i<w/2; i++) {
                f[0][i]=f[1][i]=1;
            }
        }
    }
    f[0][0]=2;
    return 1;
}

void print(int r,int c,bool sw){
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cout<<(sw?itoc[f[j][i]]:itoc[f[i][j]]);
        }
        cout<<endl;
    }
}


int main(int argc, const char * argv[])
{
    freopen("myfile1.txt","r",stdin);
    
    freopen("myfile.txt","w",stdout);

    int ts;
    cin>>ts;
    for (int tt=0; tt<ts; ++tt) {
        int r,c,m;
        bool sw=0;
        cin>>r>>c>>m;
        cout<<"Case #"<<tt+1<<":\n";
        if(r>c){
            swap(r, c);
            sw=1;
        };
        if (solve(r, c, r*c-m)) {
            if (sw) {
                swap(r,c);
            }
            print(r, c, sw);
        }
        else{
            cout<<"Impossible"<<endl;
        }
    }
    
    return 0;
}


