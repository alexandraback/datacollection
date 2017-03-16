#include<bits/stdc++.h>

using namespace std;

int main() {
    int T;
    string S;
    int digit[10];
    int count[27];
    int temp;

    cin >> T;
    for(int testcase=1;testcase<=T;testcase++) {
        cin >> S;
        memset(count, 0, sizeof(count));
        for(int i = 0;i < S.length();i ++) {
            count[S[i]-'A'] ++;
        }
        memset(digit, 0, sizeof(digit));
        digit[0] = count['Z'-'A'];
        for(int i = 0;i < digit[0];i ++) {
            count['Z'-'A'] --;
            count['E'-'A'] --;
            count['R'-'A'] --;
            count['O'-'A'] --;
        }
        digit[2] = count['W'-'A'];
        for(int i = 0;i < digit[2];i ++) {
            count['T'-'A'] --;
            count['W'-'A'] --;
            count['O'-'A'] --;
        }
        digit[4] = count['U'-'A'];
        for(int i = 0;i < digit[4];i ++) {
            count['F'-'A'] --;
            count['O'-'A'] --;
            count['U'-'A'] --;
            count['R'-'A'] --;
        }
        digit[6] = count['X'-'A'];
        for(int i = 0;i < digit[6];i ++) {
            count['S'-'A'] --;
            count['I'-'A'] --;
            count['X'-'A'] --;
        }
        digit[8] = count['G'-'A'];
        for(int i = 0;i < digit[8];i ++) {
            count['E'-'A'] --;
            count['I'-'A'] --;
            count['G'-'A'] --;
            count['H'-'A'] --;
            count['T'-'A'] --;
        }
        digit[1] = count['O'-'A'];
        for(int i = 0;i < digit[1];i ++) {
            count['O'-'A'] --;
            count['N'-'A'] --;
            count['E'-'A'] --;
        }
        digit[3] = count['T'-'A'];
        for(int i = 0;i < digit[3];i ++) {
            count['T'-'A'] --;
            count['H'-'A'] --;
            count['R'-'A'] --;
            count['E'-'A'] --;
            count['E'-'A'] --;
        }
        digit[5] = count['F'-'A'];
        for(int i = 0;i < digit[5];i ++) {
            count['F'-'A'] --;
            count['I'-'A'] --;
            count['V'-'A'] --;
            count['E'-'A'] --;
        }
        digit[7] = count['S'-'A'];
        for(int i = 0;i < digit[7];i ++) {
            count['S'-'A'] --;
            count['E'-'A'] --;
            count['V'-'A'] --;
            count['E'-'A'] --;
            count['N'-'A'] --;
        }
        digit[9] = count['I'-'A'];
        for(int i = 0;i < digit[9];i ++) {
            count['N'-'A'] --;
            count['I'-'A'] --;
            count['N'-'A'] --;
            count['E'-'A'] --;
        }
        cout << "Case #" << testcase << ": ";
        for(int i=0;i<=9;i++) {
            for(int j=0;j<digit[i];j++) cout<<i;
        }
        cout << endl;
    }
    return 0;
}
