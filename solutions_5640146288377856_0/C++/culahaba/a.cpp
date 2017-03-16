#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define fi "a.inp"
#define fo "a.out"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;


void input();
void output();

void solve(){
    
}

void input()
{
    int i;
    int ntest, rows, cols, w, ketqua;
    scanf("%d",&ntest);
    for(i=0;i<ntest;i++){
        scanf("%d %d %d",&rows,&cols,&w);
        
        if(cols%w == 0)
            ketqua = 0;
        else
            ketqua = 1;
            
        printf("Case #%d: %d\n",i+1,cols/w*rows+w-1 + ketqua);
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
