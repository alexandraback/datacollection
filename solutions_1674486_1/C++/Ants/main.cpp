/* 
 * File:   main.cpp
 * Author: Ants
 *
 * Created on May 6, 2012, 11:51 AM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <list>
#include <set>

using namespace std;


int main(int argc, char** argv) {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        
        vector<set<int> > direct_parents(N+1);
        vector<list<int> > direct_children(N+1);
        vector<set<int> > parents(N+1);
        
        for (int n = 1; n <= N; n++) {
            int M;
            cin >> M;
            for (int m = 0; m < M; m++) {
                int a;
                cin >> a;
                direct_parents[n].insert(a);
                direct_children[a].push_back(n);
            }
        }
        
        list<int> up_next;
        for (int n = 1; n <= N; n++) {
            if (direct_parents[n].empty()) up_next.push_back(n);
        }
        
        bool answer = false;
        
        while (!up_next.empty()) {
            int k = up_next.front();
            up_next.pop_front();
            parents[k].insert(k);
            
            for (list<int>::iterator it = direct_children[k].begin(); it != direct_children[k].end(); it++) {
                
                for (set<int>::iterator jt = parents[k].begin(); jt != parents[k].end(); jt++) {
                    if (parents[*it].find(*jt) != parents[*it].end()) {
                        answer = true;
                        break;
                    } else parents[*it].insert(*jt);    
                }
                
                if (answer) break;
                
                direct_parents[*it].erase(k);
                if (direct_parents[*it].empty()) up_next.push_back(*it);
                
                
            }
            
            if (answer) break;
        }
        
        cout << "Case #" << t << ": " << (answer ? "Yes" : "No") << endl;
        
    }
    return 0;
}

