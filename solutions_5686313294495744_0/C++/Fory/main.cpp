#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

int main()
{
    int T;
    cin >> T;
    cerr << "T:" << T << '\n';
    for (int t=1;t<=T;t++) {
        int N;
        cin >> N;
        set<string> first, second;
        map<string, set<string> > existen;
        for (int n=0;n<N;n++) {
            string f, s;
            cin >> f >> s;
            first.insert(f);
            second.insert(s);
            if (existen.find(f)==existen.end())
            {
                set<string> nuevoset;
                nuevoset.clear();
                existen[f] = nuevoset;
            }
            existen[f].insert(s);
        }
        int64_t total=0;
        set<string>::iterator it;
        for (it = first.begin(); it != first.end(); ++it) {
            string f = *it;
            set<string>::iterator it2;
            for (it2 = second.begin(); it2 != second.end(); ++it2) {
                string s = *it2;
                if (existen[f].count(s)>0)
                    continue;
                total++;
            }
        }
        cout << "Case #" << t << ": " << total << '\n';
    }
    return 0;
}
