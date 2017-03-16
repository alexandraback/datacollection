#include<stdio.h>
#include<stdlib.h>

int t,m,n,x;
unsigned long long an[200],bn[200];
unsigned long long max;
int at[200],bt[200];
FILE* in;
FILE* out;



void solve(unsigned long long ama,int tya,unsigned long long amb,int tyb,int nn,int mm,unsigned long long now){
    
    if(nn>=n || mm>=m) return;
    if(tya==tyb){
        //if(x==15)printf(" | %lld %d : %lld %d : %lld| \n",ama,tya,amb,tyb,now);
        
        if(ama<amb){ //pack all a
            now+=ama;
            amb-=ama;    
            nn++;
            if(nn>=n){
                if(now > max) max = now;
                return;
            }
            tya=at[nn];
            ama=an[nn];
            solve(ama,tya,amb,tyb,nn,mm,now);
        }
        else if(ama>amb){ //pack all b
            now+=amb;
            ama-=amb;
            mm++;
            if(mm>=m){
                if(now > max) max = now;
                return;
            }
            tyb=bt[mm];
            amb=bn[mm];
            solve(ama,tya,amb,tyb,nn,mm,now);
        }
        else{ //pack a b
            now+=ama;
            mm++;
            nn++;
            if(mm>=m || nn>=n){
                if(now > max) max = now;
                return;
            }
            tyb=bt[mm];
            amb=bn[mm];
            tya=at[nn];
            ama=an[nn];
            solve(ama,tya,amb,tyb,nn,mm,now);
        }
    }
    else{
        solve(an[nn+1],at[nn+1],amb,tyb,nn+1,mm,now); //toss all a
        solve(ama,tya,bn[mm+1],bt[mm+1],nn,mm+1,now); //toss all b
    }
}

int main(){

    in=fopen("d:/input3.in","r");
    out=fopen("d:/output3.out","w");

    fscanf(in,"%d",&t);
  
    for(x=1;x<=t;x++){
        fscanf(in,"%d %d",&n,&m);
        fprintf(out,"Case #%d: ",x);
        for(int i=0;i<n;i++) fscanf(in,"%lld %d",&an[i],&at[i]);
        for(int i=0;i<m;i++) fscanf(in,"%lld %d",&bn[i],&bt[i]);
        
        int typea,typeb;
        unsigned long long amounta,amountb,count;
        count=0;
        
        typea=at[0];
        amounta=an[0];
        typeb=bt[0];
        amountb=bn[0];
        max=0;
        
        solve(amounta,typea,amountb,typeb,0,0,0);
    
        fprintf(out,"%lld\n",max);
    }   
    //system("pause");
}
