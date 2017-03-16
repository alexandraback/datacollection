#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <fstream>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <list>
using namespace std;
#define FOR(i,a,b) for(int i=a; i<(int)b; i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair <int, int> pii;
#define debug(x) cerr << #x << " = " << (x) << \
" (L" << __LINE__ << ")" << " " << __FILE__ << endl;
template <class T> void debugall(T a, T b) { cerr << " (L" << __LINE__ << ") "; for(T i = a; i != b; i++) cerr << *i << ", "; cerr << endl; }


int main() {
    map <char, char> dict;
    ifstream ifs("a_dict");
    while(!ifs.eof()){
        char a, b;
        ifs >> a >> b;
        dict[a] = b;
    }
    dict[' '] = ' ';

	int zz;
	cin >> zz;
    char in[110];
    cin.getline(in, 1);
	FOR(z, 0, zz){
        memset(in, 0, sizeof(in));
        cin.getline(in, 101);
        char res[110];
        memset(res, 0, sizeof(res));
        int i = 0;
        while(in[i] != 0){
            res[i] = dict[in[i]];
            i++;
        }
		printf("Case #%d: ", z+1);
		printf("%s\n", res);
	}
}
