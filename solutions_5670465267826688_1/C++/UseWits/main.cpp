#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>

#define pii pair<long long,long long>

using namespace std;


long long sum(long long a, long long b) {
    if(a < 0) a=-a;
    if(b < 0) b=-b;
    return 100*a+b;
}



bool run() {
    long long l, x;
    cin >> l >> x;
    if(x > 12) x=12+(x%4);
    string line;
    cin >> line;

    string cont = "ijl";
 
    map<long long,long long> convert;
    convert[sum('1','1')]='1';
    convert[sum('1','i')]='i';
    convert[sum('1','j')]='j';
    convert[sum('1','k')]='k';

    convert[sum('i','1')]='i';
    convert[sum('i','i')]=-'1';
    convert[sum('i','j')]='k';
    convert[sum('i','k')]=-'j';
     
    convert[sum('j','1')]='j';
    convert[sum('j','i')]=-'k';
    convert[sum('j','j')]=-'1';
    convert[sum('j','k')]='i';

    convert[sum('k','1')]='k';
    convert[sum('k','i')]='j';
    convert[sum('k','j')]=-'i';
    convert[sum('k','k')]=-'1';

    set<pii> statesnew;
    set<pii> statesold;
    statesold.insert(make_pair('1',0));
    for(long long xi=0; xi<x; xi++) {
    for(long long i=0; i<l; i++) {
        //cout << endl<<"times " <<line[i]<<endl;
        for(set<pii>::iterator it=statesold.begin(); it!=statesold.end(); ++it) {
            pii c = *it;
           // if(c.first > 0) cout << (char)c.first;
           // else cout << "-" << (char)-c.first;
           // cout << c.second<< "    ->    ";
           
            long long tmp = convert[sum(c.first,line[i])];
            if(c.first < 0) tmp*=-1;
            c.first = tmp;

            if(c.first == cont[c.second]) {
                statesnew.insert(make_pair('1',c.second+1));
            }
            statesnew.insert(c);

          //  if(c.first > 0) cout << (char)c.first;
          //  else cout << "-" << (char)-c.first;
          //  cout << c.second << endl;
        }
        
        statesold=statesnew;
        statesnew=set<pii>();
    }
    }
    
    for(set<pii>::iterator it=statesold.begin(); it!=statesold.end(); ++it) {
        pii c = *it;
        if(c.first == 'k' && c.second == 2)
            return true;
    }
    return false;
}

int main() {
    long long ncases;
    cin >> ncases;
    for(long long i=0; i<ncases; i++) {
        cout << "Case #"<<(i+1) << ": ";
        if(run()) cout << "YES";
        else cout << "NO";
        cout <<"\n";
    }
}
