/* *************************
 * Author: xg1990
 * Created Time:  
 * LastModified:  Sat 14 Apr 2012 10:58:32 AM CST
 * C File Name: 
 * ************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

void decode(string & s){
    for( int i = 0 ; i < s.size()  ; ++i )
    {
        switch(s[i]){
            case 'a': s[i] = 'y';break;
            case 'b': s[i] = 'h';break;
            case 'c': s[i] = 'e';break;
            case 'd': s[i] = 's';break;
            case 'e': s[i] = 'o';break;
            case 'f': s[i] = 'c';break;
            case 'g': s[i] = 'v';break;
            case 'h': s[i] = 'x';break;
            case 'i': s[i] = 'd';break;
            case 'j': s[i] = 'u';break;
            case 'k': s[i] = 'i';break;
            case 'l': s[i] = 'g';break;
            case 'm': s[i] = 'l';break;
            case 'n': s[i] = 'b';break;
            case 'o': s[i] = 'k';break;
            case 'p': s[i] = 'r';break;
            case 'q': s[i] = 'z';break;
            case 'r': s[i] = 't';break;
            case 's': s[i] = 'n';break;
            case 't': s[i] = 'w';break;
            case 'u': s[i] = 'j';break;
            case 'v': s[i] = 'p';break;
            case 'w': s[i] = 'f';break;
            case 'x': s[i] = 'm';break;
            case 'y': s[i] = 'a';break;
            case 'z': s[i] = 'q';break;
            case ' ': break;
            default: s[i] = '?';
        }
    }
}

int main() {
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int T;
    string buf;
    scanf("%d\n", &T);
    for(int t = 0; t < T; ++t){
        getline(cin, buf); 
        decode(buf);
        printf("Case #%d: %s\n", t+1, buf.c_str());
    }
    return 0;
}


