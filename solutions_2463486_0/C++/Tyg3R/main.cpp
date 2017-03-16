/* 
 * File:   main.cpp
 * Author: tyg3r
 *
 * Created on 13. duben 2013, 11:08
 */

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

string array[50000];
int arrayC = 0;

bool smallerOrEqual(string& s1, string& s2) {
    if(s1.length() != s2.length()) return s1.length() < s2.length();
    int len = s1.length();
    for(int i = 0; i < len; i++) if(s1[i] != s2[i]) return s1[i] < s2[i];
    return true;
}

bool higherOrEqual(string& s1, string& s2) {
    if(s1.length() != s2.length()) return s1.length() > s2.length();
    int len = s1.length();
    for(int i = 0; i < len; i++) if(s1[i] != s2[i]) return s1[i] > s2[i];
    return true;
}

string add(string n1, string n2) {
    int diff = n1.length() - n2.length();
    for(int i = n2.length()-1; i >= 0; i--) n1[diff+i] = n1[diff+i] + n2[i] - '0';
    return n1;
}

string square(string num) {
    string mask = num;
    string ret = "";
    for(int i = num.length()-1; i >= 0; i--) {
        if(num[i] == '1') ret = add(mask, ret);
        else if(num[i] == '2') {
            ret = add(mask, ret);
            ret = add(mask, ret);
        }
        mask += '0';
    }
    return ret;
}

int main(int argc, char** argv) {
    
    //string num = "1000001";
    string num = "10000000000000000000000000000000000000000000000001";
    for(int len = 50; len >= 2; len--) {
        //array[arrayC++] = square(num);
        num[0] = num[len-1] = '2';
        if(len % 2) {
            num[len/2] = '1';
            array[arrayC++] = square(num);
            num[len/2] = '0';
        }
        array[arrayC++] = square(num);
        num[0] = num[len-1] = '1';
        for(int i = 1; i < len/2; i++) {
            num[i] = num[len-i-1] = '1';
            for(int j = i+1; j < len/2; j++) {
                num[j] = num[len-j-1] = '1';
                for(int k = j+1; k < len/2; k++) {
                    num[k] = num[len-k-1] = '1';
                    if(len % 2) {
                        num[len/2] = '1';
                        array[arrayC++] = square(num);
                        num[len/2] = '0';
                    }
                    array[arrayC++] = square(num);
                    num[k] = num[len-k-1] = '0';
                }
                if(len % 2) {
                    num[len/2] = '1';
                    array[arrayC++] = square(num);
                    num[len/2] = '0';
                }
                array[arrayC++] = square(num);
                num[j] = num[len-j-1] = '0';
            }
            if(len % 2) {
                num[len/2] = '2';
                array[arrayC++] = square(num);
                num[len/2] = '1';
                array[arrayC++] = square(num);
                num[len/2] = '0';
            }
            array[arrayC++] = square(num);
            num[i] = num[len-i-1] = '0';
        }
        if(len % 2) {
            num[len/2] = '2';
            array[arrayC++] = square(num);
            num[len/2] = '1';
            array[arrayC++] = square(num);
            num[len/2] = '0';
        }
        array[arrayC++] = square(num);
        
        num = num.substr(0,len-1);
        num[len-2] = '1';
    }
    array[arrayC++] = "9";
    array[arrayC++] = "4";
    array[arrayC++] = "1";
    //printf("%d\n", arrayC);
    
    int T;
    char c1[107], c2[107];
    string s1, s2;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++) {
        scanf("%s %s\n", c1, c2);
        s1 = string(c1);
        s2 = string(c2);
        int cnt = 0;
        for(int i = 0; i < arrayC; i++)
            if(smallerOrEqual(array[i], s2) && higherOrEqual(array[i], s1)) cnt++;
        printf("Case #%d: %d\n", t, cnt);
    }
    return 0;
}

