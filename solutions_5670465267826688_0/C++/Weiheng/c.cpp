#include <iostream>
using namespace std;

bool jmark[20010][20010];
bool imark[20010];
bool kmark[20010];

char mat[8][9] = {
    "hijklmno",
    "ilknmhoj",
    "jolinkhm",
    "kjmlonih",
    "lmnohijk",
    "mhojilkn",
    "nkhmjoli",
    "onihkjml"
};

char op(char &x, char &y) {
    return mat[x-'h'][y-'h'];
}

bool verify(string str) {
    int i, j;
    char curr = 'h';
    for (i=0; i<str.size(); i++) {
        curr = op(curr, str[i]);
        if (curr == 'i')
            imark[i] = true;
        else
            imark[i] = false;
    }
    curr = 'h';
    for (i=str.size()-1; i>=0; i--) {
        curr = op(str[i], curr);
        if (curr == 'k')
            kmark[i] = true;
        else
            kmark[i] = false;
    }
    for (i=0; i<str.size(); i++) {
        curr = 'h';
        for (j=i; j<str.size(); j++) {
            curr = op(curr, str[j]);
            if (curr == 'j')
                jmark[i][j] = true;
            else
                jmark[i][j] = false;
        }
    }
    for (i=0; i<str.size(); i++) {
        if (!imark[i]) continue;
        for (j=i+1; j<str.size()-1; j++) {
            if (!jmark[i+1][j])continue;
            if (kmark[j+1]) return true;
        }
    }
    return false;
}

int main()
{
    int n, t, l, x;
    int i;
    string str, tmp;
    cin>>n;
    t = 1;
    while (t<=n) {
        cin>>l>>x;
        cin>>tmp;
        str="";
        for (i=0; i<x; i++)
            str+=tmp;
        if (verify(str))
            cout<<"Case #"<<t<<": YES"<<endl;
        else
            cout<<"Case #"<<t<<": NO"<<endl;
        t++;
    }
    return 0;
}
