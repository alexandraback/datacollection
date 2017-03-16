#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
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
#include <ctime>
#define ALL(x) (x).begin(), (x).end()
#define FORE(i, x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())
#define FOR(i, x) for (int i = 0; i <x; i++)
#define FORI(i,x,y) for (int i = x; i <y; i++)
#define INF 10000

using namespace std;


int main(){
    freopen("A3L.in","r",stdin);
    freopen("A.out","w",stdout);
    int testCases;
    scanf("%d",&testCases);

    FOR (numberCase,testCases){
        int N;
        scanf("%d",&N);
        vector<vector<int> > matrix(N);

        //Lectura
        FOR(i,N){
            int m;
            scanf("%d",&m);
            FOR (j,m){
                int num;
                scanf("%d",&num);
                num--;
                matrix[i].push_back(num);
            }
        }


        //N busquedas por nivel
        bool sol=false;

        FOR (i,N){

            vector<bool> paso(N,false);
            vector<bool> recorridas(N,false);
            set<int> cola;
            cola.insert(i);
            int nivel=0;

            while (SZ(cola)){

                set<int> cola2;
                FORE (vertices,cola){
              //      cout<<nivel<<", "<<(*vertices)<<endl;
                    int vert=(*vertices);
                    FOR(j,SZ(matrix[vert])){
                        int destinoVert=matrix[vert][j];
                        if (!recorridas[destinoVert]){
                            cola2.insert(destinoVert);
                        }
                        if (!paso[destinoVert]){
                            paso[destinoVert]=true;
                        }
                        else{
                                sol=true;
                                break;
                        }

                    }
                    if (sol)
                        break;
                    recorridas[vert]=true;

                }
                if (sol)
                    break;
                cola=cola2;
                nivel++;
            }
            if (sol)
                break;
        }
        printf("Case #%d: ",numberCase+1);
        if (sol)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
