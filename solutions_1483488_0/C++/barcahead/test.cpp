#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;


int main() {
//    freopen("~/Desktop/in", "r", stdin);
//    freopen("~/Desktop/out", "w", stdout);
    ifstream cin("/Users/fengyelei/Desktop/in");
    ofstream cout("/Users/fengyelei/Desktop/out");
    int T;cin>>T;
    for (int c=1; c<=T; c++) {
        int A, B;
        cin>>A>>B;
        int ret = 0;
        int j = A, k=0;
        while (j/10) {j/=10,k++;}
        for (int i=A; i<B; i++) {
            j = i;
            do {
                j = (j%10)*pow(10.0,k)+j/10;
                if (j>i&&j<=B) ret++;
            }while(j!=i);
        }
        cout<<"Case #"<<c<<": "<<ret<<endl;
    }
}
