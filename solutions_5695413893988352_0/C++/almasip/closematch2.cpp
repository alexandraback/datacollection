#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

string m1="", m2="";
int i1, i2;

bool ill(string mi, string mire) {

    int l = mi.length();
    for (int i=0; i<l; i++) {
        if (mire[i] != '?' && mire[i]!=mi[i])
            return false;
    }
    return true;
}

bool ill(char* mi, char* mire, int l) {

    for (int i=0; i<l; i++) {
        if (mire[i] != '?' && mire[i]!=mi[i])
            return false;
    }
    return true;
}

void probal(string s1, string s2) {

    if (s1.find("?") == string::npos && s2.find("?") == string::npos) {
        int i=atoi(s1.c_str()), j=atoi(s2.c_str());
        if (m1.length() == 0 || (abs(i2-i1) > abs(i-j) || (i<i1 || (i==i1 && j<i2)))) {
            i1=i; i2=j;
            m1=s1; m2=s2;
        }
    }
    for (int i=0; i<s1.length(); i++) {
        if (s1[i] == '?') {
            for (int j='0'; j<='9'; j++) {
                s1[i] = j;
                probal(s1, s2);
            }
            return;
        }
    }
    for (int i=0; i<s2.length(); i++) {
        if (s2[i] == '?') {
            for (int j='0'; j<='9'; j++) {
                s2[i] = j;
                probal(s1, s2);
            }
            return;
        }
    }
}

int main() {

    int test;
    cin >> test;
    for (int testcase=1; testcase<=test; testcase++) {

        //char s1[5], s2[5];
        string s1, s2;
        cin >> s1 >> s2;
        m1=""; m2="";
        i1=0; i2=0;
        probal(s1, s2);
        /*int l = strlen(s1);*/

        /*for (int i=0; i<pow(10, l); i++) {
            for (int j=0; j<999; j++) {
                //char c[5];
                char x1[5],  x2[5];
                if (l == 3) {
                    sprintf(x1, "%03d", i);
                //    x1 = string(c);
                    sprintf(x2, "%03d", j);
                //    x2 = string(c);
                }
                if (l == 2) {
                    sprintf(x1, "%02d", i);
                //    x1 = string(c);
                    sprintf(x2, "%02d", j);
                //    x2 = string(c);
                }
                if (l == 1) {
                    sprintf(x1, "%01d", i);
                //    x1 = string(c);
                    sprintf(x2, "%01d", j);
                //    x2 = string(c);
                }


                if (ill(x1, s1, l) && ill(x2, s2, l) && (m1.length() == 0 || (abs(i2-i1) > abs(i-j) || (i<i1 || (i==i1 && j<i2))))) {
                    i1=i; i2=j;
                    m1=x1; m2=x2;
                    //cout << i1 << " " << i2 <<endl;
                }
            }
        }*/

        cout << "Case #" << testcase << ": ";
        cout << m1 << " " << m2 << endl;
    }
    return 0;
}
