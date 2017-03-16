#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;
const int N = 210000;
typedef long long ll;

int a[N];
double b[N];
bool c[N];
int main(){
//    freopen("in", "r", stdin);
//    freopen("out", "w", stdout);
//    freopen("A-small-attempt2.in", "r", stdin);
//    freopen("a.out", "w", stdout);
    freopen("A-large.in", "r", stdin);
    freopen("AA.out", "w", stdout);
    int cas;
    int n,m;
    int i;
    double sum,x;
    bool flag;
    scanf("%d",&cas);
    for(int cask = 1; cask <= cas; cask++){
        scanf("%d",&n);
        sum = 0;
        for(i = 0; i < n; i++)
            scanf("%d",&a[i]),c[i] = true,sum += a[i];
        
        do{
            flag = false;
            x = 0;m = 0;
            for(i = 0; i < n; i++){
                if(c[i]) x += a[i],m++;
            }
//            if(m == 0) break;
            x = (x+sum)/m;
            for(i = 0; i < n; i++){
                if(c[i]){
                    if(a[i] > x){
                        c[i] = false;
                        b[i] = 0.0;
                        flag = true;
                    }
                }
            }
        }while(flag);
        for(i = 0; i < n; i++){
            if(c[i]){
                b[i] = (x-a[i])/sum*100;
            }
        }
        
        
        printf("Case #%d:",cask);
        for(i = 0; i < n; i++){
            printf(" %lf",b[i]);
        }
        printf("\n");
    }
}