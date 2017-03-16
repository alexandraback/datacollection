#include <iostream>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <iomanip>


using namespace std;

int t;

string c, j;
int l;
unsigned long long  mindist;

bool check(string s, int k) {
    for (int i = s.length()-1; i >= 0; i--) {
        if (s[i] != '?' && (s[i]-'0' != (k%10)))
            return 0;
        k /= 10;
    }
    return 1;
}

string a, b, aa, bb;



unsigned long long dist(string u, string v) {
    unsigned long long x = 0, y = 0;
    unsigned long long r = 1;

    for (int i = u.length()-1; i >= 0; i--)  {
        x += r*(u[i]-'0');
        y += r*(v[i]-'0');
        r *= 10;
    }

    return ((x>y)?(x-y):(y-x));
}

bool smaller(string u, string v) {
    unsigned long long x = 0, y = 0;
    unsigned long long r = 1;

    for (int i = u.length()-1; i >= 0; i--)  {
        x += r*(u[i]-'0');
        y += r*(v[i]-'0');
        r *= 10;
    }

    return ((x<y)?1:0);
}


void maxmin(int d) {
    for (int i = d; i < l; i++) {
        if (a[i] == '?')
            a[i] = '9';
        if (b[i] == '?')
            b[i] = '0';  
    }
}

void minmax(int d) {
    //cout << a << " " << b << endl;
    for (int i = d; i < l; i++) {
        if (a[i] == '?')
            a[i] = '0';
        if (b[i] == '?')
            b[i] = '9';  
    }
    //cout << a << " " << b << endl;
}

void rec(int d) {
    if (d >= l) {
       // cout << a << " " << b<<" "<<dist(a, b) << endl;

        if (dist(a,b) == mindist) {
          //  cout << a << endl;
            if (smaller(a, aa)) {
                aa = a;
                bb = b;
            } else if (dist(a, aa) == 0) {
                if (smaller(b, bb)) {
                    bb = b;
                }

            }
        }

        if (dist(a,b) < mindist) {
            aa = a;
            bb = b;
            mindist = dist(a,b);
        }
        return;
    }
    
    if (d > 0) {
        if (a[d-1] > b[d-1]) {
//                cout << "doo" << endl;
            minmax(d);
            rec(l);
            for (int i = d; i < l; i++) {
                a[i] = c[i];
                b[i] = j[i];
            }

            return ;
        } else if (a[d-1] < b[d-1]) {
            maxmin(d);
            rec(l);
            for (int i = d; i < l; i++) {
                a[i] = c[i];
                b[i] = j[i];
            }

return ;
        }
    }

    if (c[d] != '?' && j[d] != '?')
        rec(d+1);
    else if (c[d] == '?' && j[d] == '?') {
        a[d] = '0'; b[d] = '0';
        rec(d+1);
        a[d] = '0'; b[d] = '1';
        rec(d+1);
        a[d] = '1'; b[d] = '0';
        rec(d+1);
        
        a[d] = '0'; b[d] = '9';
        rec(d+1);
        a[d] = '9'; b[d] = '0';
        rec(d+1);


    } else if (c[d] == '?') {
        if (j[d] > '0') {
            a[d] = j[d]-1;
            rec(d+1);
        } else {
            a[d] = '9';
            rec(d+1);
        }
        
        a[d] = j[d];
        rec(d+1);

         if (j[d] < '9') {
            a[d] = j[d]+1;
            rec(d+1);
        } else {
            a[d] = '0';
            rec(d+1);
        }
         

    } else if (j[d] == '?') {
         if (c[d] > '0') {
            b[d] = c[d]-1;
            rec(d+1);
        } else {
            b[d] = '9';
            rec(d+1);
        }

        
        b[d] = c[d];
        rec(d+1);

         if (c[d] < '9') {
            b[d] = c[d]+1;
            rec(d+1);
        } else {
            b[d] = '0';
            rec(d+1);
        }

        
    }
    
}

int main() {
    cin >> t;

    for (int i = 1; i <= t; i++) {
        cout << "Case #"<<i<<": ";

        cin >> c >> j;
        
        l = c.length();
        a = c;
        b = j;
        
        mindist = (1LL<<63);
        //cout << mindist<<endl;
        rec(0);
        
 /*       int p[4] = {1, 10, 100, 1000};
        int mindist = 100000;
        int aa, bb;

        for (int a = 0; a < p[l]; a++)
            for (int b = 0; b < p[l]; b++) {
                //cout << a << " " << b << endl; 
                
                if (check(c, a) && check(j, b)) {
                    if (abs(a-b) < mindist) {
                        aa = a;
                        bb = b;
                        mindist = abs(a-b);
                    }
                }
            }
        
        //cout << l << endl; 
   */
        std::cout << std::setfill('0') << std::setw(l) <<  aa <<" "  << std::setfill('0') << std::setw(l) << bb << endl;   
    }

    return 0;
}
