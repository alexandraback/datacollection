#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<fstream>
#include<cmath>

using namespace std;

int tot;
long long r, t;

bool check(long long res) {
    return res * 2 + (2 * r - 1) <= t / res;
}

int main() {
    
    //FILE* fi = fopen("", "r");
    //FILE* fo = fopen("", "w");
    ifstream fi("A-small-attempt0.in");
    ofstream fo("output.txt");
    
    fi >> tot;
    int cnt = 0;
    while (tot > 0) {
        cnt++;
        fi >> r >> t;
        
        long long res = 0;
        long long left = 1;
        long long right = 707107000;
        
        while (right >= left) {
            long long tmp = (left + right) / 2;
            if (check(tmp)) {
                res = tmp;
                left = tmp + 1;
            }
            else
                right = tmp - 1;
        }
        
        //double res = 1.0 * (2 * r - 1) / 16 * (2 * r - 1);
        //res = res + 1.0 * t / 2;
        //res = sqrt(res);
        //res = res - 1.0 * (2 * r - 1) / 4;
        //long long re = (long long) res;
        
        fo << "Case #" << cnt << ": " << res << endl;
        
        tot--;
    }
    
    
    fi.close();
    fo.close();
    //fclose(fi);
    //fclose(fo);
    return 0;
}
