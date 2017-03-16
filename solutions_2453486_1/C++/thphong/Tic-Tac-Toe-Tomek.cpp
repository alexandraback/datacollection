#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
#include <cstring>

#define MAXN 100005
#define INFTY 1000000000

using namespace std;

int a[MAXN];
char s[5][5];

int sum(){
    int res = 0;
    for(int i=0; i<4; i++){
          for(int j=0; j<4; j++) res += (s[i][j] == '.');\
     }
     return res;
}

bool check(char c){
     //row
     for(int i=0; i<4; i++){
          int num = 0;
          for(int j=0; j<4; j++) num += (s[i][j] == c) || (s[i][j] == 'T');
          if(num == 4) return 1;
     }
     //col
     for(int j=0; j<4; j++){
          int num = 0;
          for(int i=0; i<4; i++) num += (s[i][j] == c) || (s[i][j] == 'T');
          if(num == 4) return 1;
     }
     //dig 1
     int num = 0;
     for(int i=0; i<4; i++){
             num += (s[i][i] == c) || (s[i][i] == 'T');
     }
     if(num == 4) return 1;
     
     //dig 2
     num = 0;
     for(int i=0; i<4; i++){
             num += (s[3-i][i] == c) || (s[3-i][i] == 'T');
     }
     if(num == 4) return 1;
     
     return 0;
}

int main () {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    for(int ca=1; ca<=t; ca++){
        for(int i=0; i<4; i++) cin >> s[i];
        cout<<"Case #"<<ca<<": ";
        if(check('O')) cout<<"O won"<<endl;
        else if(check('X')) cout<<"X won"<<endl;
        else if(sum() == 0) cout<<"Draw"<<endl;
        else cout<<"Game has not completed"<<endl;
    }
    return 0;
}
