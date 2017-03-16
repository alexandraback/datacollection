#include <fstream>
#include <sstream>
#include <math.h>
using namespace std;

ifstream sf("fs.in");
ofstream vf("fs.out");

bool isPali (long long int x) {
    string s;
    stringstream ss;
    ss << x;
    s = ss.str();
    for (int i = 0; i < s.length()/2; i++) {
        if (s[i] != s[s.length()-i-1]) return false;
    }
    return true;
}

long long int a, b;
int n;

int main () {
    sf >> n;
    for (int j = 1; j <= n; j++) {
        sf >> a >> b;
        long long int x = sqrt(a);
        if (x*x < a) x++;
        long long int y = sqrt(b);
        
        int count = 0;
        for (long long int i = x; i <= y; i++) {
            if (isPali(i)) {
                if (isPali(i*i)) count++;   
            }
        }
        vf << "Case #" << j << ": " << count << endl;
    }
}
