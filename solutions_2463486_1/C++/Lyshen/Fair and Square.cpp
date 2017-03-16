#include <fstream>
#include <iostream>
using namespace std;

long long pal[100] = {
0, 1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201,
104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001, 10221412201, 12102420121, 12345654321, 40000800004, 1000002000001, 1002003002001, 1004006004001, 1020304030201,
1022325232201, 1024348434201, 1210024200121, 1212225222121, 1214428244121, 1232346432321, 1234567654321, 4000008000004, 4004009004004
};

int find(long long x) {
          int i;
          for(i=0; i<39; i++) {
                    if (pal[i] <= x && x < pal[i+1]) return i;
          }
          return i;
}

int main() {
          //ifstream in("C-large-1.in");
          //ofstream out("C-large-1.out");

          int T,na,nb;
          long long a,b;
          cin >> T;
          for(int tc=1; tc<=T; tc++) {
                    cin >> a >> b;
                    na = find(a-1);
                    nb = find(b);
                    cout << "Case #" << tc << ": " << nb-na << endl;
          }
          return 0;
}
