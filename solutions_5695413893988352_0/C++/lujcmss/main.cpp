#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>

#include <thread>
#include <chrono>

#include <memory>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <time.h>
#include <errno.h>
#include <Semaphore.h>

using namespace std;

uint64_t dis(string s1, string s2) {
    uint64_t v1 = stoull(s1);
    uint64_t v2 = stoull(s2);
    return v1 > v2 ? v1 - v2 : v2 - v1;
}

pair<string, string> cmp(pair<string, string> p1, pair<string, string> p2) {
    auto d1 = dis(p1.first, p1.second);
    auto d2 = dis(p2.first, p2.second);
    
    if (d1 > d2) {
        return p2;
    } else if (d1 < d2) {
        return p1;
    }
    
    if (p1.first > p2.first) {
        return p2;
    } else if (p1.first < p2.first) {
        return p1;
    }
    
    if (p1.second > p2.second) {
        return p2;
    }
    return p1;
}

pair<string, string> searchs(string c, string j, uint64_t cVal, uint64_t jVal, int index) {
    auto posc = c.find("?");
    auto posj = j.find("?");
    if (posc == string::npos && posj == string::npos) {
        return make_pair(c, j);
    }
    
    if (c[index] == '?' && j[index] == '?') {
        if (cVal > jVal) {
            c[index] = '0';
            j[index] = '9';
            
            cVal = cVal * 10 + c[index] - '0';
            jVal = jVal * 10 + j[index] - '0';
            return searchs(c, j, cVal, jVal, index+1);
        } else if (cVal < jVal) {
            c[index] = '9';
            j[index] = '0';
            
            cVal = cVal * 10 + c[index] - '0';
            jVal = jVal * 10 + j[index] - '0';
            return searchs(c, j, cVal, jVal, index+1);
        }
        
        c[index] = '0'; j[index] = '0';
        auto tcVal = cVal * 10 + c[index] - '0';
        auto tjVal = jVal * 10 + j[index] - '0';
        auto p1 = searchs(c, j, tcVal, tjVal, index+1);
        
        c[index] = '1'; j[index] = '0';
        tcVal = cVal * 10 + c[index] - '0';
        tjVal = jVal * 10 + j[index] - '0';
        auto p2 = searchs(c, j, tcVal, tjVal, index+1);
        p1 = cmp(p1, p2);
        
        c[index] = '0'; j[index] = '1';
        tcVal = cVal * 10 + c[index] - '0';
        tjVal = jVal * 10 + j[index] - '0';
        p2 = searchs(c, j, tcVal, tjVal, index+1);
            
        return cmp(p1, p2);
    } else if (c[index] == '?') {
        if (cVal > jVal) {
            c[index] = '0';
            
            cVal = cVal * 10 + c[index] - '0';
            jVal = jVal * 10 + j[index] - '0';
            return searchs(c, j, cVal, jVal, index+1);
        } else if (cVal < jVal) {
            c[index] = '9';
            
            cVal = cVal * 10 + c[index] - '0';
            jVal = jVal * 10 + j[index] - '0';
            return searchs(c, j, cVal, jVal, index+1);
        }
        
        c[index] = j[index];
        auto tcVal = cVal * 10 + c[index] - '0';
        auto tjVal = jVal * 10 + j[index] - '0';
        auto p1 = searchs(c, j, tcVal, tjVal, index+1);
        
        c[index] = j[index] == '0' ? '9' : j[index] - 1;
        tcVal = cVal * 10 + c[index] - '0';
        tjVal = jVal * 10 + j[index] - '0';
        auto p2 = searchs(c, j, tcVal, tjVal, index+1);
        p1 = cmp(p1, p2);
        
        c[index] = j[index] == '9' ? '0' : j[index] + 1;
        tcVal = cVal * 10 + c[index] - '0';
        tjVal = jVal * 10 + j[index] - '0';
        p2 = searchs(c, j, tcVal, tjVal, index+1);
        
        return cmp(p1, p2);
    } else if (j[index] == '?') {
        if (cVal > jVal) {
            j[index] = '9';
            
            cVal = cVal * 10 + c[index] - '0';
            jVal = jVal * 10 + j[index] - '0';
            return searchs(c, j, cVal, jVal, index+1);
        } else if (cVal < jVal) {
            j[index] = '0';
            
            cVal = cVal * 10 + c[index] - '0';
            jVal = jVal * 10 + j[index] - '0';
            return searchs(c, j, cVal, jVal, index+1);
        }
        
        j[index] = c[index];
        auto tcVal = cVal * 10 + c[index] - '0';
        auto tjVal = jVal * 10 + j[index] - '0';
        auto p1 = searchs(c, j, tcVal, tjVal, index+1);
        
        j[index] = c[index] == '0' ? '9' : c[index] - 1;
        tcVal = cVal * 10 + c[index] - '0';
        tjVal = jVal * 10 + j[index] - '0';
        auto p2 = searchs(c, j, tcVal, tjVal, index+1);
        p1 = cmp(p1, p2);
        
        j[index] = c[index] == '9' ? '0' : c[index] + 1;
        tcVal = cVal * 10 + c[index] - '0';
        tjVal = jVal * 10 + j[index] - '0';
        p2 = searchs(c, j, tcVal, tjVal, index+1);
        
        return cmp(p1, p2);
    } else {
        cVal = cVal * 10 + c[index] - '0';
        jVal = jVal * 10 + j[index] - '0';
        return searchs(c, j, cVal, jVal, index+1);
    }
}

int main() {
    freopen("/Users/lujcmss/Downloads/B-small-attempt1.in.txt", "r", stdin);
    freopen("/Users/lujcmss/Downloads/b.txt", "w", stdout);
    
    int T;
    cin >> T;
    
    for (int kase = 0; kase < T; kase++) {
        string c, j;
        cin >> c >> j;
        
        auto p = searchs(c, j, 0, 0, 0);
        printf("Case #%d: %s %s\n", kase+1, p.first.c_str(), p.second.c_str());
    }
    return 0;
}