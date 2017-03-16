//
//  GCJ20141A.cpp
//  Console Application
//
//  Created by Vanan on 25/04/2014.
//  Copyright (c) 2014 Elly Works. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <bitset>
#include <sstream>
using namespace std;

ifstream fin("/Users/Vanan/Downloads/C-small-attempt3.in");
ofstream fout("/Users/Vanan/Downloads/output.out");

void problemA();
void problemB();
void problemC();

long long ancestors = (1L << 40);

long long gcd(long long a, long long b) {
    if (a == 0) {
        return b;
    }
    if (a == b) {
        return a;
    }
    if (a > b) {
        return gcd(b, a);
    }
    if (a % 2 == 0 && b % 2 == 0) {
        return 2*gcd(a/2, b/2);
    }
    if (a % 2 == 0)
        return gcd(a/2, b);
    if (b % 2 == 0)
        return gcd(a, b/2);
    return gcd ((b-a)/2, a);
}

void problemA() {
    long long p, q;
    fin >> p;
    char temp;
    fin >> temp;
    fin >> q;
    
    while (p % 2 == 0 && q % 2 == 0) {
        p /= 2;
        q /= 2;
    }
    
    long long g = gcd(p, q);
    p /= g;
    q /= g;
    
    if ((ancestors*p) % q == 0) {
        int answer = 1;
        p = (p*ancestors)/q;
        while ((p << 1) < ancestors) {
            ++answer;
            p = (p << 1);
        }
        fout << answer << endl;
    }
    else {
        fout << "Impossible" << endl;
    }
}

unsigned long long modulo = 1000000007;

unsigned long long factorial(unsigned long long a) {
    if (a == 0 || a == 1)
        return 1;
    return (a*factorial(a-1)) % modulo;
}

int N;
string words[100];
bool validWord[100];

unsigned long long ways(int left, int startLetter, int components) {
    //if (left == 0 || left == 1)
    //    return factorial(components);
    if (startLetter >= 26)
        return factorial(components + left - 1);
    
    int i = startLetter;
    char letter = 'a' + i;
    
    int fullCount = 0;
    int startCount = 0;
    int startID = -1;
    int endCount = 0;
    int endID = -1;
    int middleCount = 0;
    
    bool full[100];
    
    for (int j=0; j<N; ++j) {
        if (!validWord[j])
            continue;
        full[j] = false;
        string word = words[j];
        int wordLength = word.length();
        bool any = false;
        bool stoppedAny = false;
        int leftCount = 0;
        bool leftEnded = false;
        int rightCount = 0;
        
        for (int k=0; k<wordLength; ++k) {
            bool isLetter = ((word.at(k)) == letter);
            if (any && stoppedAny && isLetter)
                return 0;
            if (any && !isLetter) {
                stoppedAny = true;
            }
            any = any || isLetter;
            if (!leftEnded && isLetter) ++leftCount;
            else leftEnded = true;
        }
        for (int k=wordLength - 1; k>=0; --k) {
            bool isLetter = ((word.at(k)) == letter);
            if (isLetter) ++rightCount;
            else break;
        }
        if (leftCount == wordLength) { ++fullCount; full[j] = true; }
        else if (leftCount > 0 && rightCount == 0) { ++startCount; startID = j; }
        else if (leftCount == 0 && rightCount > 0) { ++endCount; endID = j; }
        else if (leftCount == 0 && rightCount == 0 && any) ++middleCount;
        else if (leftCount > 0 && rightCount > 0) {
            return 0;
        }
    }
    if (startCount > 1 || endCount > 1) {
        return 0;
    }
    if (middleCount > 0 && startCount + endCount + middleCount + fullCount > 1) {
        return 0;
    }
    if (startCount + endCount == 1) {
        for (int j=0; j<N; ++j) {
            if (validWord[j] && full[j]) {
                validWord[j] = false;
                --left;
            }
        }
        return (factorial(fullCount)*ways(left, startLetter + 1, components)) % modulo;
    }
    if (startCount + endCount == 2) {
        words[endID] += words[startID];
        validWord[startID] = false;
        --left;
        for (int j=0; j<N; ++j) {
            if (validWord[j] && full[j]) {
                validWord[j] = false;
                --left;
            }
        }
        return (factorial(fullCount)*ways(left, startLetter + 1, components)) % modulo;
    }
    if (startCount + endCount == 0) {
        for (int j=0; j<N; ++j) {
            if (validWord[j] && full[j]) {
                validWord[j] = false;
                --left;
            }
        }
        int add = (fullCount > 0) ? 1 : 0;
        return (factorial(fullCount)*ways(left, startLetter + 1, components + add)) % modulo;
    }
    
    // Should never get here
    return ways(left, startLetter + 1, components);
}

void problemB() {
    //int N;
    fin >> N;
    
    //string words[100];
    for (int i=0; i<N; ++i) {
        fin >> words[i];
        validWord[i] = true;
    }
    
    unsigned long long answer = ways(N, 0, 1) % modulo;
    
    fout << answer << endl;
}

void problemC() {
    int N, M, K;
    fin >> N >> M >> K;
    if (N > M) {
        int temp = M;
        M = N;
        N = temp;
    }
    // N is the smaller one
    if (N == 1 || N == 2) {
        fout << K << endl;
        return;
    }
    if (K <= 4) {
        fout << K << endl;
        return;
    }
    if (N == 3) {
        int answer = 4;
        int total = 5;
        while (total < K) {
            if (answer % 2 == 0) {
                ++answer;
                ++total;
            }
            else {
                ++answer;
                total += 2;
            }
        }
        fout << answer << endl;
        return;
    }
    if (N == 4) {
        int answer = 4;
        int total = 5;
        while (total < K) {
            if (answer == 4) {
                ++answer;
                ++total;
            }
            else {
                ++answer;
                total += 2;
            }
        }
        if (answer > (N-2) + (N-2) + (M-2) + (M-2)) {
            answer = (N-2) + (N-2) + (M-2) + (M-2);
            total = N*M - 4;
            while (total < K) {
                ++answer;
                ++total;
            }
        }
        fout << answer << endl;
        return;
    }
}

int main (int argc, const char * argv[])
{
    cout << "Start" << endl;
    int T;
    fin >> T;
    for (int t=1; t<=T; ++t)
    {
        fout << "Case #" << t << ": ";
        
        //problemA();
        //problemB();
        problemC();
    }
    cout << "Done" << endl;
    return 0;
}