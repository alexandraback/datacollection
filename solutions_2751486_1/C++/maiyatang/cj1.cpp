
#include <stdio.h>

long a[1100000];

int main(){
    
    long long t,tt,i,m,k,st,en,last;
    
    long long neg,ans,t2;
    
    char c;
    
    freopen("A-large.in", "r",stdin);
    freopen("A-large.out", "w",stdout);

    
    scanf("%lld",&t);
    
    for (tt=1;tt<=t;tt++){
        
        m=0;
        scanf("%c",&c);
        while (c<'a'||c>'z'){
            
            scanf("%c",&c);
        }
        
        while ((c>='a')&&(c<='z')){
            
            if ((c=='a')||(c=='e')||(c=='i')||(c=='o')||(c=='u')){
                
                a[m]=0;
            }
            else {
                
                a[m]=1;
            }
            
            m++;
            scanf("%c",&c);
        }
        scanf("%lld",&k);
        
        st=0;
        
        neg=0;
        
        en=0;
        last=0;
        
        for (i=0;i<m;i++){
            
            if (a[i]){
                
                last++;
                
                if (last>=k){
                    
                    en=i-k+2;
                }
            }
            else {
                
                last=0;
            }
            
            neg+=(i-en+1);
        }
        
        
        t2=m*(m+1);
        t2/=2;
        
        ans=t2-neg;
        
        
        printf("Case #%lld: %lld\n",tt,ans);
    
        
    }
    return 0;
}
