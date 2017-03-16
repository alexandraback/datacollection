#ifdef VX_PRECOMPILED
    #include "precomp.h"
    typedef mpz_class big;
    // I use 4 cores :)
    #define MAX_THREADS 4
#else
    #include <bits/stdc++.h>
    #include<sys/stat.h>
    #include<unistd.h>
    // http://gmplib.org/ (uncomment if solution uses big nums)
    // most likely you'll get an error about mpz_class not being declared...
    //#include "gmpxx.h"
    #define big mpz_class
    // I figure that when other people want to test my solutions they shouldn't
    // get the whole multi-threaded mess that requires and deletes folders and files...
    #define MAX_THREADS 1
#endif

#define for_each(q,s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
typedef long long int64;
#define long int64

using namespace std;

//====================================================================
// Library code follows:
//.
// My Max flow solver:
//
namespace MaxFlow
{
    typedef int     Cap;
    
    const Cap  INF   =  3000; //infinite (capacity)
    const int  MAX   =  2002; //maximum vertices
    const int  EDGES = 10000; // maximum edges
    struct network
    {
        int source, sink;
        int V = 0, E = 0;
        int    u;
        Cap  capacity[2*EDGES];
        int  destination[2*EDGES];
        int  next[2*EDGES];
        int  first[MAX];

        /** Add vertex, return index */
        int addVertex()       
        {
            assert(V < MAX);
            first[V] = -1;
            return V++;
        }
        /** Add edge between two vertices with a capacity */
        void addEdge(int from, int to, Cap edgecapacity)
        {
            assert(E + 2 <= 2 * EDGES);
            // Since max flow process creates residual networks we actually 
            // create two edges, one for each direction.
            // In case the initial graph could have edges in both directions,
            // it would be more efficient to use a different function...
            capacity   [E] = edgecapacity;
            destination[E] = to;
            next       [E] = first[from];
            first[from] = E++;
            
            capacity   [E] = 0;
            destination[E] = from;
            next       [E] = first[to];
            first[to] = E++;
            // We get clever, for a given edge e , the opposite edge will be e^1 
        }

        int  dist[MAX];
        void bfs()
        {
            // A BFS to get min distance from source.
            fill(dist, dist + V, 2*(V + 1));
            dist[source] = 0;
            queue<int> Q;
            Q.push(source);
            while (! Q.empty()) {
                int x = Q.front(); Q.pop();
                int e = first[x];
                while (e != -1) {
                    int y = destination[e];
                    if (capacity[e] != 0) {
                        if ( dist[y] > dist[x] + 1) {
                            dist[y] = dist[x] + 1;
                            Q.push(y);
                        }
                    }
                    e = next[e];
                }
            }
        }

        bool visited[MAX];        
        int reFlow(int x, Cap f)
        {
            // Recursively fill the flow follow the order from BFS
            if (x == sink) {
                return f;
            }
            if (visited[x]) {
                return 0;
            }
            visited[x] = true;
            Cap uf = 0;
            int e = first[x];
            while ( (uf < f) && (e != -1) ) {
                int y = destination[e];
                if ( (dist[y] == dist[x]+1) && (capacity[e] != 0) ) {
                    Cap r = reFlow(y, std::min(f - uf, capacity[e] ) );
                    if (r > 0) {
                        uf += r;
                        // Residual network:
                        capacity[e] -= r;
                        capacity[e^1] += r;
                    }
                }
                e = next[e];
            }   
            return uf;
        }
        
        /** Returns the maximum flow, network will be residual**/ 
        Cap maxFlow()
        {
            Cap totalFlow = 0;
            Cap old = -1;
            //repeat until flow is full:
            while (old < totalFlow) {
                old = totalFlow;
                bfs();
                fill(visited, visited + V, false);
                int r = reFlow(source, INF);
                if ( totalFlow > INF  - r) {
                    totalFlow = INF;
                } else {
                    totalFlow += r;
                }
            }
            return totalFlow;
        }
    };
}
//
// Library code has ended...
//===============================



//=========================================================
// program:
//
struct solver
{

    
    int solve(const vector<pair<string, string>> & topics)
    {
        MaxFlow::network *g = new MaxFlow::network();
        int f = 0, s = 0;
        map<string,int> first_id, second_id;
        for (auto q: topics) {
            if ( first_id.count(q.first) == 0 ) {
                first_id[q.first] = f++;
            }
            if ( second_id.count(q.second) == 0 ) {
                second_id[q.second] = s++;
            }
        }
        for (int i = 0; i < f + s; i++) {
            g->addVertex();
        }
        g->source = g->addVertex(); 
        g->sink = g->addVertex();
        for (int i = 0; i < f; i++) {
            g->addEdge(g->source, i, 1);
        }
        for (int j = 0; j < s; j++) {
            g->addEdge(f + j, g->sink, 1);
        }
        for (auto q: topics) {
            int u = first_id[q.first], v = second_id[q.second];
            g->addEdge(u, f + v, 1);
        }
        int mf = g->maxFlow();
        
        delete g;
        
        
        return topics.size() - ( f  + s  - mf );
    }
    void init() { }
    vector<pair<string, string>> topics;
    void read() {
        int n;
        cin >> n;
        topics.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> topics[i].first >> topics[i].second;
        }
    }
    #if MAX_THREADS > 1
        ofstream cout;
    #endif
    void write(int cn) {
        cout << "Case #"<<cn<<": "<<solve(topics) << endl;
    }
    
};

//=========================================================
// I/O:
//
#if MAX_THREADS > 1
    void run(const char* x)
    {
        int r = system(x);
        cerr<<x<<" "<<"("<<r<<")"<<endl;
    }
#endif

int main(int argc, const char* argv[])
{
    int TestCases, mode;
    #if MAX_THREADS == 1
        // Simple and straight forward. 
        cin >> TestCases;
        solver * theSolver = new solver;
        theSolver->init();
        for (int i=1; i<= TestCases; i++) {
            theSolver->read();
            theSolver->write(i);
        }
        delete theSolver;    
    #else
        cin>>TestCases;
        //-------------------------------------------
        // Copy the whole input to a file...
        ofstream f;
        f.open("tests/.input");
        f << cin.rdbuf();
        f.close();
        // Yeah...wipe that folder... Cause we will need its files to be empty
        run("rm ./tests/.t*");
        int k = 0;
        mode = 0;
        // We create some extra threads...
        while (k < MAX_THREADS) {
            if ( fork() == 0 ) {
                mode = k + 1;
                break;
            }
            k++;
        }
        // Reopen the input, this happens for each of the threads...
        if (mode != 0) {
            assert( freopen( "tests/.input","r",stdin) );
        }
    
        solver * theSolver = new solver;
        theSolver->init();
        for (int i=1; i<= TestCases; i++) {
            // Yeah, I don't like this much either
            ofstream f;
            char fn1[200], fn2[200];
            sprintf(fn1, "tests/.test.%d", i);
            sprintf(fn2, "tests/.test.%d.done", i);
            if (mode == 0) {
                // main thread shall just join stuff together as it becomes ready
                struct stat stFileInfo;
                // When a thread finishes a test case, it writes the .done file
                // Wait for that...
                while ( stat(fn2, &stFileInfo) !=0 ) {
                    sleep(1);
                }
                // Now copy the output file...
                ifstream f(fn1);
                cout << f.rdbuf();
            } else {
                // The trick is to make each thread read all the inputs, whether
                // it will process it or not...
                theSolver->read();
                // If fn1 exists, it is being processed already. Else process it
                f.open(fn1, ios_base::out | ios_base::in);
                if ( !f ) {
                    theSolver->cout.open(fn1, ios_base::out);
                    cerr << "[" << i << "/"<<TestCases<<"] "<<mode << endl;
                    theSolver->write(i);
                    theSolver->cout.close();
                    f.open(fn2);
                    f << "1" << endl;
                }
            }
        }
        delete theSolver;
    #endif

    
    return 0;
}
