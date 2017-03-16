/* 
 * File:   main.cpp
 * Author: tyg3r
 *
 * Created on 27. duben 2013, 4:00
 */

#include <cstdlib>
#include <stdio.h>
#include <queue>

using namespace std;

struct task {
    long day;
    long v;
    
    task(long d, long v) {
        day = d;
        this->v = v;
    }
    bool operator<(const task t) const {
        return v < t.v;
    }
};

int main(int argc, char** argv) {
    
    long energy[10007];
    bool used[10007];
    priority_queue<task> pq;
    
    int T;
    long N, R, E, v;
    
    scanf("%d", &T);
    for(int caseN = 1; caseN <= T; caseN++) {
        pq = priority_queue<task>();
        scanf("%ld%ld%ld", &E, &R, &N);
        for(int i = 0; i < N; i++) {
            scanf("%ld", &v);
            pq.push(task(i,v));
            used[i] = false;
            energy[i] = E;
        }
        long gain = 0;
        while(!pq.empty()) {
            task tsk = pq.top();
            pq.pop();
            
            //find available energy
            long available = energy[tsk.day];
            long regenerate = 0;
            for(int i = tsk.day+1; i < N; i++) {
                regenerate += R;
                if(used[i] == true) {
                    available = min(available, min(E, available+regenerate-energy[i]));
                    break;
                }
            }
            if(available < 0) available = 0;
            //printf("v: %ld, av: %ld\n", tsk.v, available);
            gain += available * tsk.v;
            used[tsk.day] = true;
            long newEnergy = energy[tsk.day] - available;
            //energy[tsk.day] = available;
            
            for(int i = tsk.day+1; i < N && used[i] == false; i++) {
                newEnergy += R;
                if(newEnergy > E) newEnergy = E;
                energy[i] = newEnergy;
            }
        }
        printf("Case #%d: %ld\n", caseN, gain);
    }
    
    return 0;
}

