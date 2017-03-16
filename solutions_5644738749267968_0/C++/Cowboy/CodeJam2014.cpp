/*
 *ID:   Cowboy
 *TASK:
 *Judge:
 */
#include <bits/stdc++.h>
#define INF 0x7fffffff
#define PI 2*acos(0.0)
#define EPS 10E-9
using namespace std;

#define PB(t) push_back(t)
#define ALL(t) t.begin(),t.end()
#define MP(x, y) make_pair((x), (y))
#define Fill(a,c) memset(&a, c, sizeof(a))

int main( ){
    freopen("D-small.in","r",stdin);
    freopen("solution.out","w",stdout);
    int T, k = 0, n, res1, res2;
    for( cin>>T; k<T; k++){
        cin>>n;
        vector<double>naomi(n);
        vector<double>ken(n);

        //Lectura de Naomi
        for(int i=0; i<n; i++){
            cin>>naomi[i];
        }

        //Lectura de Ken
        for(int i=0; i<n; i++){
            cin>>ken[i];
        }

        sort( ALL(naomi) );
        sort( ALL(ken) );
//cout<<endl;cout<<endl;
//        for(int i=0; i<n; i++){
//            cout<<" "<<naomi[i];
//        }
//        cout<<endl;
//        for(int i=0; i<n; i++){
//            cout<<" "<<ken[i];
//        }
//        cout<<endl;
//cout<<endl;cout<<endl;
        res1 = res2 = 0;

        //Solucion
        int i, j = 0;
        for( i=0; j<n && i<n; i++, j++){
            while( j<n && naomi[i]>ken[j] )
                j++;
            if( j>=n )
                break;
        }
        res2 = n-i;


        int idxfKen = n;
        //Quitar mayores
        //Quitar menores
        for(i=0, j=0; j<idxfKen && i<n; i++, j++){
            if( naomi[i]>ken[j] ){
                res1++;
            } else {
              idxfKen--;
              j--;
            }
        }
        res1+=n-i;

        printf("Case #%d: %d %d\n", k+1, res1, res2);

    }

return 0;
}
