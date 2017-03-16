//
//  main.cpp
//  CodeJam.2013.Q.C
//
//  Created by Maxim Piskunov on 13.04.2013.
//  Copyright (c) 2013 Maxim Piskunov. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include <gmpxx.h>

using namespace std;

struct test_case {
    string A;
    string B;
};

void read(vector <test_case> *tests)
{
    ifstream in("input.txt");
    
    int T;
    in >> T;
    tests->resize(T);
    for (int i = 0; i < T; i++) {
        in >> (*tests)[i].A >> (*tests)[i].B;
    }
    
    in.close();
}

void write(vector <string> *results)
{
    ofstream out("output.txt");
    
    out << "Case #1: " << (*results)[0];
    for (int i = 1; i < results->size(); i++) {
        out << endl << "Case #" << i+1 << ": " << (*results)[i];
    }
    
    out.close();
}

bool palindrome(mpz_class n) {
    string nstr = n.get_str();
    for (int i = 0; i < nstr.length(); i++) {
        if (nstr[i] != nstr[nstr.length()-i-1]) return false;
    }
    return true;
}

void inc(mpz_class *n) {
    (*n)++;
    string nstr = n->get_str();
    for (int i = (int)nstr.length()-1; i > 0; i--) {
        if (nstr[i] == '2') {
            nstr[i] = '0';
            nstr[i-1]++;
        }
        else break;
    }
    if (nstr[0] == '2') {
        nstr[0] = '0';
        nstr = "1" + nstr;
    }
    *n = nstr;
}

mpz_class full(mpz_class n, bool reduce) {
    string nstr = n.get_str();
    string result = nstr;
    if (reduce) result.pop_back();
    reverse(nstr.begin(), nstr.end());
    result += nstr;
    return mpz_class(result);
}

void addIfOk (mpz_class A, mpz_class B, mpz_class n, vector <mpz_class> *numbers) {
    mpz_class nfull0 = full(mpz_class(n),0);
    mpz_class nfull0sqr = nfull0 * nfull0;
    if (palindrome(nfull0sqr) && nfull0sqr <= B && nfull0sqr >= A) numbers->push_back(nfull0sqr);
    
    mpz_class nfull1 = full(mpz_class(n),1);
    mpz_class nfull1sqr = nfull1 * nfull1;
    if (palindrome(nfull1sqr) && nfull1sqr <= B && nfull1sqr >= A) numbers->push_back(nfull1sqr);
}

void read_numbers(vector <mpz_class> *numbers) {
    ifstream in("numbers.txt");
    int n;
    in >> n;
    numbers->reserve(n);
    for (int i = 0; i < n; i++) {
        string str;
        in >> str;
        numbers->push_back(mpz_class(str));
    }
    in.close();
}

string solve_test_fast (test_case test, vector <mpz_class> *numbers) {
    int count = 0;
    for (int i = 0; i < numbers->size(); i++) {
        if (mpz_class(test.A) <= (*numbers)[i] && (*numbers)[i] <= mpz_class(test.B)) {
            count++;
        }
    }
    return mpz_class(count).get_str();
}

string solve_test (test_case test)
{
    vector <mpz_class> numbers;
    mpz_class A(test.A), B(test.B);
    /*
    vector <mpz_class> alt_numbers;
    mpz_class j, isqr;
    for (j = 1; (isqr = j*j) <= B; j++) if (isqr >= A) {
        if (palindrome(j) && palindrome(isqr)) {
            alt_numbers.push_back(isqr);
        }
    }
    */
    addIfOk(A, B, mpz_class(1), &numbers);
    addIfOk(A, B, mpz_class(2), &numbers);
    addIfOk(A, B, mpz_class(3), &numbers);
    
    mpz_class i = 10;
    mpz_class fulli;
    mpz_class fullisqr;
    
    int len = 2;
    while (true) {
        if (len == i.get_str().length()) {
            cout << len++ << " " << flush;
        }
        
        fulli = full(i, 1);
        fullisqr = fulli*fulli;
        if (fullisqr > B) break;
        if (palindrome(fullisqr)) {
            numbers.push_back(fullisqr);
        }
        
        fulli = full(i, 0);
        fullisqr = fulli*fulli;
        if (fullisqr <= B && palindrome(fullisqr)) {
            numbers.push_back(fullisqr);
        }
        
        inc(&i);
    }
    
    cout << endl;
    
    cout << "2s..." << endl;
    
    for (int i = 2; i < 200; i++) {
        string n(i, '0');
        n[0] = '1';
        n[i-1] = '2';
        addIfOk(A, B, mpz_class(n), &numbers);
        for (int j = 1; j < i-1; j++) {
            n[j] = '1';
            addIfOk(A, B, mpz_class(n), &numbers);
            n[j] = '0';
        }
        n[0] = '2';
        n[i-1] = '0';
        addIfOk(A, B, mpz_class(n), &numbers);
        
        n[i-1] = '1';
        addIfOk(A, B, mpz_class(n), &numbers);
    }
    
    cout << "sorting..." << endl;
    sort(numbers.begin(), numbers.end());
    
    ofstream numb("numbers.txt");
    numb << numbers.size() << endl;
    for (int i = 0; i < numbers.size(); i++) {
        numb << numbers[i].get_str() << endl;
    }
    numb.close();
    /*
    for (int i = 0; i < min(numbers.size(), alt_numbers.size()); i++) {
        cout << numbers[i].get_str() << " " << alt_numbers[i].get_str() << endl;
    }
    
    if (numbers.size() != alt_numbers.size()) {
        cout << "incorrect size!" << endl;
        return "1";
    }
    else for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] != alt_numbers[i]) {
            cout << "incorrect content!" << endl;
            return "1";
        }
    }
    */
    return mpz_class(numbers.size()).get_str();
}

void solve(vector <test_case> *tests, vector <string> *results)
{
    vector <mpz_class> numbers;
    read_numbers(&numbers);
    results->resize(tests->size());
    for (int i = 0; i < tests->size(); i++) (*results)[i] = solve_test_fast((*tests)[i], &numbers);
}

int main(int argc, const char * argv[])
{
    vector <test_case> tests;
    vector <string> results;
    
    read(&tests);
    solve(&tests, &results);
    write(&results);
    
    return 0;
}