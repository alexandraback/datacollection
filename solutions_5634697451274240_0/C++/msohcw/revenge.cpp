#include <stdio.h>
#include <cstring>

using namespace std;

int T;

int main(){
    scanf("%d\n", &T);
    for(int Tn = 1; Tn <= T; Tn++){
        printf("Case #%d: ", Tn);
        char c;
        char c_prev;
        int l = 0;
        while(scanf("%c",&c)){
            if(c == '\n') break;
            if(l == 0){
                c_prev = c;
                l++;
                continue;    
            }
            if(c == c_prev) continue;
            c_prev = c;
            l++;
        }
        if(c_prev == '+') l--;
        printf("%d\n",l);
    }
}
