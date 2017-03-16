#include <fstream>
#include <cstring>
using namespace std;
char buff[52] = {};
char sqbuff[101] = {};
int lensq = 0;
int lenOr = 0;
bool isPalindrome (const char a[], int sz) {

    for (int i = 0; i <= (sz-1) / 2; i++)
        if (a[i] != a[sz-i-1]) return false;
    return true;
}
bool inline testsqPal() {
    return isPalindrome(sqbuff, lensq);
}
bool testLEQ (const char a[], const char b[], int lenA, int lenB) {
    if (lenA > lenB) return false;
    if (lenB > lenA) return true;
    for (int i = lenA - 1 ; i >= 0; i--)
        if (a[i] != b[i]) return a[i] < b[i];
    return true;
}
bool testGEQ (const char a[], const char b[], int lenA, int lenB) {
    if (lenA < lenB) return false;
    if (lenB < lenA) return true;
    for (int i = lenA - 1 ; i >= 0; i--)
        if (a[i] != b[i]) return a[i] > b[i];
    return true;
}
void mulBuff(char out[], int & lenM, int num) {
    out[0] = buff[0] * num;
    for (int i = 1; i < lenOr; i++) {
        out[i] = out[i-1] / 10 + buff[i] * num;
        out[i-1] %= 10;
    }
    lenM = lenOr;
    if (out[lenOr-1] >= 10) {
        lenM++;
        out[lenOr] = out[lenOr-1] / 10;
        out[lenOr-1] %= 10;
    }
}
void add(char out[], char in[], int & lenA, int lenB, int off) {
    out[off] += in[0];
    if (lenA < lenB + off) {
        for (int i = off+1; i < lenA; i++) {
            out[i] += out[i-1] / 10 + in[i - off];
            out[i-1] %= 10;
        }
        for (int i = lenA; i < lenB + off; i++) {
            out[i] = out[i-1] / 10 + in[i - off];
            out[i-1] %= 10;
        }
        lenB += off;
        if (out[lenB -1] >= 10) {
            out[lenB] = out[lenB-1]/10;
            out[lenB-1] %= 10;
            lenB++;
        }
        lenA = lenB;
    }
    else {
        for (int i = off+1; i < lenB + off; i++) {
            out[i] += out[i-1] / 10 + in[i - off];
            out[i-1] %= 10;
        }
        if (out[lenA-1] >= 10) {
            out[lenA] = out[lenA-1] / 10;
            out[lenA - 1] %= 10;
            lenA++;
        }
    }
}
void getSqBuff() {
    for (int i = 0; i < 101; i ++)
        sqbuff[i] = 0;
    char buffMul[101] = {};
    lensq = 0;
    for (int i = 0; i < lenOr; i++) {
        int lenB = 0;
        mulBuff(buffMul,lenB,buff[i]);
        add(sqbuff,buffMul,lensq, lenB,i);
    }
}
unsigned int calcPalindrom(int stI, int enI, int len, const char a[], int lenA, const char b[], int lenB) {
    unsigned int c = 0;
    if (len <= 0) {
        getSqBuff();
        return (testLEQ(a, sqbuff, lenA, lensq) && testGEQ(b, sqbuff, lenB, lensq) && testsqPal()) ? (1) : (0);
    }
    // lenor
    for (int i = stI; i <= enI; i++) {
        buff[lenOr/2 - len/2] = i;
        buff[lenOr/2 -1 + lenOr%2 + len/2] = i;
        c += calcPalindrom(0, 9, len-2, a, lenA, b, lenB);
    }
    return c;
}
unsigned int countP( char a[],  char b[]) {
    int lenL = strlen(a);
    int stL = 1;
    int lenU = strlen(b);
    int enU = 9;
    
    int lenA = strlen(a);
    int lenB = strlen(b);
    for (int i = 0; i < lenL; i++)
        a[i] -= '0';
    for (int i = 0; i < lenU; i++) 
        b[i] -= '0';
 
        lenL = max(lenA/2 + lenA%2, 1);
    if (lenA %2 == 0) {
        stL = int(sqrt(a[0]*10 + a[1]));
        stL = max(1, stL);
    }
    else {
        stL = int(sqrt(a[0]));
        stL = max(1, stL);
    }
    if (lenB %2 == 0) {
        enU = int(sqrt(b[0]*10 + b[1])) + 1;
    }
    else {
        enU = int(sqrt(b[0])) + 1;
    }
        lenU = max(lenB/2 + lenB%2, 1);
        enU = min(9, enU);
    for (int i = lenA/2-1; i >=0; i--) {
        char c = a[i];
        a[i] = a[lenA - 1 - i];
        a[lenA - 1 - i] = c;
    }
    for (int i = lenB/2-1; i >=0; i--) {
        char c = b[i];
        b[i] = b[lenB - 1 - i];
        b[lenB - 1 - i] = c;
    }
    unsigned int cnt = 0;
    if (lenL == lenU) { // okay...
        lenOr = lenL;
        return calcPalindrom(stL, enU, lenL, a, lenA, b, lenB);
    }
    else {
        lenOr = lenL;
        cnt = calcPalindrom(stL, 9, lenL, a, lenA, b, lenB);
        lenOr = lenU;
        cnt += calcPalindrom(1, enU, lenU, a, lenA, b, lenB);
        for (int i = lenL+1; i < lenU; i++) {
            lenOr = i;
            cnt += calcPalindrom(1, 9, i, a, lenA, b, lenB);
        }
        return cnt;
    }
}

int main () {
    ifstream in("in.txt");
    ofstream out("out.txt");

    int n = 0;
    in >> n;
    char a[101], b[101];
    for (int i = 0; i < n; i++) {
        out << "Case #" << (i+1) << ": ";
        in >> a >> b;
        out << countP(a,b) << endl;
    }
    return 0;

}