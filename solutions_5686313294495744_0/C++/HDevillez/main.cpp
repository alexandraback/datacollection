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
#define ull double
#define vi vector<int>
#define vii vector<ii>

#define UNVISITED 0
#define OPENED 1
#define CLOSED 2

#define NBNODE 2000


using namespace std;


map<string, int> dico;

int nodes[3000];
vector <int> adjList[3000];

int degree[3000];
int visited[3000][3000];

        
int main () {  

    int nCase;
    cin >> nCase;

    for(int iCase= 0; iCase < nCase; iCase++) {
    

        for(int i= 0; i < 3000; i++) {
            for(int j = 0; j < 3000; j++) {
                visited[i][j] = false;
            }
            degree[i] = 0;
        }
        dico.clear();



        int n;
        cin >> n;
        int id = 1;
        vector < pair <string, string> > tab;
        


        for(int i= 0; i < n; i++) {
            string a;
            string b;
            cin >> a >> b; 

            if( dico[a] ==  0){
                dico[a] = id;
                id++;
            }        
            if( dico[b] == 0) {
                dico[b] = id;
                id++;
            }
           /* cout << a << " " << b << endl;
            cout << dico[a] << " " << dico[b] << endl;*/

            if(visited[dico[a]][dico[b]]) continue;

             
            visited[dico[a]][dico[b]] = true;
            visited[dico[b]][dico[a]] = true;
            
            tab.push_back(make_pair(a, b));
        }     
        
        for(int i= 0; i < tab.size(); i++) {

            string a  = tab[i].first;
            string b = tab[i].second;

            int c = dico[a];
            int d = dico[b];

            bool ok = true;
            
            degree[c]++;
            degree[d]++;
        }
        int rep = 0;
        for(int i= 0; i < tab.size(); i++) {
            string a  = tab[i].first;
            string b = tab[i].second;

            int c = dico[a];
            int d = dico[b];
            if(degree[c] >= 2 && degree[d] >= 2) {
                rep++;
            }
        }   
        printf("Case #%d: %d\n", iCase+1, rep);      

    }
      
        
    
    return 0;
}
