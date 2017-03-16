#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,tk=1;
    scanf("%d",&t);
    while(t--){
        int x,r,c;
        scanf("%d%d%d",&x,&r,&c);
        if(r>c)
            swap(r,c);
        if(x>6 || r*c%x>0 || r<(x+1)/2 || c<((x+1)/2+(x+1)%2)){
            printf("Case #%d: RICHARD\n",tk++);
            continue;
        }
        if(x<4){
            printf("Case #%d: GABRIEL\n",tk++);
            continue;
        }
        if(x==4 && r>x-2){
            printf("Case #%d: GABRIEL\n",tk++);
            continue;
        }
        printf("Case #%d: RICHARD\n",tk++);
    }
}
        

