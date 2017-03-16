#include <iostream>
#include <algorithm>
#define TASK "A"
#define Small "-small-attempt"
#define NUM "0"
#include <string>
#include <map>
#include <set>

using namespace std;

int test;
int n;
char s[1000010];
int a[1000010];
int b[1000010];
long long answer;

bool isVocal(char c){
    return (c=='a' || c=='o' || c=='i' || c=='e' || c=='u');    
}

void readinput(){
    scanf("%s %i\n",s,&n);
    //printf("!! %i\n",n);
}

void solve(){
    answer = 0;
    int len = 0;
    for (int i=0;s[i];i++){
        if (isVocal(s[i]))
        {
            a[i]=0;    
        }else{
            a[i]=1;
            if (i>0) a[i]+=a[i-1];                
        }
        len++;        
    }
    int pos;
    for (int i=len-1;i>=0;i--){
        if (a[i]>0)
        {            
            if (len-1==i || a[i]>a[i+1]){
                pos = i;                    
            }
            b[i]=pos;
        }
        else
        {
            b[i]=i;    
        }            
    }
    /*for (int i=0;i<len;i++){
        printf("%i ",b[i]);    
    }
    cout<<endl;*/
    
    int Q=0;
    int max = 0;
    int maxpos = -1;
    for (int i=0;i<len;i++){
        if (b[i]>=Q) max--;
        if (max<n)
        {
            int cur=0;
            while (Q<len){
                int num = a[Q];
                if (b[i]>=Q)
                {
                    if (i>0)
                    {
                        num-=a[i-1];    
                    }    
                }
                if (num>cur) cur = num;
                if (cur>max) max = cur;
                if (max>=n) break;    
                Q++;
            }
        }        
        if (max>=n){
            answer = answer + ((long long)len - Q);                
        }
        //printf("%i %i   %i\n",i,Q,max);
    }
}

void writeoutput(int t){
    printf("Case #%i: ",t+1);        
    cout<<answer<<endl;
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
