#include <iostream>
using namespace std;
struct node {
     int n;
     int next;
};
const int maxn = 1007;

int n;
node tree[maxn];
node pool[maxn*15];
int ai;
bool vi[maxn];
void init()
{
     memset(tree, 0, sizeof(tree));
     memset(pool, 0, sizeof(pool));
     ai = 1;
     
     cin >> n;
     for (int i=1; i<=n; i++) {
          cin >> tree[i].n;
          for (int j=0; j<tree[i].n; j++) {
               int p = tree[i].next;
               tree[i].next = ai++;
               cin >> pool[tree[i].next].n;
               pool[tree[i].next].next = p;
          }
     }


     // for (int i=1; i<=n; i++) {
     //      cout << "node " << i << ":" << endl;
     //      int p = tree[i].next;
     //      while (p) {
     //           cout << pool[p].n << ' ';
     //           p = pool[p].next;
     //      }
     //      cout << endl;
     // }
}

bool calc(int no)
{
     // cout << "calc(" << no << ")" << endl;
     vi[no] = true;
     // for (int i=1; i<=n; i++) cout << vi[i] << ' ';
     // cout << endl;
     int p = tree[no].next;
     while (p) {
          // if (pool[p].n == 5) cout << "here" << endl;
          // cout << pool[p].n << endl;
          // if (no == 4 && pool[p].n == 5) cout << "here" << vi[pool[p].n] << endl;
          if (vi[pool[p].n]) {
               return true;
          } else {
               if (calc(pool[p].n)) {
                    return true;
               }
          }
          p = pool[p].next;
     }
     return false;
}

int main()
{
     int T;
     cin >> T;
     for (int t=1; t<=T; t++) {
          bool flag = false;
          init();
          for (int i=1; i<=n; i++) {
               // cout << "i = " << i << endl;
               memset(vi, 0, sizeof(vi));
               if (calc(i)) {
                    flag = true;
                    break;
               }
          }
          cout << "Case #" << t << ": ";
          if (flag) {
               cout << "Yes" << endl;
          } else {
               cout << "No" << endl;
          }
     }
     return 0;
}
