#include <iostream>
#include <cstdio>

using namespace std;

char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

bool isvowel(char a){
    for (int i = 0; i < 5; ++i){
        if (vowels[i] == a){
            return true;
        };
    };
    return false;
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i){
        string myin;
        int mynum;
        cin >> myin >> mynum;
        int lenconst[myin.length()];
        if (isvowel(myin[0])){
            lenconst[0] = 0;
        }
        else {
            lenconst[0] = 1;
        };
        for (int j = 1; j < myin.length(); ++j){
            if (isvowel(myin[j])){
                lenconst[j] = 0;
            }
            else {
                lenconst[j] = lenconst[j - 1] + 1;
            };
        };
        for (int j = 0; j < myin.length(); ++j){
            if (lenconst[j] >= mynum){
                lenconst[j] = 1;
            }
            else {
                lenconst[j] = 0;
            };
        };
/*        for (int j = 0; j < myin.length(); ++j){
            cout << lenconst[j] << endl;
        };
*/        int zerosbefore = 0;
        int myout = 0;
        bool myfirst = true;
        for (int j = 0; j < myin.length(); ++j){
            if (lenconst[j] == 0){
                zerosbefore += 1;
            }
            else {
                if (myfirst == true){
                    myout += (zerosbefore + 1 - (mynum - 1)) * (myin.length() - j);
                    myfirst = false;
                }
                else {
                    myout += (zerosbefore + 1 + mynum - 1 - (mynum - 1)) * (myin.length() - j);
                };
                zerosbefore = 0;
            };
        };
        cout <<  "Case #" << i + 1 << ": " << myout << endl;
    };



    return 0;
}
