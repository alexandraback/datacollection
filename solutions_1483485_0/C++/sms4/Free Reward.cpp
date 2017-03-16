#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <list>

using namespace std;

int mapa[200];
string s1, s2;


int main(){

    freopen("a.txt", "r", stdin);
    freopen("b.txt", "w", stdout);

    mapa[32] = 32;
    mapa[97] = 121;
    mapa[98] = 104;
    mapa[99] = 101;
    mapa[100] = 115;
    mapa[101] = 111;
    mapa[102] = 99;
    mapa[103] = 118;
    mapa[104] = 120;
    mapa[105] = 100;
    mapa[106] = 117;
    mapa[107] = 105;
    mapa[108] = 103;
    mapa[109] = 108;
    mapa[110] = 98;
    mapa[111] = 107;
    mapa[112] = 114;
    mapa[113] = 122;
    mapa[114] = 116;
    mapa[115] = 110;
    mapa[116] = 119;
    mapa[117] = 106;
    mapa[118] = 112;
    mapa[119] = 102;
    mapa[120] = 109;
    mapa[121] = 97;
    mapa[122] = 113;

    int t, caso, tam;
    scanf("%d\n", &t);
    caso = 1;
    while(t--){
        getline(cin, s1);
        s2 = "";
        tam = s1.size();
        for(int i=0;i<tam;i++){
            s2 += mapa[s1[i]];
        }
        printf("Case #%d: ",caso++);
        cout << s2 << endl;
    }

    return 0;
}
/*

    s1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
    s2 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
    s3 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";

    r1 = "our language is impossible to understand";
    r2 = "there are twenty six factorial possibilities";
    r3 = "so it is okay if you want to just give up";
    for(int i = 0; i < s1.size();i++){
        mapa[s1[i]] = r1[i];
    }
    for(int i = 0; i < s1.size();i++){
        mapa[s2[i]] = r2[i];
    }
    for(int i = 0; i < s1.size();i++){
        mapa[s3[i]] = r3[i];
    }
    for(int i =97; i < 123;i++){
        cout << "   mapa["<< i << "]"<< " = " << mapa[i]<< ";"<<endl;
    }
*/

