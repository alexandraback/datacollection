#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int convert(char a) {
    if (a == 'i') {
        return 2;
    }
    if (a == 'j') {
        return 3;
    }
    if (a == 'k') {
        return 4;
    }
    return 1;
}
int res(int a, int b) {
    if (a < 0) {
        return -1 * res(-a, b);
    }
    if (b < 0) {
        return -1 * res(a, -b);
    }
    if (a == 1) {
        return b;
    }
    if (b == 1) {
        return a;
    }
    if (a == b) {
        return -1;
    }
    if (a > b) {
        return -1 * res(b, a);
    }
    if (a == 2 && b == 3) {
        return 4;
    }
    if (a == 2 && b == 4) {
        return -3;
    }
    if (a == 3 && b == 4) {
        return 2;
    }
    return 0;
}

bool test(long l, long long x,string str) {
    int first = 1;
    int third = 1;
    int a = 0;
    size_t b = str.length();
    int c = 0;
    while (first != 2&& a < b) {
        first = res(first, convert(str[a]));
        a++;
    }
    while (third != 4 && b > 0) {
        third = res(convert(str[b-1]), third);
        b--;
        c++;
    }
    if (x*str.length()/4>=a+c&&first==2&&third==4) {
        return true;
    }
    return false;
}

bool result (long l, long long x, string str) {
    int tmp=1;
    for (long i = 0; i < str.length(); i++) {
        tmp = res(tmp, convert(str[i]));
    }
    if (tmp == 1) {
        return false;
    }
    if (tmp == -1) {
        if (x % 2 == 0) {
            return false;
        }
        return test(l,x, str + str+str + str);
    }
    if (x == 1) {
        return false;
    }
    if (x % 4 != 2) {
        return false;
    } else {
        return test(l,x, str + str+str + str);
    }
}

int main() {
    freopen("C-large.in","r",stdin);
    freopen("output3.txt","w",stdout);
    int t;
    long l;
    long long x;
    string str;
    scanf ("%i",&t);
    for (int i=0;i<t;i++) {
        cin >>l >> x;
        cin >> str;
        if (result(l, x, str))
            cout <<"Case #"<<i+1<<": YES" << endl;
        else
            cout <<"Case #"<<i+1<<": NO" << endl;
    }
    
    return 0;
}

    

    

    

    




