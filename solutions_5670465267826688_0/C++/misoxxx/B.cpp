#include <cstdio>
#include <string>
#include <set>
#include <iostream>
#include <cstdlib>
#include <queue>
#include <cmath>
#include <vector>
#include <map> 
#include <ctime>
#include <sstream>
#include <list>
#include <algorithm>
#define pb push_back
#define FOR(a,b) for(int a=0;a<b;a++)
#define ll long long
#define Point pair<double,double>
#define NEKONECNO 99999999
#define PI 3.14159265359
#define ff first
#define ss second
#define DEBUG(x) fprintf(stderr,"%s\n",#x);
#define mp make_pair
using namespace std;
const int DDD=5;
int toInt(char c){
    return c-'i'+5;
}
int mul(int a,int b){
    if(a==1)return b;
    if(b==1)return a;
    if(a==-1)return -b;
    if(b==-1)return -a;
    int aa=abs(a),bb=abs(b);
    if(aa==bb){
        return -((a*b)/(aa*bb));
    }
    switch(aa){
        case 5:
            if(bb==6)return ((a*b)/(aa*bb))*7;
            if(bb==7)return -6*((a*b)/(aa*bb));
        case 6:
            if(bb==5)return -7*((a*b)/(aa*bb));
            if(bb==7)return 5*((a*b)/(aa*bb));
        case 7:
            if(bb==5)return 6*((a*b)/(aa*bb));
            if(bb==6)return -5*((a*b)/(aa*bb));
    }
    return 0;
}
int main(){
 /*   vector<int> V={1,toInt('i'),-toInt('j'),toInt('k')};
    FOR(i,V.size()){
        FOR(j,V.size()){
            printf("%d ",mul(V[i],-V[j]));
        }
        printf("\n");
    }
    */
    int T;
    cin >> T;
    for(int tt=1;tt<=T;tt++){
        ll L,X;
        cin >> L >> X;
        vector<int> S(L);
        FOR(i,L){
            char c;
            cin >> c;
            S[i]=toInt(c);
        }
        vector<vector<int> > D(L*X,vector<int> (L*X));
        FOR(i,L*X){
            D[i][i]=S[i%L];
        }
        for(int i=0;i<L*X;i++){
            for(int j=i+1;j<L*X;j++){
            //    cerr << i <<" "<< j << " " << j%L << "\n";
                D[i][j]=mul(D[i][j-1],S[j%L]);
            }
        }
     /*   FOR(i,L*X){
            FOR(j,L*X){
                cout << D[i][j] << " ";
            }
            cout << "\n";
        }*/
        bool dasa=false;
        for(int i=0;i<L*X;i++){
            if(D[0][i]==5){
                for(int j=i+1;j<L*X-1;j++){
                    if(D[i+1][j]==6 && D[j+1][L*X-1]==7){
                        dasa=true;
                    }
                }
            }
        }
        if(dasa){
            cout << "Case #" << tt << ": YES\n";
        }else{
            cout << "Case #" << tt << ": NO\n";  
        }
    }
    return 0;
}
