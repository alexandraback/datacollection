#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int NMax = 51;

char Bo[NMax][NMax];

int T;
vector <int> R,C,M;

void readInput(){
    cin >>T;
    for(int i = 0; i<T; i++){
        int r,c,m;
        cin >>r>>c>>m;
        R.push_back(r);
        C.push_back(c);
        M.push_back(m);
    };
};

void floodIt(int i, int j, int R, int C){
    Bo[i][j] = 10;

    for(int ix = -1; ix<=1; ix++){
    for(int jy = -1; jy<=1; jy++){
           if(ix == 0 and jy ==0) continue;
           if ((i+ix <0)|| (i+ix >=R) )continue;
           if ((j+jy <0)|| (j+jy >=C) )continue;
           if (Bo[i+ix][j+jy] == 0){
                floodIt(i+ix, j+jy, R,C);
           }
       }; //jy
    }; // ix
}

bool check(string x, int R, int C){
    //cout <<"Checking for "<<x<<" "<<R<<" "<<C<<endl;
    for(int i = 0; i<R; i++)
    for(int j = 0; j<C; j++) Bo[i][j]  = 0;

    for(int i = 0; i<x.length(); i++){
        if (x[i] != '*') continue;
        int u = i/C;
        int v = i%C;
        Bo[u][v] = 9;
    };

    /*
    for(int i = 0; i<R; i++){
        for(int j = 0; j<C; j++)
            cout <<'0'+Bo[i][j]<<" ";
        cout <<endl;
    }*/

    //cout <<" next:"<<endl;

    for(int i = 0; i<R; i++)
    for(int j = 0; j<C; j++)
    if (Bo[i][j] == 9){
        for(int ix = -1; ix<=1; ix++)
        for(int jy = -1; jy<=1; jy++){
            if(ix == 0 and jy ==0) continue;
            if ((i+ix <0)|| (i+ix >=R) )continue;
            if ((j+jy <0)|| (j+jy >=C) )continue;
            if (Bo[i+ix][j+jy] != 9) Bo[i+ix][j+jy]++;
        };

    }; // if -1
    /*
    for(int i = 0; i<R; i++){
        for(int j = 0; j<C; j++)
            cout <<'0'+Bo[i][j]<<" ";
        cout <<endl;
    }*/

    // check here: 1..8
    for(int i = 0; i<R; i++)
    for(int j = 0; j<C; j++)
    if (Bo[i][j] < 9 && Bo[i][j]>0 ){
    //if (Bo[i][j] < 9){
        bool found = false;
        for(int ix = -1; ix<=1; ix++){
            if (found) break;
            for(int jy = -1; jy<=1; jy++){
                if(ix == 0 and jy ==0) continue;
                if ((i+ix <0)|| (i+ix >=R) )continue;
                if ((j+jy <0)|| (j+jy >=C) )continue;
                if (Bo[i+ix][j+jy] == 0){
                    found = true;
                    break;
                }
            }; //jy
        }; // ix
        if (not found) return false;
    }; // if 1..8

    //check 0:
    int nComp =0;
    for(int i=0; i<R; i++)
    for(int j=0; j<C; j++){
        if (Bo[i][j] == 0){
            nComp++;
            floodIt(i,j, R,C);
        }; // if
    };//
/*
    for(int i = 0; i<R; i++){
        for(int j = 0; j<C; j++)
            cout <<'0'+Bo[i][j]<<" ";
        cout <<endl;
    }
*/

    return (nComp == 1);
    //return true;
}

vector<string> Mines(int R, int C, int M){
    //cout <<R<<" "<<C<<" "<<M<<endl;
    vector<string> res;
    int nM = R*C - M;
    bool flag = false; // R<=C;
    if (R>C){
        swap(R,C);
        flag = true;
    };
    // now R<=C
    if(nM == 1){
        for(int i = 0; i<R; i++){
            string tmp;
            for(int j = 0; j<C; j++)
               tmp.push_back('*');
            res.push_back(tmp);
        };
        res[0][0]='c';
    };

    if (nM>1){
        string x = "";
        for(int i = 1; i<=nM; i++) x += ".";
        for(int i = 1;  i<=M; i++) x += "*";
        bool yesno = false;
        do{
            //cout <<x<<endl;
            yesno = check(x,R,C);
            if (yesno) break;
        } while(prev_permutation (x.begin(), x.end()));

        if(yesno==false){
            res.push_back("Impossible");
            return res;
        }
        else{
            int u,v;
            for(int i = 0; i<R; i++){
                string tmp;
                tmp.resize(C);
                for(int j = 0; j<C; j++){
                    if (Bo[i][j] ==10){
                        u = i;
                        v = j;
                    };
                    if (Bo[i][j] == 9)tmp[j] = '*';
                    else tmp[j] = '.';
                }// j
                res.push_back(tmp);
            }//i
            res[u][v] = 'c';
        }// else yesno

    };// nM>1;


    if (flag){ //
        vector<string> tmp; tmp.clear();
        tmp.resize(res[0].length());
        for(int i = 0; i<res[0].length();i++)
        for(int j = 0; j<res.size(); j++)
            tmp[i].push_back(res[j][i]);

        res.clear();
        res = tmp;
    };

    return res;
}

void solve(){
    for(int i=0;i<T;i++){
        cout <<"Case #"<< (i+1) <<": "<<endl;
        vector<string> res = Mines(R[i],C[i],M[i]);

        for(int i = 0; i<res.size(); i++){
            cout <<res[i]<<endl;
        };
    };
}

int main()
{
    readInput();
    solve();
    return 0;
}
