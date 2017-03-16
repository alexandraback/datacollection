#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

class Number {
    
    static const unsigned int SIZE = 200;
    char digits[SIZE];
    
public:
    Number(const char *n);
    void print();
    Number simpleSquare();

    bool operator==(const Number &n) {
        for (int i=0; i<SIZE; i++) {
            if (digits[i] != n.digits[i]) return false;
        }
        return true;
    }
    bool operator !=(const Number &n) {
        return !operator ==(n);
    }
    
    friend bool operator>(const Number &a, const Number &b);
    friend bool operator<(const Number &a, const Number &b);
    friend bool operator>=(const Number &a, const Number &b);
    friend bool operator<=(const Number &a, const Number &b);
};

bool operator>(const Number &a, const Number &b) {
    for (int i=a.SIZE-1; i >= 0; i--) {
        if (a.digits[i] > b.digits[i]) {
            return true;
        } else if (a.digits[i] < b.digits[i]) {
            return false;
        }
    }
    return false;
}

bool operator>=(const Number &a, const Number &b) {
    for (int i=a.SIZE-1; i >= 0; i--) {
        if (a.digits[i] > b.digits[i]) {
            return true;
        } else if (a.digits[i] < b.digits[i]) {
            return false;
        }
    }
    return true;
}

bool operator<(const Number &a, const Number &b) {
    for (int i=a.SIZE-1; i >= 0; i--) {
        if (a.digits[i] < b.digits[i]) {
            return true;
        } else if (a.digits[i] > b.digits[i]) {
            return false;
        }
    }
    return false;
}

bool operator<=(const Number &a, const Number &b) {
    for (int i=a.SIZE-1; i >= 0; i--) {
        if (a.digits[i] < b.digits[i]) {
            return true;
        } else if (a.digits[i] > b.digits[i]) {
            return false;
        }
    }
    return true;
}

Number::Number(const char *n) {
    memset(digits, 0, SIZE);

    int len = 0;
    while (n[len]) { len++; }
        
    for (int i=0; i < len; i++) {
        digits[i] = n[len-1-i] - 48; // non-ASCII
    }
}

void Number::print() {
    bool leading_zero = true;
    for (int i = SIZE-1; i >= 0; i--) {
        if(leading_zero == true && digits[i] == 0) continue;
        leading_zero = false;
        cout << (int) digits[i];
    }
    cout << endl;
}

Number Number::simpleSquare() {
    char sqr[SIZE+1] = { 0 };
    
    for (int i=0; i<100; i++) {  // TODO SIZE/2
        for (int j=0; j<100 ; j++) {
            sqr[SIZE-1-(j+i)] += digits[j] * digits[i]; // back to ASCII
        }
    }
    for (int i =0; i < 200; i++) {
            sqr[i] = sqr[i] + 48; // back to ASCII
    }
    return Number(sqr);
}

vector<Number> fsList;

void addEvenNumber(const char *n, int len) {
    char p[200] = { 0 };
    for (int i=0; i < len; i++) {
        p[i] = n[i];
        p[2*len-1-i] = n[i];
    }
    Number palindrome(p);
    fsList.push_back(palindrome.simpleSquare());
}

void addOddNumber(const char *n, int len, unsigned char c) {
    char p[200] = { 0 };
    for (int i=0; i < len; i++) {
        p[i] = n[i];
        p[2*len-i] = n[i];
    }
    p[len] = c;
    Number palindrome(p);
    fsList.push_back(palindrome.simpleSquare());
}

void createAllFairAndSquareNumbers() {
    // len = 0 special case
    addOddNumber("", 0, '1');  // cost 1
    addOddNumber("", 0, '2');  // cost 4
    addOddNumber("", 0, '3');  // cost 9

    // len greater than zero
    for (int len=1; len<=25; len++) {

        // cost per number must be less than 10!
        char n[len];

        // case leading 1
        
        // no additional 1's
        memset(n, '0', len);
        n[0] = '1';  // cost 2
        addEvenNumber(n, len);
        if (len != 25) {
            addOddNumber(n, len, '0');  // cost 0
            addOddNumber(n, len, '1');  // cost 1
            addOddNumber(n, len, '2');  // cost 4
        }

        // one additional 1
        if (len >= 2) {
            for (int i=1; i<len; i++) {
                memset(n, '0', len);
                n[0] = '1';  // cost 2
                n[i] = '1';      // cost 2
                addEvenNumber(n, len);
                if (len != 25) {
                    addOddNumber(n, len, '0');  // cost 0
                    addOddNumber(n, len, '1');  // cost 1
                    addOddNumber(n, len, '2');  // cost 4
                }
            }
        }
        
        // two additional 1's
        if (len >= 3) {
            for (int i=1; i<len-1; i++) {
                for (int j=i+1; j<len; j++) {
                    memset(n, '0', len);
                    n[0] = '1';  // cost 2
                    n[i] = '1';      // cost 2
                    n[j] = '1';      // cost 2
                    addEvenNumber(n, len);
                    if (len != 25) {
                        addOddNumber(n, len, '0');  // cost 0
                        addOddNumber(n, len, '1');  // cost 1
                    }
                }
            }
        }
        
        // three additional 1's
        if (len >= 4) {
            for (int i=1; i<len-2; i++) {
                for (int j=i+1; j<len-1; j++) {
                    for (int k=j+1; k<len; k++) {
                        memset(n, '0', len);
                        n[0] = '1';  // cost 2
                        n[i] = '1';      // cost 2
                        n[j] = '1';      // cost 2
                        n[k] = '1';      // cost 2
                        addEvenNumber(n, len);
                        if (len != 25) {
                            addOddNumber(n, len, '0');  // cost 0
                            addOddNumber(n, len, '1');  // cost 1
                        }
                    }
                }
            }
        }

        // case leading 2
        memset(n, '0', len);
        n[0] = '2';  // cost 8
        addEvenNumber(n, len);
        if (len != 25) {
            addOddNumber(n, len, '0');  // cost 0
            addOddNumber(n, len, '1');  // cost 1
        }
    }
}

void testcase(int _t)
{
    string A, B;
    
    cin >> A;
    cin >> B;
    
    Number nA(A.c_str());
    Number nB(B.c_str());

    long int count = 0;
    for (int i=0; i < fsList.size(); i++) {
      Number v = fsList[i];
      if (v >= nA && v <= nB) count++;
    }
    
    cout << "Case #" << _t << ": ";
    cout << count;
    cout << endl;
}

int main(int argc, char** argv) {
    int T;
    cin >> T;
    
    createAllFairAndSquareNumbers();
    
    for (int t=1; t<=T; t++) {
        testcase(t);
    } 
}
