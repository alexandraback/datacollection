//
// Google Codejam 2016 - Round 1a -  problem C
//
// Usually built with g++ 4.4.5 on Linux
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <list>
#include <algorithm>
#include <gmpxx.h>

#include <cstdlib>
#include <math.h>

using namespace std;

typedef pair<uint32_t,uint32_t> pii;


// Code taken from
// http://www.geeksforgeeks.org/hopcroft-karp-algorithm-for-maximum-matching-set-2-implementation/

const uint32_t NIL = 0;
const uint32_t INF = 0x7fffffff;
 
// A class to represent Bipartite graph for Hopcroft
// Karp implementation
class BipGraph
{
    // m and n are number of vertices on left
    // and right sides of Bipartite Graph
    int m, n;
 
    // adj[u] stores adjacents of left side
    // vertex 'u'. The value of u ranges from 1 to m.
    // 0 is used for dummy vertex
public:
    list<int> *adj;
 
    // These are basically pointers to arrays needed
    // for hopcroftKarp()
    unsigned int *pairU, *pairV, *dist;
 
public:
    BipGraph(int m, int n); // Constructor
    void addEdge(int u, int v); // To add edge
 
    // Returns true if there is an augmenting path
    bool bfs();
 
    // Adds augmenting path if there is one beginning
    // with u
    bool dfs(unsigned int u);
 
    // Returns size of maximum matcing
    int hopcroftKarp();
};
 
// Returns size of maximum matching
int BipGraph::hopcroftKarp()
{
    // pairU[u] stores pair of u in matching where u
    // is a vertex on left side of Bipartite Graph.
    // If u doesn't have any pair, then pairU[u] is NIL
    pairU = new unsigned int[m+1];
 
    // pairV[v] stores pair of v in matching. If v
    // doesn't have any pair, then pairU[v] is NIL
    pairV = new unsigned int[n+1];
 
    // dist[u] stores distance of left side vertices
    // dist[u] is one more than dist[u'] if u is next
    // to u'in augmenting path
    dist = new unsigned int[m+1];
 
    // Initialize NIL as pair of all vertices
    for (int u=0; u<=m; u++)
        pairU[u] = NIL;
    for (int v=0; v<=n; v++)
        pairV[v] = NIL;
 
    // Initialize result
    int result = 0;
 
    // Keep updating the result while there is an
    // augmenting path.
    while (bfs())
    {
        // Find a free vertex
        for (int u=1; u<=m; u++)
         
            // If current vertex is free and there is
            // an augmenting path from current vertex
            if (pairU[u]==NIL && dfs(u))
                result++;
    }
    return result;
}
 
// Returns true if there is an augmenting path, else returns
// false
bool BipGraph::bfs()
{
    queue<int> Q; //an integer queue
 
    // First layer of vertices (set distance as 0)
    for (int u=1; u<=m; u++)
    {
        // If this is a free vertex, add it to queue
        if (pairU[u]==NIL)
        {
            // u is not matched
            dist[u] = 0;
            Q.push(u);
        }
 
        // Else set distance as infinite so that this vertex
        // is considered next time
        else dist[u] = INF;
    }
 
    // Initialize distance to NIL as infinite
    dist[NIL] = INF;
 
    // Q is going to contain vertices of left side only. 
    while (!Q.empty())
    {
        // Dequeue a vertex
        int u = Q.front();
        Q.pop();
 
        // If this node is not NIL and can provide a shorter path to NIL
        if (dist[u] < dist[NIL])
        {
            // Get all adjacent vertices of the dequeued vertex u
            list<int>::iterator i;
            for (i=adj[u].begin(); i!=adj[u].end(); ++i)
            {
                int v = *i;

                // If pair of v is not considered so far
                // (v, pairV[V]) is not yet explored edge.
                if (dist[pairV[v]] == INF)
                {
                    // Consider the pair and add it to queue
                    dist[pairV[v]] = dist[u] + 1;
                    Q.push(pairV[v]);
                }
            }
        }
    }
 
    // If we could come back to NIL using alternating path of distinct
    // vertices then there is an augmenting path
    return (dist[NIL] != INF);
}
 
// Returns true if there is an augmenting path beginning with free vertex u
bool BipGraph::dfs(unsigned int u)
{
    if (u != NIL)
    {
        list<int>::iterator i;
        for (i=adj[u].begin(); i!=adj[u].end(); ++i)
        {
            // Adjacent to u
            int v = *i;
 
            // Follow the distances set by BFS
            if (dist[pairV[v]] == dist[u]+1)
            {
                // If dfs for pair of v also returns
                // true
                if (dfs(pairV[v]) == true)
                {
                    pairV[v] = u;
                    pairU[u] = v;
                    return true;
                }
            }
        }
 
        // If there is no augmenting path beginning with u.
        dist[u] = INF;
        return false;
    }
    return true;
}
 
// Constructor
BipGraph::BipGraph(int m, int n)
{
    this->m = m;
    this->n = n;
    adj = new list<int>[m+1];
}
 
// To add edge from u to v and v to u
void BipGraph::addEdge(int u, int v)
{
    adj[u].push_back(v); // Add u to v’s list.
    //adj[v].push_back(u); // Add u to v’s list.
}


int main( int argc, char ** argv )
{
     uint32_t T;

     cin >> T;

     for (auto i=1u; i<=T; i++) {

          uint32_t N;
          cin >> N;

          map<string,uint32_t> m1;
          map<string,uint32_t> m2;
          vector<pii> edges;
          for (auto j=0u; j<N; j++)
          {
               string s1, s2;
               cin >> s1 >> s2;

               if (m1.find(s1) == m1.end())
               {
                    auto k = m1.size();
                    m1[s1] = k;
               }
               if (m2.find(s2) == m2.end())
               {
                    auto k = m2.size();
                    m2[s2] = k;
               }
               
               edges.push_back(make_pair(m1[s1], m2[s2]));
          }

          BipGraph g( m1.size(), m2.size());

          for (auto e : edges)
          {
               if (0) {
                    cerr << setw(2) << e.first+1 << " ";
                    cerr << setw(2) << e.second+1 << endl;
               }
               g.addEdge(e.first+1, e.second+1);

          }

          if (0) {
               for (auto u=1u; u<=m1.size(); u++)
               {
                    cerr << u << " : ";
                    for (auto v : g.adj[u]) {
                         cerr << v << " ";
                    }
                    cerr << endl;
               }
          }

          auto nn =  g.hopcroftKarp();

          //cerr << "max matching gives " << nn << endl;

          nn += m1.size()-nn + m2.size()-nn;

          auto a = N-nn;

          cout << "Case #" << i << ": ";
          cout << a ;

          cout << endl;
     }

     return 0;
}

