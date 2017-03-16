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
    for(int i=1;i<=T;i++){
        int sMax;
        string s;
        cin >> sMax >> s;
        int friends=0;
        int standing=0;
        for(int j=0;j<sMax+1;j++){
            if(j<=standing)standing+=s[j]-'0';
            else{
                friends+=j-standing;
                standing=j+s[j]-'0';
            }
        }
        cout << "Case #"<<i<<": " <<friends << "\n";
    }
    return 0;
}