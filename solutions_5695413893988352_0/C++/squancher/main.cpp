#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <string>
#include <cmath>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

char coders[100];
char jammers[100];

int curr_len;

long long min(char *p) {
    long long res = 0;
    while (*p != 0) {
        res *= 10;
        
        if (*p != '?') {
            res += *p - '0';
        }
        
        p++;
    }
    return res;
}

void set_min(char *p) {
    while (*p != 0) {
        if (*p == '?') {
            *p = '0';
        }
        
        p++;
    }
}

long long max(char *p) {
    long long res = 0;
    while (*p != 0) {
        res *= 10;
        
        if (*p != '?') {
            res += *p - '0';
        }
        
        else {
            res += 9;
        }
        
        p++;
    }
    return res;
}

void set_max(char *p) {
    while (*p != 0) {
        if (*p == '?') {
            *p = '9';
        }
        
        p++;
    }
}

long long ten_power(int p) {
    long long res = 1;
    
    for (int i = 0; i < p; i++) {
        res *= 10;
    }
    
    return res;
}

long long clothest(char *c, char *j, int p) {
    if (*c == 0) {
        return 0;
    }
    
    if (*c != '?' && *j != '?') {
        if (*c == *j) {
            return clothest(c + 1, j + 1, p + 1);
        }
        
        if (*c < *j) {
            return (*j - *c) * ten_power(curr_len - p - 1) - max(c + 1) + min(j + 1);
        }
        
        if (*c > *j) {
            return (*c - *j) * ten_power(curr_len - p - 1) - max(j + 1) + min(c + 1);
        }
    }
    
    else if (*c != '?' && *j == '?') {
        long long v1 = clothest(c + 1, j + 1, p + 1);
        
        long long v2;
        if (*c == '0') {
            v2 = ten_power(18);
        }
        
        else {
            v2 = ten_power(curr_len - p - 1) - max(j + 1) + min(c + 1);
        }
        
        long long v3;
        if (*c == '9') {
            v3 = ten_power(18);
        }
        
        else {
            v3 = ten_power(curr_len - p - 1) - max(c + 1) + min(j + 1);
        }
        
        if (v1 < v2) {
            if (v1 < v3) {
                return v1;
            }
            
            else {
                return v3;
            }
        }
        
        else {
            if (v2 < v3) {
                return v2;
            }
            
            else {
                return v3;
            }
        }
    }
    
    else if (*c == '?' && *j != '?') {
        long long v1 = clothest(c + 1, j + 1, p + 1);
        
        long long v2;
        if (*j == '0') {
            v2 = ten_power(18);
        }
        
        else {
            v2 = ten_power(curr_len - p - 1) - max(c + 1) + min(j + 1);
        }
        
        long long v3;
        if (*j == '9') {
            v3 = ten_power(18);
        }
        
        else {
            v3 = ten_power(curr_len - p - 1) - max(j + 1) + min(c + 1);
        }
        
        if (v1 < v2) {
            if (v1 < v3) {
                return v1;
            }
            
            else {
                return v3;
            }
        }
        
        else {
            if (v2 < v3) {
                return v2;
            }
            
            else {
                return v3;
            }
        }
    }
    
    else {
        long long v1 = clothest(c + 1, j + 1, p + 1);
        
        long long v2 = ten_power(curr_len - p - 1) - max(c + 1) + min(j + 1);
        
        long long v3 = ten_power(curr_len - p - 1) - max(j + 1) + min(c + 1);
        
        if (v1 < v2) {
            if (v1 < v3) {
                return v1;
            }
            
            else {
                return v3;
            }
        }
        
        else {
            if (v2 < v3) {
                return v2;
            }
            
            else {
                return v3;
            }
        }
    }
    
    return -100000;
}

void set_clothest(char *c, char *j, int p) {
    if (*c == 0) {
        return;
    }
    
    if (*c != '?' && *j != '?') {
        if (*c == *j) {
            set_clothest(c + 1, j + 1, p + 1);
        }
        
        if (*c < *j) {
            set_max(c + 1);
            set_min(j + 1);
        }
        
        if (*c > *j) {
            set_max(j + 1);
            set_min(c + 1);
        }
    }
    
    else if (*c != '?' && *j == '?') {
        long long v1 = clothest(c + 1, j + 1, p + 1);
        
        long long v2;
        if (*c == '0') {
            v2 = ten_power(18);
        }
        
        else {
            v2 = ten_power(curr_len - p - 1) - max(j + 1) + min(c + 1);
        }
        
        long long v3;
        if (*c == '9') {
            v3 = ten_power(18);
        }
        
        else {
            v3 = ten_power(curr_len - p - 1) - max(c + 1) + min(j + 1);
        }
        
        
        if (v2 <= v3 && v2 <= v1) {
            *j = *c - 1;
            set_max(j + 1);
            set_min(c + 1);
        }
        
        else if (v1 <= v2 && v1 <= v3) {
            *j = *c;
            set_clothest(c + 1, j + 1, p + 1);
        }
        
        else if (v3 <= v1 && v3 <= v2) {
            *j = *c + 1;
            set_max(c + 1);
            set_min(j + 1);
        }
    }
    
    else if (*c == '?' && *j != '?') {
        long long v1 = clothest(c + 1, j + 1, p + 1);
        
        long long v2;
        if (*j == '0') {
            v2 = ten_power(18);
        }
        
        else {
            v2 = ten_power(curr_len - p - 1) - max(c + 1) + min(j + 1);
        }
        
        long long v3;
        if (*j == '9') {
            v3 = ten_power(18);
        }
        
        else {
            v3 = ten_power(curr_len - p - 1) - max(j + 1) + min(c + 1);
        }
        
        if (v2 <= v3 && v2 <= v1) {
            *c = *j - 1;
            set_max(c + 1);
            set_min(j + 1);
        }
        
        else if (v1 <= v2 && v1 <= v3) {
            *c = *j;
            set_clothest(c + 1, j + 1, p + 1);
        }
        
        else if (v3 <= v1 && v3 <= v2) {
            *c = *j + 1;
            set_max(j + 1);
            set_min(c + 1);
        }
    }
    
    else {
        long long v1 = clothest(c + 1, j + 1, p + 1);
        
        long long v2 = ten_power(curr_len - p - 1) - max(c + 1) + min(j + 1);
        
        long long v3 = ten_power(curr_len - p - 1) - max(j + 1) + min(c + 1);
        
        if (v1 <= v2 && v1 <= v3) {
            *j = '0';
            *c = '0';
            set_clothest(c + 1, j + 1, p + 1);
        }
        
        else if (v2 <= v3 && v2 <= v3) {
            *j = '1';
            *c = '0';
            set_max(c + 1);
            set_min(j + 1);
        }
        
        else if (v3 <= v2 && v3 <= v2) {
            *j = '0';
            *c = '1';
            set_max(j + 1);
            set_min(c + 1);
        }
    }
}



int main() {
    freopen("B-small.in", "r", stdin);
    freopen("B-small.out", "w", stdout);
    
    int tn = 0;
    
    scanf("%d\n", &tn);
    
    for (int t = 1; t <= tn; t++) {
        for (int i = 0; i < 100; i++) {
            coders[i] = 0;
            jammers[i] = 0;
        }
        
        int k = 0;
        
        while (1) {
            char c = getchar();
            
            if (c == ' ') {
                break;
            }
            
            if (c == '?' || (c >= '0' && c <= '9')) {
                coders[k++] = c;
            }
        }
        
        k = 0;
        
        while (1) {
            char c = getchar();
            
            if (c == '\n') {
                break;
            }
            
            if (c == '?' || (c >= '0' && c <= '9')) {
                jammers[k++] = c;
            }
        }
        
        curr_len = 0;
        
        while (coders[curr_len] != 0) {
            curr_len++;
        }
        
        set_clothest(coders, jammers, 0);
        
        printf("Case #%d: ", t);
               
        for (int i = 0; i < curr_len; i++) {
            putchar(coders[i]);
        }
        
        putchar(' ');
        
        for (int i = 0; i < curr_len; i++) {
            putchar(jammers[i]);
        }
        
        putchar('\n');
    }
    
    return 0;
}