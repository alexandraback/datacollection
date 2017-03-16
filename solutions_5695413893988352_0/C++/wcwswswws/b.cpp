#include <string.h>
#include <fstream>
using namespace std;

bool Check(string s, string t, int pos) {
    for (int i = 0; i < pos; i++)
    if ((s[i] != t[i]) && (s[i] != '?') && (t[i] != '?')) { return false; }
    if (pos == s.length()) { return true; }
    if ((s[pos] == '?') || (t[pos] == '?') || (s[pos] != t[pos])) { return true; }
    return false;
}

long long ltoa(string s){
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        ans = ans * (long long)10 + (long long)(s[i] - '0');
    }
    return ans;
}

void big(string& s) {
    for (int i = 0; i < s.length(); i++)
    if (s[i] == '?') { s[i] = '9'; }
}

void small(string& s) {
    for (int i = 0; i < s.length(); i++)
    if (s[i] == '?') { s[i] = '0'; }
}
long long Work(string& a, string& b, int pos) {
    long long ans = 0;
    int n = a.length();
    for (int i = 0; i < pos; i++) {
        if (a[i] == '?') {
            if (b[i] == '?') { a[i] = b[i] = '0'; }
            else { a[i] = b[i]; }
        } else
        if (b[i] == '?') {
            b[i] = a[i];
        }
    }
    if (pos == n) { return ans; }
    ans = -1;
    string a_ans, b_ans;
    for (char i = '0'; i <= '9'; i++)
    for (char j = '0'; j <= '9'; j++) {
        string s = a, t = b;
        if (s[pos] == '?') { s[pos] = i; }
        if (t[pos] == '?') { t[pos] = j; }
        if (s[pos] < t[pos]) { big(s); small(t); }
        else { small(s); big(t); }
        long long temp = ltoa(s) - ltoa(t);
        if (temp < 0) { temp = -temp; }
        if ((ans == -1) || (temp < ans) || ((temp == ans) && (s < a_ans)) || ((temp == ans) && (s == a_ans) && (t < b_ans))) {
            ans = temp;
            a_ans = s;
            b_ans = t;
        }
    }
    a = a_ans;
    b = b_ans;
    return ans;
}

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("B-small-attempt1.in");
    fout.open("B-small-attempt1.out");

    int test;
    fin >> test;
    for (int t = 1; t <= test; t++) {
        fout << "Case #" << t << ": ";
        string a, b, a_ans, b_ans;
        fin>> a >> b;
        long long ans = -1;
        for (int i = 0; i <= a.length(); i++)
        if (Check(a, b, i)) {
            string s = a, t = b;
            long long temp = Work(a, b, i);
            if ((ans == -1) || (temp < ans) || ((temp == ans) && (a < a_ans)) || ((temp == ans) && (a == a_ans) && (b < b_ans))) {
                ans = temp;
                a_ans = a;
                b_ans = b;
            }
            a = s;
            b = t;
         }
         fout << a_ans << " " << b_ans << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
