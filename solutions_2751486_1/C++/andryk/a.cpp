#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;

bool isvowel(char v) {
    return v == 'a' ||
    v == 'e' || v == 'i' ||
    v == 'o' || v == 'u';
}

bool iscons(char c) {
    return !isvowel(c);
}

void run(int t) {
    string s;
    cin>>s;
    int n;
    cin>>n;

    queue<char> q;
    unsigned long long res = 0;
    int c = 0;
    int st = 0;
    for(int i = 0 ; i < s.size(); i++) {

        q.push(s[i]);
        if(iscons(s[i])) c++;

        if(q.size() > n) {
            if(iscons(q.front())) c--;
            q.pop();
        }

        if(n == c) {
            unsigned long long  a = i-n+1 - st + 1;
            unsigned long long  b = s.size() - i;
            res += (a) * (b);

            st = i - n+2;
        }

    }

    cout <<"Case #"<<t<<": " << res << endl;




}

int main() {


    int t;
    cin>>t;
    for(int i = 0; i < t ; i++) {

        run(i+1);
    }


}
