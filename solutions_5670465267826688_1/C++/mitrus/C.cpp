//
//  main.cpp
//  GCJQual
//
//  Created by Anton Krasnokutskiy on 11.04.15.
//  Copyright (c) 2015 Anton Krasnokutskiy. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const long long minTimesIsNeeded = 40; // 4 equals substring gives a reduce equals to 1. 4 * 3 = 12. We'll take 50 - it's enough.

enum Quaternion {
    OneElement,
    IElement,
    JElement,
    KElement
};

typedef pair<bool, Quaternion> SignedQuaternion;

SignedQuaternion translateUnsignedQuaternion(const char c) {
    switch (c) {
        case '1':
            return make_pair(false, OneElement);
        case 'i':
            return make_pair(false, IElement);
        case 'j':
            return make_pair(false, JElement);
        case 'k':
            return make_pair(false, KElement);
    }
    return make_pair(false, OneElement);
}

SignedQuaternion multiply(const SignedQuaternion &a, const SignedQuaternion &b) {
    bool totalSign = a.first ^ b.first;
    Quaternion unsignedA = a.second;
    Quaternion unsignedB = b.second;
    switch (unsignedA) {
        case OneElement:
            switch (unsignedB) {
                case OneElement:
                    return make_pair(totalSign, OneElement);
                case IElement:
                    return make_pair(totalSign, IElement);
                case JElement:
                    return make_pair(totalSign, JElement);
                case KElement:
                    return make_pair(totalSign, KElement);
            }
            break;
            
        case IElement:
            switch (unsignedB) {
                case OneElement:
                    return make_pair(totalSign, IElement);
                case IElement:
                    return make_pair(totalSign ^ 1, OneElement);
                case JElement:
                    return make_pair(totalSign, KElement);
                case KElement:
                    return make_pair(totalSign ^ 1, JElement);
            }
            break;
            
        case JElement:
            switch (unsignedB) {
                case OneElement:
                    return make_pair(totalSign, JElement);
                case IElement:
                    return make_pair(totalSign ^ 1, KElement);
                case JElement:
                    return make_pair(totalSign ^ 1, OneElement);
                case KElement:
                    return make_pair(totalSign, IElement);
            }
            break;
            
        case KElement:
            switch (unsignedB) {
                case OneElement:
                    return make_pair(totalSign, KElement);
                case IElement:
                    return make_pair(totalSign, JElement);
                case JElement:
                    return make_pair(totalSign ^ 1, IElement);
                case KElement:
                    return make_pair(totalSign ^ 1, OneElement);
            }
            break;
    }
}

const SignedQuaternion neutralElement = make_pair(false, OneElement);

bool solve(const string &s, long long times) {
    int smartTimes = (int) min(times, minTimesIsNeeded + times % 4);
    int n = (int) s.length() * smartTimes;
    
    SignedQuaternion current = neutralElement;
//    for (int i = 0; i < n; i++) {
//        current = multiply(current, translateUnsignedQuaternion(s[i % s.length()]));
//    }
//    bool isMinusOne = current == make_pair(true, OneElement);
//    
//    current = neutralElement;
    int i = 0;
    for (; i < n; i++) {
        current = multiply(current, translateUnsignedQuaternion(s[i % s.length()]));
        if (current == translateUnsignedQuaternion('i'))
            break;
    }
    if (i == n)
        return false;
    
    i++;
    current = neutralElement;
    for (; i < n; i++) {
        current = multiply(current, translateUnsignedQuaternion(s[i % s.length()]));
        if (current == translateUnsignedQuaternion('j'))
            break;
    }
    if (i == n)
        return false;
    
    i++;
    current = neutralElement;
    for (; i < n; i++)
        current = multiply(current, translateUnsignedQuaternion(s[i % s.length()]));
    
    return current == translateUnsignedQuaternion('k');
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        long long n, t;
        cin >> n >> t;
        string s;
        cin >> s;
        if (solve(s, t))
            cout << "Case #" << i << ": " << "YES" << endl;
        else
            cout << "Case #" << i << ": " << "NO" << endl;
    }
    return 0;
}

