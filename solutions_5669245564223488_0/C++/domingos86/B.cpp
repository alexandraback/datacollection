#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

ll tryncheck(int lvl, int* perm, bool* used, int* usedat, int N, const vector<string>& cars){
    ll k=0;
    char lastcar='a'-1;
    if(lvl>0) lastcar=cars[perm[lvl-1]].at(cars[perm[lvl-1]].length()-1);
    char curcar;
    bool test;
    for(int j=0;j<N;j++){
        test=true;
        for(int l=0;l<lvl;l++) test=test && (perm[l]!=j);
        if(test) for(int l=0;l<cars[j].length();l++) test=test && !(used[cars[j].at(l)-'a']);
        if(test){
            for(int l=26;l<52;l++) used[l]=false;
            curcar=lastcar;
            if(lvl==0) curcar=cars[j].at(0);
            for(int l=0;l<cars[j].length();l++) if(test&&(cars[j].at(l)!=curcar)){
                used[curcar-'a'+26]=true;
                usedat[curcar-'a']=lvl+1;
                test=test && !(used[cars[j].at(l)-'a'+26]);
                curcar=cars[j].at(l);
            }
        }
        if(test){
            for(int l=0;l<26;l++) used[l]=used[l]||used[l+26];
            if(lvl==N-1){
                k+=1;
            } else {
                perm[lvl]=j;
                k+=tryncheck(lvl+1,perm, used, usedat, N, cars);
            }
            for(int l=0;l<26;l++) if(used[l]&&(usedat[l]>lvl)) used[l]=false;
        }
    }
    return k % MOD;
}

int main(){

    int T;
    cin >> T;
    vector<string> strs (100);

    int N;
    bool used[52];
    int usedat[26];
    int perm[100];
    string readtemp;
    //int *o, *e, *p;

    for(int i=1;i<=T;i++){

        cin >> N;

        for(int j=0;j<N;j++){
            cin >> readtemp;
            strs.at(j)=readtemp;
        }

        for(int j=0;j<52;j++) used[j]=false;

        cout << "Case #" << i << ": ";

        cout << tryncheck(0,perm,used,usedat,N,strs);

        cout << endl;
    }

    return 0;
}
