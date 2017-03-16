#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

int main() {
    freopen("A-small-attempt4.in","r",stdin);
	freopen("A-small-attempt4.out","w",stdout);
    int T,case_id,N,i,X,rel_case,rel_X;
    long double threshold,rel_threshold,val;
    cin >> T;
    cout << fixed;
    cout << setprecision (6);
    for (case_id=1; case_id<=T; ++case_id) {
        cin >> N;
        cout << "Case #" << case_id << ":";
        int s[N];
        X=0;
        for (i=0;i<N;++i) {
            cin >> s[i];
            X += s[i];
        }
        threshold = 2.0*(double)X/(double)N;
        rel_case = N;
        rel_X = X;
        //cout << rel_case << " " << rel_X << endl;
        for (i=0;i<N;++i) {
            if ((double)s[i]>threshold) {
                --rel_case;
                rel_X -= s[i];
            }
        }
        //cout << rel_case << " " << rel_X << endl;
        rel_threshold = ((double)X+(double)rel_X)/(double)rel_case;
        //cout << rel_threshold << endl;
        
        for (i=0;i<N;++i) {
            if (rel_threshold>0.0000001) {
                //cout << "1\n";
                if ((double)s[i]>threshold+0.0000001) val=0;
                else val = (rel_threshold-(double)s[i])/(double)X*100.0;
            } else {
                //cout << "2\n";
                if ((double)s[i]>threshold+0.0000001) val=0;
                else val = 1.0/(double)rel_case*100.0;
            }
            
            cout << " " << val;
        }
        cout << endl;
    }
    return 0;
}
