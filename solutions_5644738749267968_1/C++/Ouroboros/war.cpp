#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <list>

using namespace std;

// global
int T;
int N;



int main() {
  cin >> T;
  int run = 0;
  while (run++ < T) {
    fprintf(stderr,"doing case %d\n",run);
    cin >> N;
    vector<double> nao,ken;
    nao.resize(N);
    ken.resize(N);
    for (int i = 0;i < N;i++) cin >> nao[i];
    for (int i = 0;i < N;i++) cin >> ken[i];
    sort(nao.begin(),nao.end());
    sort(ken.begin(),ken.end());
    list<double> ken2(ken.begin(),ken.end());

/*     printf("nao: ");
 *     for (auto &x : nao) {
 *       printf("%.3f ",x);
 *     }
 *     printf("\n");
 * 
 *     printf("ken: ");
 *     for (auto &x : ken) {
 *       printf("%.3f ",x);
 *     }
 *     printf("\n");
 */

    //calc normal war
    int normal = 0;
    int i,j;
    i = j = N-1;
    while (i >= 0 && j >= 0) {
      if (nao[i] > ken[j])
        i--;
      else {
        i--;
        j--;
        normal++;
      }
    }
    normal = N - normal;

    //calc deceit
    int deceit = 0;
    i = j = 0;
    while (i < N && j < N) {
      if (nao[i] < ken[j]) {
        i++;
      } else {
        i++;
        j++;
        deceit++;
      }
    }

    printf("Case #%d: %d %d\n",run,deceit,normal);
  }
}
