#include<cstdio>
#include<vector>

using namespace std;

void factor(int x, vector<int> &primes,vector<int> &count){
    int i,j,k;
    for(i=0;i<primes.size();i++){
        for(j=0;x%primes[i]==0;j++){
            x/=primes[i];
        }
        if(j>count[i]){
            count[i]=j;
        }
    }
}

int main(){
    vector<int> primes;
    vector<int> count;
    int i,j,k,l,m,n,o,p,r,s,t;
    
    primes.resize(4);
    count.resize(4,0);
    
    primes[0]=2;
    primes[1]=3;
    primes[2]=5;
    primes[3]=7;
    
    scanf("%d",&l);
    scanf("%d",&r);
    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%d",&k);
    
    printf("Case #1:\n");
    
    for(i=0;i<r;i++){
        for(j=0;j<k;j++){
            scanf("%d",&p);
            factor(p,primes,count);
        }
        for(j=0;j<n;j++){
            for(s=0;(count[s]==0)&&(s<4);s++){
            }
            if(s<4){
                t=1;
                while((count[s] > 0)&&(t*primes[s]<=m)){
                    count[s]--;
                    t*=primes[s];
                }
                printf("%d",t);
            }else{
                printf("1");
            }            
        }
        for(j=0;j<4;j++){
            count[j]=0;
        }
        putchar('\n');
    }
    
    return 0;
}
