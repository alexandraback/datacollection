/* 
 * File:   Dijkstra.cpp
 * Author: Uday Kandpal
 *
 * Created on 11 April, 2015, 10:07 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstdio>

using namespace std;

int I = 2, J = 3, K = 4, O = 1, E = 0;

int matrix[5][5] = {
    {E, E, E, E, E}, //E => extra (to set index offset for adjustment)
    {E, O, I, J, K},
    {E, I, -O, K, -J},
    {E, J, -K, -O, I},
    {E, K, J, -I, -O}
};

int getTransform(int i1, int i2) {
    int x = 1;
    if (i1 < 0) {
        x *= -1;
        i1 *= -1;
    }
    if (i2 < 0) {
        x *= -1;
        i2 *= -1;
    }
    //cout << "matrix[i = " << i1 << "][j = " << i2 << "] = " << x * matrix[i1][i2] << endl;
    return x * matrix[i1][i2];
}

int getValue(char e) {
    //cout << e << " ";
    if (e == '1')
        return O;
    else if (e == 'i')
        return I;
    else if (e == 'j')
        return J;
    else if (e == 'k')
        return K;
}

char data[10004];

/*
 * 
 */
int main(int argc, char** argv) {
    int t, l, caseNo = 1;
    long long x, product;

    freopen("C-small-attempt2.in", "r+", stdin);
    freopen("dijkstra.txt", "w+", stdout);
    cin>>t;
    while (t--) {
        cin >> l>>x;
        cin>>data;
        product = l * x;
        int iFound = 0, jFound = 0, kFound = 0;
        int splitComplete = 0;
        int calculated = O;
        for (int i = 0; i < product; i++) {
            calculated = getTransform(calculated, getValue(data[i % l] - 'g'));
            if (!iFound && calculated == I) {
                iFound = 1;
            }
            if (iFound && calculated == K) {
                jFound = 1;
            }
            if (!kFound && calculated == -O && i == product - 1) {
                kFound = 1;
                break;
            }
        }
        splitComplete = iFound * jFound * kFound;


        if (splitComplete) {
            cout << "Case #" << caseNo << ": " << "YES" << endl;
        } else {
            cout << "Case #" << caseNo << ": " << "NO" << endl;
        }
        caseNo++;
    }
    return 0;
}

