#include <iostream>
#include <cstdio>
#include <list>
 
using namespace std;
 
int main() {
        
        int t, T, ctr, stars, prevb;
        int i,n;
        int a[100000], b[100000];
        bool flag;
 
        cin >> T;
 
        for ( t = 0; t < T; t++ ) {
 
                cin >> n;
 
                list<int> l, x;
                list<int>::iterator it, dit;
 
                for ( i = 0; i < n; i++ ) {
                        cin >> a[i] >> b[i];
                        l.push_back(i);
                }
 
                bool ans = true;
 
                        ctr = 0;
                        stars = 0;
 
                        while ( l.size()!=0 || x.size()!=0 ) {
 
                                int pctr = ctr;
 
                                back:
 
                                flag = true;
                                while ( flag ) {
 
                                flag = false;
 
                                for ( it = l.begin(); it != l.end(); it++ ) {
 
                                        if ( b[(*it)] <= stars ) {
                                                l.erase(it);
                                                flag = true;
                                                stars = stars + 2;
                                                ctr++;
                                                it--;
                                        }
 
                                }
 
                                }
 
                                for ( it = x.begin(); it != x.end(); it++ ) {
 
                                        if ( b[(*it)] <= stars ) {
                                                x.erase(it);
                                                stars++;
                                                ctr++;
                                                goto back;
                                                it--;
                                        }
 
                                }
 
                                if ( pctr == ctr ) {
                                dit = l.end();
 
                                prevb = -1;
 
                                for ( it = l.begin(); it != l.end(); it++ ) {
 
                                        if ( a[(*it)] <= stars ) {
                                                if ( b[(*it)] > prevb ) {
                                                        prevb = b[(*it)];
                                                        dit = it;
                                                }
                                        }
 
                                }
 
                                if ( dit == l.end() ) {
                                        ans = false;
                                        break;
                                } else {
                                x.push_back(*dit);
                                l.erase(dit);
                                stars++;
                                ctr++;
                                }
                                }
 
                        }
 
 if ( ans ) {
                        cout << "Case #"<<t+1<<": " << ctr;
                        } else {
                        cout << "Case #"<<t+1<<": Too Bad";
                        }
                        
 
              
 
                cout << endl;
 
        }
 
        return 0;
}
