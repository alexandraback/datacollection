#include <iostream>
#include <algorithm>
#define TASK "C"
#define Small "-small-attempt"
#define NUM "1"
#include <string>
#include <map>
#include <set>

#define DELTA 500

using namespace std;

int test;
int n;
int answer;
int m;
int all;


struct attack
{
    int t;
    int h;
    int l,r;        
};

int H[2030];
attack Q[300];

bool cmp(attack A, attack B){
    if (A.t<B.t) return true; else
    if (A.t>B.t) return false; else        
    if (A.h<B.h) return true; else
    if (A.h>B.h) return true; else
    if (A.l<B.l) return true; else
    if (A.l>B.l) return true; else
    if (A.r<B.r) return true; else
    return false;
}

void readinput(){
    all=0;    
    scanf("%i",&n);
    for (int i=0;i<n;i++){
        int m,d,w,e,s,dd,ds,dx;
        scanf("%i %i %i %i %i %i %i %i",&d,&m, &w,&e,&s,&dd,&dx,&ds);
        for (int j=0;j<m;j++)
        {
            Q[all].h = s;
            Q[all].l = w;
            Q[all].r = e;
            Q[all].t = d;
            all++;
            d+=dd;
            w+=dx;
            e+=dx;
            s+=ds;
        }
    }    
}

bool Attack_Suc(attack A)
{
    int ll = (A.l+DELTA)*2;  
    int rr = (A.r+DELTA)*2;
    
    bool suc = false;
    for (int i=ll;i<=rr;i++){
        if (A.h>H[i]){
            suc = true;
            //H[i]=A.h;    
        }            
    }   
    
    return suc;
}

void Build(attack A)
{
    int ll = (A.l+DELTA)*2;  
    int rr = (A.r+DELTA)*2;
    
//    bool suc = false;
    for (int i=ll;i<=rr;i++){
        if (A.h>H[i]){
            //suc = true;
            H[i]=A.h;    
        }            
    }   

}

void solve(){
    answer = 0;
    sort(Q,Q+all,cmp);
    memset(H,0,sizeof(H));
    
    int i=0;
    while (i<all)
    {
        int j=i;
        while (j<all && Q[i].t==Q[j].t){
            j++;    
        }
        //printf("%i-%i\n",i,j);
        //printf("%i -(%i,%i) - %i\n",Q[i].t,Q[i].l,Q[i].r,Q[i].h);    
        for (int k = i;k<j;k++){
            if (Attack_Suc(Q[k]))
            {
                answer++;
                //printf("!!!\n");
            }
        }
        for (int k =i;k<j;k++){
            Build(Q[k]);            
        }
        i=j;
    }    
}

void writeoutput(int t){
    printf("Case #%i: ",t+1);        
    printf("%i\n",answer);
}

int main(void){
    //freopen("input.txt","r",stdin);    
    freopen(TASK""Small""NUM".in","r",stdin);
    //freopen(TASK"-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%i\n",&test);

    for (int i=0;i<test;i++){
        readinput();
        solve();
        writeoutput(i);
    }
    
    return 0;    
}
