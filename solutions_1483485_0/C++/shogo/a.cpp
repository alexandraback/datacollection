#include <iostream>

using namespace std;

char *map = "                                                                                                 yhesocvxduiglbkrztnwjpfmaq                                                                                                                                     ";

int main()
{
    string dummy;
    int T;
    cin >> T;
    getline(cin, dummy);

    for(int i=1;i<=T;++i) {
        string s;
        getline(cin, s);
        for(int j=0;j<(int)s.size();++j) {
            s[j] = map[s[j]];
        }
        cout << "Case #" << i << ": " << s << endl;
    }
    return 0;
}
