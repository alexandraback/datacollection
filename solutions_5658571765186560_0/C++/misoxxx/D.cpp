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
int main(){
    int T;
    cin >> T;
    for(int tt=1;tt<=T;tt++){
        int x,R,C;
        cin >> x >> R >> C;
        bool gabriel=false;
        if(x==1){
            gabriel=true;
        }else if(x==2 && (R*C)%2==0){
            gabriel=true;
        }else if(x==3){
            if(R*C%3!=0){
                ;
            }else{
                if(R==3 && C>=2)gabriel=true;
                if(C==3 && R>=2)gabriel=true;
            }
        }else{
            if(R*C%4!=0){
                ;
            }else{
                if(R==4 && C>=3)gabriel=true;
                if(C==4 && R>=3)gabriel=true;
            }
        }
       // cout << x << " " << R << " " << C << " ";
        if(gabriel){
            cout << "Case #" << tt << ": GABRIEL\n";
        }else{
           cout << "Case #" << tt << ": RICHARD\n"; 
        }
    }
    return 0;
}