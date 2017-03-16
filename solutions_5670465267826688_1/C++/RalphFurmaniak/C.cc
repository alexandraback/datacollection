#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
typedef long long i64;
#define fu(i,m,n) for(int i=m; i<n; i++)
#define fr(i,m,n) for(typeof(m) i=m; i!=n; i++)
#define fa(i,c) fr(i,(c).begin(),(c).end())

int _mult[5][5] = {
    {0, 0, 0, 0, 0},
    {0, 1, 2, 3, 4},
    {0,2, -1, 4, -3},
    {0,3, -4,-1, 2},
    {0,4, 3, -2, -1}}; 

char mult(char x, char y) {
    return 'g'+_mult[abs(x-'g')][abs(y-'g')]*(x>'g'?1:-1)*(y>'g'?1:-1);
}

int main(void) {

    /*for(char c='c'; c<='k'; c++) {
        for(char d='c'; d<='k'; d++) {
            cout << mult(c,d);
        }
        cout << endl;
    }
    cout << endl;*/

	int T;
	cin >> T;

	for(int ts=1; ts<=T; ts++) {
		cout << "Case #" << ts << ": ";
        int L;
        long X;
        cin >> L >> X;
        string s;
        cin >> s;

        char prods='h';
        //cout << s << endl;
        for(char x: s) {
            prods = mult(prods, x);
            //cout << prods;
        }

        char prodt='h';
        for(int i=0; i<X%4; i++)
            prodt = mult(prodt, prods);

        char cur='h';

        int i;
        for(i=0; i<min(10L,X)*L; i++) {
            cur=mult(cur, s[i%L]);
            if(cur=='i') break;
        }

        int k;
        for(k=i+1; k<min(20L,X)*L; k++) {
            cur=mult(cur, s[k%L]);
            if(cur=='k') break;
        }
        //cout << i << " " << k << " " << prods << " " << prodt << endl;

        cout << (i<min(10L,X)*L && k<min(20L,X)*L && prodt=='f' ? "YES" : "NO") << endl;

	}
}
