/*
 * PID: 	b
 * NAME:	B
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <climits>

#include <map>
#include <string>
#include <algorithm>
#include <list>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <utility>

using namespace std;


// Google Code Jam - specific template

int main(){
	int ncase;
    cin >> ncase;

    multimap<int, int> l1; //level 1 costs
    multimap<int, int> l2; //level 2 costs
    map<int,int>:: iterator it,it2;
    pair<int,int> p;
    int status[1000]; //0 if not completed, 1 if level one completed, etc
    int second[1000]; // stores value of second level to tie break 1st level selection
    for (int i = 0; i < ncase; i++){
        // READ AND PROCESS CASE
        int n; // number of levels
        cin >> n;

        l1.clear();
        l2.clear();
        // insert the levels
        for (int j = 0; j < n; j++){
            p.second = j;
            cin >> p.first;
            l1.insert(p);
            cin >> p.first;
            l2.insert(p);
            status[j] = 0;
            second[j] = p.first;
        }
        int stars = 0;
        int plays = 0;
        bool bad = true;
        while (true){
           bad = true;
           // printf("a");
           // fflush(stdout);
            // main loop, find next selection
            if (!l2.empty()){
                it = l2.begin();
                int cost = it -> first;
               // cout << "Level 2 has cost " << cost << " with " << l2.size() << " items " << endl;
                if (cost <= stars){
                    // add level 2
                   // cout << "Playing level " << it -> second << " for 2 stars" << endl;
                    stars += 2-status[it->second];
                    status[it -> second] = 2;
                    plays++;
                    bad = false;
                    l2.erase(it);
                    continue;
                }
            }
            while(!l1.empty()){
                it = l1.begin();
                if (status[it -> second] >= 1){
                    l1.erase(it);
                    continue;
                }else{
                    int cost = it -> first;

                    if (cost <= stars){
                        //add level 1 (find maxmimum 2nd level with this cost)
                        int maxsec = second[it -> second];
                        for (it2 = it; it2 != l1.end() && it2->first <= stars ; it2++){
                            if (status[it2 -> second] >= 1) continue;
                         //   cout << "Looking at level " << it2 -> second << endl;
                            if(second[(it2 -> second)] > maxsec){
                     //           cout << "updating maximum " << endl;
                                maxsec = second[it2 -> second];
                                it = it2;
                            }
                        }

                        
                        stars += 1;
                        status[it -> second] = 1;
                     // cout << "Playing level " << it -> second << " for 1 stars" << endl;
                        plays++;
                        bad = false;
                        l1.erase(it);
                    } 
                    break;
                }
            }
            
            if (l1.empty() && l2.empty()){
                bad = false;
                break;
            }
            
          //  printf(" finisihing");
           // fflush(stdout);
            if (bad) break;
        }

        if (bad){
            printf("Case #%i: Too Bad\n", i+1);
        } else{
            printf("Case #%i: %i\n", i+1, plays);
        }
        
    }

}
