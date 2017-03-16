#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

typedef enum {ONE=1, I=2, J=3, K=4, MINUSONE=-1, MINUSI=-2, MINUSJ=-3, MINUSK=-4} _Quad;

const _Quad opList[5][5] = {{ONE,ONE,ONE,ONE,ONE},
                          {ONE,ONE,I,J,K},
                          {ONE,I,MINUSONE,K,MINUSJ},
                          {ONE,J,MINUSK,MINUSONE,I},
                          {ONE,K,J,MINUSI,MINUSONE}};

const char *convRes[] = { "NO", "YES" };

inline _Quad conv(char c) {
    switch(c) {
        case 'i': return I;
        case 'j': return J;
        case 'k': return K;
        default:;
    }
    return ONE;
}

class Quad {
    _Quad _data;
public:
    Quad(_Quad origin=ONE):
        _data(origin)
    {}

    Quad(char c):
        _data(conv(c))
    {}

    bool operator == (const _Quad other) const {
        return _data == other;
    }

    bool operator == (const Quad &other) const {
        return _data == other._data;
    }

    Quad operator * (const Quad &other) const {
        int flag = (other._data * _data < 0) ? -1 : 1;
        int tmp = (int)(opList[abs(_data)][abs(other._data)]) * flag;
        return Quad(_Quad(tmp));
    }

    Quad operator / (const Quad &other) const {
        int count = 0;
        for(int x=1; x<=4; x++) {
            if((other * Quad(_Quad(x))) == (*this)) {
                if(count != 0) throw "error";
                count = x;
            }
        }
        return Quad(_Quad(count));
    }

    Quad power(long long times) const {
        if(times < 0) throw "error";
        if(times == 0) return Quad();
        if(times == 1) return Quad(*this);
        if(times == 2) return (*this) * (*this);
        times = times & 3;
        Quad tmp = this->power(times >> 1);
        if(times & 1) return (*this) * tmp.power(2);
        return tmp.power(2);
    }
};


int a, t, l;
long long x;
Quad L;
bool res;
Quad myleft[10001], myright[10001];

int mymin(long long x, long long y) {
    if(x > y) return y;
    return x;
}

bool check() {
    for(int i=0; i<mymin(x, 4); i++) {
        for(int j=1; j<=l; j++) {
            if(L.power(i) * myleft[j] == I) {
                for(int b=0; b<=mymin(x-i-1, 3); b++) {
                    for(int c=l-1; c>=0; c--) {
                        int flag = (j<c) ? 0 : 1;
                        if(flag == 1 && (x-i-1==0)) break;
                        if(myright[c] * L.power(b) == K) {
                            /*long long tmp = x-1-b-i-flag;
                            if(tmp>0 || flag>0) {
                                if(myright[j] * L.power(x-1-b-i-flag) * myleft[c] == J) return true;
                            } else {
                                if((myleft[c] / myleft[j]) == J) return true;
                            }*/
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    cin >> t;
    string tmp;
    for(a=0; a<t; a++) {
        cin >> l >> x;
        cin >> tmp;

        L = Quad();
        for(int i=0; i<l; i++) {
            myleft[i] = L;
            L = L * Quad(tmp[i]);
        }
        myleft[l] = L;

        myright[l] = ONE;
        for(int i=l-1; i>=0; i--) {
            myright[i] = Quad(tmp[i]) * myright[i+1];
        }

        if(!(L.power(x) == MINUSONE)) res = false;
        else res = check();

        cout << "Case #" << a+1 << ": " << convRes[res] << endl;
    }
    return 0;
}

