# include <fstream>
# include <iostream>
# include <string>
# include <vector>
# include <math.h>
# include <algorithm>
# include <string.h>
# include <stack>
# include <queue>
# include <sstream>
# include <set>
# include <map>
using namespace std;
int main()
{
    //ios_base::sync_with_stdio(false);
    ifstream cin ("input.txt");
    ifstream voc("voc.txt");
    ofstream cout ("output.txt");
    vector<char> f(26);
    for (int i = 0; i < 26; i++)
        voc >> f[i] >> f[i];
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    for (int i = 0; i < n; i++)
    {
        cout << "Case #" << i + 1 << ": ";
        getline(cin, s);
        for (int i = 0; i < s.length(); i++)
            if (s[i] >= 'a' && s[i] <= 'z')
               cout << f[s[i] - 'a'];
            else
                cout << s[i];
        cout << endl;
    }
    //system("pause");
    return 0;
}
