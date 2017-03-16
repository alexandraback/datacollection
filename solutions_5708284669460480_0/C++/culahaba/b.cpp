#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define fi "b.inp"
#define fo "b.out"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int ntest, keys,needs,attemp;
long maxr, sum, dem, demkq;
char s[10], keyboard[10], need[10], array[10000], d[10000];


void input();
void output();

void check(){
    int i, j;
    long temp;
    
    temp = 0;
    
    for(i=0;i<attemp;i++){
        if(s[i] == need[0]){
            for(j=0;j<needs;j++){
                if(i+j >= attemp || s[i+j] != need[j]){
                    break;
                }
            }
            
            if(j == needs){
                temp++;
            }
        }
    }
    
    sum += temp;
    maxr = max(maxr, temp);
}

void dequy(int dept){
    int i;
    
    if(dept == attemp){
        //s[dept] = '\0';
        //printf("%s\n",s);
        demkq++;
        check();
        return;
    }
    
    for(i=0;i<dem;i++){
        s[dept] = array[i];
        dequy(dept + 1);
    }
}

void solve(){
    int i, j;
    
    for(i='A';i<='Z';i++)
        d[i] = 0;
        
    dem = 0;
    demkq = 0;
    sum = 0;
    maxr = 0;
        
    for(i=0;i<keys;i++){
        d[keyboard[i]]++;
        //if(d[keyboard[i]] == 1){
            array[dem++] = keyboard[i];
        //}
    }
    
    dequy(0);
}

void input()
{
    int i;
    scanf("%d",&ntest);
    for(i=0;i<ntest;i++){
        scanf("%d %d %d",&keys,&needs,&attemp);
        scanf("%s %s",&keyboard,&need);
        
        solve();
        
        printf("Case #%d: %0.7f\n",i+1,maxr*1.0 - sum*1.0/(demkq*1.0));
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
