#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    long long int i,j,k,l,m,n,o,p;
    long long int b,e,mid;
    char c;
    vector<long long int> pole;
    
    scanf("%lld",&m);
    
    for(l=1;l<=m;l++){
        pole.clear();
        c=getchar();
        while(c=='\n'){
            c=getchar();
        }
        pole.push_back(0);
        while(c!=' '){
            switch(c){
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    pole.push_back(0);
                    break;
                default:
                    pole.push_back(1);
                    break;
            }
            c=getchar();
        }
        scanf("%lld",&n);
        
        /*printf("%lld\n",n);
        for(i=0;i<pole.size();i++){
            printf("%lld ",pole[i]);
        }putchar('\n');*/
        
        if(n==0){
            printf("Case #%lld: %lld\n",l,n*(n+1)/2);
        }else{
            p=0;
            for(i=0;i<pole.size();i++){
                if(pole[i]==1){
                    p++;
                    if(p>=n){
                        pole[i]=1;
                    }else{
                        pole[i]=0;
                    }
                }else{
                    pole[i]=0;
                    p=0;
                }
            }
            
            /*for(i=0;i<pole.size();i++){
                printf("%lld ",pole[i]);
            }putchar('\n');*/
            
            p=0;
            for(i=0;i<pole.size();i++){
                p+=pole[i];
                pole[i]=p;
            }
            
            /*for(i=0;i<pole.size();i++){
                printf("%lld ",pole[i]);
            }putchar('\n');*/
            
            /*k=0;
            for(i=1;i<pole.size()-n+1;i++){
                b=i+n-2;
                e=pole.size()-1;
                while(e-b>1){
                    mid = (b+e)/2;
                    if((pole[mid]-pole[i+n-2])>=1){
                        e=mid;
                    }else{
                        b=mid;
                    }
                }
                //k+=pole[pole.size()-1] - pole[i+n-2];
                k+=b-(i+n-2);
            }*/
            k=0;
            for(i=0;i<pole.size();i++){
                if(pole[i]>0){   
                    b=0;
                    e=i+1;
                    while(e-b>1){
                        mid = (b+e)/2;
                        if((pole[i]-pole[mid])>0){
                            b=mid;
                        }else{
                            e=mid;
                        }
                    }
                    //printf("%lld %lld\n",i,b);
                    if(b-n+2>0){
                        k+=b-n+2;
                    }
                }
            }
            printf("Case #%lld: %lld\n",l,k);
        }
    }
    
    return 0;
}
