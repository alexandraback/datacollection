#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main () {
    int T,case_id;
    string original,trans;
    string::iterator it1,it2;
    freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
    
    cin >> T;
    getline (cin,original);
    for (case_id=1;case_id<=T;case_id++) {
        cout << "Case #" << case_id << ": ";
        getline (cin,original);
        trans=original;
        it2=trans.begin();
        for ( it1=original.begin() ; it1 < original.end(); it1++ ) {
            
            if (*it1=='a') *it2='y'; // 25
            if (*it1=='b') *it2='h'; // 8
            if (*it1=='c') *it2='e'; // 5
            if (*it1=='d') *it2='s'; // 19
            if (*it1=='e') *it2='o'; // 15
            if (*it1=='f') *it2='c'; // 3
            if (*it1=='g') *it2='v'; // 22
            if (*it1=='h') *it2='x'; // 24
            if (*it1=='i') *it2='d'; // 4
            if (*it1=='j') *it2='u'; // 21
            if (*it1=='k') *it2='i'; // 9
            if (*it1=='l') *it2='g'; // 7
            if (*it1=='m') *it2='l'; // 12
            if (*it1=='n') *it2='b'; // 2
            if (*it1=='o') *it2='k'; // 11
            if (*it1=='p') *it2='r'; // 18
            if (*it1=='q') *it2='z'; // 26//not found
            if (*it1=='r') *it2='t'; // 20
            if (*it1=='s') *it2='n'; // 14
            if (*it1=='t') *it2='w'; // 23
            if (*it1=='u') *it2='j'; // 10
            if (*it1=='v') *it2='p'; // 16
            if (*it1=='w') *it2='f'; // 6
            if (*it1=='x') *it2='m'; // 13
            if (*it1=='y') *it2='a'; // 1
            if (*it1=='z') *it2='q'; // 17
            it2++;
        }
        cout << trans << endl;
    }
    
    
    return 0;
}
