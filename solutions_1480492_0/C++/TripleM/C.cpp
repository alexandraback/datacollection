#include <iostream>
#include <cmath>
using namespace std;
bool debug = false;
char llane[50][2];
bool lane[50];
int speed[50], pos[50];
typedef struct Event {
    double time;
    int a,b;
    bool type;
    bool operator<(const Event& e) const {
        if (fabs(time-e.time)>1e-9) return time<e.time;
        if (type!=e.type) return !type;
        return false;
    }
};
bool graph[50][50];
bool deleted[50][50];
int tmp[50];
Event events[3000];
int ec;
int N;
bool empty[50];
void cleanup() {
    for (int i=0; i<N; i++) {
        empty[i] = true;
        for (int j=0; j<N; j++) if (!deleted[i][j] && (graph[i][j] || graph[j][i])) {
            empty[i] = false;
            break;
        }
    }
    for (int i=0; i<N; i++) if (empty[i])
    for (int j=i+1; j<N; j++) if (empty[j] && deleted[i][j]) {
        deleted[i][j] = deleted[j][i] = false;
        graph[i][j] = graph[j][i] = false;
    }
}
void removeedge(int a, int b) {
    if (graph[a][b] && graph[b][a]) {
        deleted[a][b] = deleted[b][a] = true;
    } else {
        graph[a][b] = graph[b][a] = false;
    }
    cleanup();
}
bool updateedge(int a, int b) {
if (debug) printf("Updating edge %d %d\n",a,b);    
    bool forward = false, backward = false;
    for (int i=0; i<N; i++) {
        if (graph[i][a] && !graph[a][i]) backward = true;
        if (graph[a][i] && !graph[i][a]) forward = true;
        if (graph[b][i] && !graph[i][b]) backward = true;
        if (graph[i][b] && !graph[b][i]) forward = true;
    }
if (debug)     printf("Back: %d Forward: %d\n",backward,forward);
    if (backward && forward) return false;
    assert(graph[a][b] && graph[b][a]);
    if (forward) {
        graph[b][a] = false;
    }
    if (backward) {
        graph[a][b] = false;
    }
    if (forward || backward) {
        for (int i=0; i<N; i++) {
            if (graph[i][a] && graph[a][i] && !updateedge(i,a)) return false;
            if (graph[i][b] && graph[b][i] && !updateedge(i,b)) return false;
        }
    }
    return true;
}
bool oddcycle(int start, int type) {
if (debug) printf("Tmp[%d] = %d\n",start,type);    
    tmp[start] = type;
    for (int i=0; i<N; i++) {
        if (graph[start][i] && graph[i][start]) {

if (debug)             printf("Is edge from %d to %d and latter is type %d\n",start,i,tmp[i]);
            if (tmp[i] && tmp[i]!=3-type) return true;
            if (tmp[i]==0 && oddcycle(i,3-type)) return true;
        }
    }
    return false;
}
bool addedge(int a, int b) {
if (debug) printf("Add edge %d %d\n",a,b);    
    graph[a][b] = graph[b][a] = true;
    if (!updateedge(a,b)) return false;
if (debug) printf("Past updateedge\n");
    for (int i=0; i<N; i++) tmp[i] = 0;    
    if (oddcycle(a,1)) {
if (debug)         printf("Is odd cycle\n");
        return false;    
    }
    return true;
}
void addevent(double time, int a, int b, bool type) {
if (debug) printf("Add event %f %d %d %d\n",time,a,b,type);    
    events[ec].time = time;
    events[ec].a = a;
    events[ec].b = b;
    events[ec].type = type;
    ec++;
}
int main() {
    int T; scanf("%d",&T); for (int t=1; t<=T; t++) {
        ec=0;
        memset(graph,0,50*50*sizeof(bool));
        memset(deleted,0,50*50*sizeof(bool));
        scanf("%d",&N);
        for (int i=0; i<N; i++) {
            scanf("%s %d %d",llane[i],&speed[i],&pos[i]);            
            lane[i] = llane[i][0]=='L';
        }
        for (int i=0; i<N; i++)
        for (int j=i+1; j<N; j++) {
            if (speed[i]==speed[j]) {
                // are they overlapping
                if (abs(pos[i]-pos[j])<5) {
                    assert(lane[i]!=lane[j]);
                    if (lane[i]) {
                        graph[i][j] = true;
if (debug) printf("%d -> %d\n",i,j);                        
                    }
                    else {
                        graph[j][i] = true;
if (debug) printf("%d -> %d\n",j,i);                                                
                    }

                }
            } else {
                // when does front of i hit end of j
                /*
                pos[i] + 5 + speed[i]*t = pos[j] + speed[j] * t
                // t(speed[i]-speed[j]) = pos[j] - pos[i] - 5
                */
                double time1 = (pos[j]-pos[i]-5)*1./(speed[i]-speed[j]);
                double time2 = (pos[i]-pos[j]-5)*1./(speed[j]-speed[i]);
                double start = min(time1,time2);
                double end = max(time1,time2);
                
                // are they overlapping
                if (start<0 && end>0) {
                    assert(lane[i]!=lane[j]);
                    if (lane[i]) graph[i][j] = true;
                    else graph[j][i] = true;
                    addevent(end,i,j,false);
                } else if (end<0) {}
                else {                    
                    addevent(start,i,j,true);
                    addevent(end,i,j,false);
                }
            }
        }
        sort(events,events+ec);
        double ans = 0;
        bool ok = true;
        for (int i=0; i<ec; i++) {
//printf("%f %d %d %d\n",events[i].time,events[i].a,events[i].b,events[i].type);
        }
        for (int i=0; i<ec; i++) {
            ans = events[i].time;
if (debug) printf("At time %f\n",ans);
            if (events[i].type) {
                if (!addedge(events[i].a,events[i].b)) {
                    ok = false;
                    break;
                }
            } else {
                removeedge(events[i].a,events[i].b);
            }
        }
        printf("Case #%d: ",t);
        if (ok) printf("Possible\n");
        else printf("%f\n",ans);
    } 
}
