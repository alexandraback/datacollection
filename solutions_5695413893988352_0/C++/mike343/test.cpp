#include<iostream>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<list>
#include<queue>
#include<bitset>
#include<assert.h>
using namespace std;

string getMin(string str){
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '?')
            str[i] = '0';
    }
    return str;
}
string getMax(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '?')
            str[i] = '9';
    }
    return str;
}

int getResult(string str1, string str2, string& val1, string& val2) {
    for (int i = 0; i < str1.length(); i++) {
        if (str1[i] == '?' && str2[i] == '?') {
            if (i + 1 == str1.length()) {
                str1[i] = str2[i] = '0';
                val1 = str1;
                val2 = str2;
                return abs(stoi(val1) - stoi(val2));
            } else {
                if (str1[i+1] == '?' && str2[i+1] == '?') {
                    str1[i] = str2[i] = '0';
                } else {
                    int diff = INT_MAX;
                    string v1; string v2;
                    str1[i] = str2[i] = '0';
                    int d = getResult(str1, str2, v1, v2);
                    if (d < diff || (d == diff && (v1 < val1||(v1==val1 && v2 < val2)) )) {
                        diff = d;
                        val1 = v1;
                        val2 = v2;
                    } 
                    str1[i] = '1'; str2[i] = '0';
                    d = getResult(str1, str2, v1, v2);
                    if (d < diff || (d == diff && (v1 < val1||(v1==val1 && v2 < val2)) )) {
                        diff = d;
                        val1 = v1;
                        val2 = v2;
                    }
                    str1[i] = '0'; str2[i] = '1';
                    d = getResult(str1, str2, v1, v2);
                    if (d < diff || (d == diff && (v1 < val1||(v1==val1 && v2 < val2)) )) {
                        diff = d;
                        val1 = v1;
                        val2 = v2;
                    }
                    return abs(stoi(val1)-stoi(val2));
                }
            }
        } else if (str1[i] == '?') {
            str1[i] = str2[i];
               int diff = INT_MAX;
                    string v1; string v2;
                    int d = getResult(str1, str2, v1, v2);
                    if (d < diff || (d == diff && (v1 < val1||(v1==val1 && v2 < val2)) )) {
                        diff = d;
                        val1 = v1;
                        val2 = v2;
                    }
      
            str1[i] = str2[i] == '9' ? '0' : str2[i]+1;
            d = getResult(str1, str2, v1, v2);
                    if (d < diff || (d == diff && (v1 < val1||(v1==val1 && v2 < val2)) )) {
                        diff = d;
                        val1 = v1;
                        val2 = v2;
                    }

            str1[i] = str2[i] == '0' ? '9' : str2[i]-1;
            d = getResult(str1, str2, v1, v2);
                    if (d < diff || (d == diff && (v1 < val1||(v1==val1 && v2 < val2)) )) {
                        diff = d;
                        val1 = v1;
                        val2 = v2;
                    }

            return abs(stoi(val1)-stoi(val2));

        } else if (str2[i] == '?') {
            str2[i] = str1[i];
               int diff = INT_MAX;
                    string v1; string v2;
                    int d = getResult(str1, str2, v1, v2);
                    if (d < diff || (d == diff && (v1 < val1||(v1==val1 && v2 < val2)) )) {
                        diff = d;
                        val1 = v1;
                        val2 = v2;
                    }
      
            str2[i] = str1[i] == '9' ? '0' : str1[i]+1;
            d = getResult(str1, str2, v1, v2);
                    if (d < diff || (d == diff && (v1 < val1||(v1==val1 && v2 < val2)) )) {
                        diff = d;
                        val1 = v1;
                        val2 = v2;
                    }

            str2[i] = str1[i] == '0' ? '9' : str1[i]-1;
            d = getResult(str1, str2, v1, v2);
                    if (d < diff || (d == diff && (v1 < val1||(v1==val1 && v2 < val2)) )) {
                        diff = d;
                        val1 = v1;
                        val2 = v2;
                    }

            return abs(stoi(val1)-stoi(val2));


        } else {
            if (str1[i] > str2[i]) {
                val1 = getMin(str1);
                val2 = getMax(str2);
                return abs(stoi(val1)-stoi(val2));
            } else if (str1[i] < str2[i]) {
                val1 = getMax(str1);
                val2 = getMin(str2);
                return abs(stoi(val1)-stoi(val2));
            }
        }
    }
    val1 = str1;
    val2 = str2;
    return abs(stoi(val1)-stoi(val2));
            
}

int main() {

   int numCase = 1000000;
    cin >> numCase; 
    for (int i = 0; i < numCase; i++) {
        string str1;
        cin >> str1;

        string str2;
        cin >> str2;
        cout <<"Case #"<<(i+1)<<": ";
        string a1;
        string a2;
        getResult(str1, str2, a1, a2);
        cout <<a1<<" "<<a2 << endl; 
    }
}
