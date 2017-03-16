/*
 ID: szhu0081
 LANG: C++
 TASK: butter
 */

#include <iostream>
#include <list>
#include <cstring>
#include <numeric>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
#include <utility>
#include <string>
#include <map>
#include <set>
#include <cmath>
using namespace std;

typedef vector<int> vi;
typedef set<vi> svi;

long long T, S;

int main(){
    
    ifstream ins("A-large.in");
    ofstream ofs("A-large-out.txt");
    
    ins >> T;
    
    for (int cse = 1; cse <= T; cse ++){
        
        ins >> S;
        string shyness;
        ins >> shyness;
        int numToAdd = 0;
        int totalCount = 0;
        for (int i = 0; i <= S; i++){
            if (totalCount < i){
                numToAdd += (i-totalCount);
                totalCount = i;
            }
            totalCount += int(shyness[i] - '0');
        }
        ofs << "Case #" << cse << ": " << numToAdd << endl;
        
    }


    return 0;
}


