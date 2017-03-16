#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

    int test;
    cin >> test;
    for (int tc=1; tc<=test; ++tc) {
        int j, p, s, k;
        vector<int> jv, pv, sv;
        int db=0;
        cin>>j>>p>>s>>k;
        for (int a=1; a<=j; ++a) {
            for (int b=1; b<=p; ++b) {
                for (int c=1; c<=s; ++c) {
                    int jp=0,js=0,ps=0;
                    for (int i=0; i<db; ++i) {
                        if (jv[i] == a && pv[i] == b)
                            jp++;
                        if (jv[i] == a && sv[i] == c)
                            js++;
                        if (sv[i] == c && pv[i] == b)
                            ps++;
                    }
                    if (jp<k && js<k && ps<k) {
                        db++;
                        jv.push_back(a);
                        pv.push_back(b);
                        sv.push_back(c);
                    }
                }
            }
        }

        cout << "Case #" << tc << ": " << db << endl;
        for (int i=0; i<db; ++i) {
            cout << jv[i] << " " << pv[i] << " " << sv[i] << endl;
        }
    }
}
