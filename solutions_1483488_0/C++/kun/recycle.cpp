#include<cstdio>
#include<cstdlib>
int a,b,n,ct = 1,ans = 0,T;
int main(){
    freopen("C-small-attempt0.in","r",stdin);
    freopen("test.txt","w",stdout);
    scanf("%d",&T);
    for(int i=0;i<T;i++){
       scanf("%d%d",&a,&b);
       ans = 0;
       for(int j=a;j<b;j++){
           n = j;ct = 1;
           while(ct*10 <= j) ct*= 10;
           n = (j%10)*(ct) + j/10;
           while(n!=j){
              if(n >= a && n<=b && n > j) {ans++;} 
              n = (n%10)*(ct) + n/10;    
           }
       }        
       printf("Case #%d: %d\n",i+1,ans);  
    }
    //system("pause");
    return 0;
}
