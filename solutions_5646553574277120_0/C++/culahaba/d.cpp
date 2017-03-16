#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

#define fi "d.inp"
#define fo "d.out"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int ntest, maxc, coins, maxval;
int a[1010], c[1010];
bool d[1010];

void input();
void output();

int solve(){
    int i, j;
    int ketqua;
    
    for(i=1;i<=maxval;i++){
        d[i] = false;
    }
    
    d[0] = true;
        
    for(i=0;i<coins;i++){
        for(j=maxval;j>=a[i];j--){
            d[j] |= d[j - a[i]];
        }
    }
    
    ketqua = 0;
    
    while(1){
        for(i=1;i<=maxval;i++){
            if(!d[i])
                break;
        }
                
        if(i > maxval)
            break;
            
        ketqua++;
        
        for(j=maxval;j>=i;j--){
            d[j] |= d[j - i];
        }
    }
    
    printf("%d\n",ketqua);
}

void input()
{
    int i, j;
    
    scanf("%d",&ntest);
    
    for(i=0;i<ntest;i++){
        scanf("%d %d %d",&maxc,&coins,&maxval);
        
        for(j=0;j<coins;j++)
            scanf("%d",&a[j]);
        
        printf("Case #%d: ", i + 1);
        solve();
    }
}

void output()
{
}


int main() {
	
	//freopen(fi,"r",stdin);
	//freopen(fo,"w",stdout);
	
	input();
	
	return 0;
}
