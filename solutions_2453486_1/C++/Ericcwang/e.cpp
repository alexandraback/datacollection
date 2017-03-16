#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <set>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <fstream>
using namespace std;
typedef long long LL;
const int inf=1000000000;//1e9
string s[4];
int checkrowchar(int x,char ch){
    for (int i=0;i<4;i++)
    if (s[x][i]!=ch&&s[x][i]!='T') return 0;
    return 1;
}
int checkcolumchar(int x,char ch){
    for (int i=0;i<4;i++)
    if(s[i][x]!=ch&&s[i][x]!='T' ) return 0;
    return 1;
}
int checkdiag(char ch){
    for (int i=0;i<4;i++)
        if (s[i][i]!=ch&&s[i][i]!='T') return 0;
    return 1;
}
int checkidiag(char ch){
    for (int i=0;i<4;i++)
        if (s[i][3-i]!=ch&&s[i][3-i]!='T') return 0;
    return 1;
}
int checkx(){
    for (int i=0;i<4;i++) if (checkrowchar(i,'X')) return 1;
    for (int i=0;i<4;i++) if (checkcolumchar(i,'X')) return 1;
    if (checkdiag('X')) return 1;
    if (checkidiag('X')) return 1 ;
    return 0;
}
int checko(){
    for (int i=0;i<4;i++) if (checkrowchar(i,'O')) return 1;
    for (int i=0;i<4;i++) if (checkcolumchar(i,'O')) return 1;
    if (checkdiag('O')) return 1;
    if (checkidiag('O')) return 1;
    return 0;
}
int main(){
    ifstream icin("A-large.in");
    ofstream icout("output.txt");
    int T;
    icin>>T;
    for (int t=1;t<=T;t++){
        for (int i=0;i<4;i++) icin>>s[i];
       // for (int i=0;i<4;i++) cout<<s[i]<<endl;cout<<endl;
        int cnt=0;
        for (int i=0;i<4;i++)
            for (int j=0;j<4;j++) cnt+=(s[i][j]=='.');
        icout<<"Case #"<<t<<": ";
        if (checkx()) icout<<"X won\n";else
            if (checko()) icout<<"O won\n";else
            if (cnt) icout<<"Game has not completed\n";else
                icout<<"Draw\n";
    }
    icin.close();
    icout.close();
}
