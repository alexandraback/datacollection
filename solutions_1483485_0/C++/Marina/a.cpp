#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int cifru[26];
string ex[3], decr[3], text;

void computeCipher()
{
    int i, j;
    for(i = 0; i < 3; ++i)
      for(j = 0; j < ex[i].size(); ++j)
        if(ex[i][j] != ' ')
            cifru[ex[i][j] - 'a'] = decr[i][j];
    cifru['z' - 'a'] = 'q';
    cifru['q' - 'a'] = 'z';
}

string decodeText(string enc)
{
    string dec = "";
    int i;
    for(i = 0; i < enc.size(); ++i)
        if(enc[i] != ' ') dec = dec + (char)(cifru[enc[i] - 'a']);
        else dec = dec + enc[i];
    return dec;
}
int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

    int t, i, j;
    
    ex[0] = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
    ex[1] = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
    ex[2] = "de kr kd eoya kw aej tysr re ujdr lkgc jv";

    decr[0] = "our language is impossible to understand";
    decr[1] = "there are twenty six factorial possibilities";
    decr[2] = "so it is okay if you want to just give up";

    computeCipher();  
    
    cin >> t;
    getline(cin, text);
    for(i = 1; i <= t; ++i)
    {
        getline(cin, text);
        cout << "Case #"<< i << ": " << decodeText(text) << "\n";
    }
    return 0;
}

