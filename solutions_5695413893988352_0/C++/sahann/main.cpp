#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
//#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

ifstream cin("/Users/Nagi2/Downloads/GCJ2016/B-small-attempt0.in");
ofstream cout("/Users/Nagi2/Downloads/qwertyD.txt");




using namespace std;

void f(string &s1, int i, string s2, vector <string> & vs){
    if(s2.size()==s1.size()){
        vs.push_back(s2);
        return;
    }
    if(s1[i]=='?'){
        
        for(int j=0;j<=9;j++){
            string s3 = s2;
            s3+= '0'+j;
            f(s1,i+1,s3,vs);
        }
    }
    else{
        string s3 = s2;
        s3+=s1[i];
        f(s1,i+1,s3,vs);
    }
}


       

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    
    for(int t =0;t<T;t++){
        vector<string> vs1;
        vector<string> vs2;
        string coders;
        string jammers;
        cin >> coders;
        cin >> jammers;
        string s2;
        f(coders,0,s2,vs1);
        f(jammers,0,s2,vs2);
        vector <int> best;
        best.push_back(1000);
        best.push_back(1000);
        best.push_back(1000);
        for(int i=0;i<vs1.size();i++){
            for(int j=0;j<vs2.size();j++){
                vector <int> cand;
                istringstream iss1(vs1[i]);
                istringstream iss2(vs2[j]);
                int sc1,sc2;
                iss1>> sc1;
                iss2 >> sc2;

                cand.push_back(abs(sc1-sc2));
                cand.push_back(sc1);
                cand.push_back(sc2);
                cand.push_back(i);
                cand.push_back(j);
                best = min(best,cand);
                
            }
        }
        
        
        cout << "Case #" << t+1 << ": "<< vs1[best[3]]<< " " << vs2[best[4]]<<  endl;
        
    }
    return 0;
}
