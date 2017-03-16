#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <bitset>
#include <cstdio>
#include <sstream>
#include <string>
#include <queue>
#include <map>
#include <stack>
#include <set>
#include <cctype>
#include <iomanip>
#include <list>
#include <cstring>

#define INF 2000000000
#define ull unsigned long long int
#define vi vector<int>
#define vii vector<ii>

#define UNVISITED 0
#define OPENED 1
#define CLOSED 2

#define NBNODE 2000


using namespace std;





int main () {  

    int nCase = 0;
    cin >> nCase;
    getchar();
    for(int iCase = 1; iCase <= nCase; iCase++) {    
       
        string pancake;
        getline(cin, pancake);
        
        char last = pancake[0];
        int rep = 0;
        for(int i= 1; i < pancake.size(); i++) {
            if(last != pancake[i]) {
                rep++;
                last = pancake[i];        
            }

        }
        if(last == '-') rep++;

        printf("Case #%d: %d\n", iCase, rep);

    }    
     
    
    return 0;
}
