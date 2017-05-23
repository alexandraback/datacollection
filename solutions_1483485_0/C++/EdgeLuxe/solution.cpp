#include <string>
#include <iostream>
#include <cstdio>
using namespace std;

//                'a' 'b' 'c' 'd' 'e' 'f' 'g' 'h' 'i' 'j' 'k' 'l' 'm' 'n' 'o' 'p' 'q' 'r' 's' 't' 'u' 'v' 'w' 'x' 'y' 'z'
char replace[] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

int main()
{
    /*freopen("d.txt", "r", stdin);
    freopen("file.out", "w", stdout);*/

    int t;
    string str;

    cin >> t;
    getline(cin, str);

    for(int i = 1; i <= t; ++i)
    {
        getline(cin, str);
        for(int k = 0; k < str.size(); ++k)
        {
            if(str[k] != ' ') str[k] = replace[str[k]-'a'];
        }
        cout << "Case #" << i << ": " << str << endl;
    }

    return 0;
}
