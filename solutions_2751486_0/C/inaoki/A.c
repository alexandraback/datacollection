#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int iscons(int a){
    if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u'){
        return 0;
    }
    return 1;
}

int main(){
    int t;    
    int p,n,len,i,j,c,a;
    int cnscount;
    int bef,aft;
    unsigned long long val;
    int cns[1000001];
    int cnsst[1000001];
    scanf("%d\n",&t);
    for(p=0;p<t;p++){
        i=0;c=0;val = 0;
        while((a=getchar()) != ' '){
            if(iscons(a)){
                c++;
            }else{
                c=0;
            }
            cns[i]=c; 
            i++;
        }
        len = i;
        scanf("%d\n",&n);
        //read done
        cnscount = 0;
        for(i=0;i<len;i++){
            if(cns[i] >= n){
                cnsst[cnscount] = i;
                cnscount++;
            }
        }
        for(i=0;i<2;i++){
            for(j=0;j<cnscount - i;j++){
                bef = cnsst[j] + 1 - n + 1;
                aft = len - cnsst[j+i];
//                printf("i:%d bef,%d,aft,%d\n",i,bef,aft);
                if(i==0){
                    val = val + (unsigned long long)bef * aft;
                }else {
                    val = val - (unsigned long long)bef * aft;
                }
            }
        }
        
        // done
/*
        for(i=0;i<len;i++){
            printf("%d",cns[i]);
        }
*/
        printf("Case #%d: %lld\n",p+1,val);
    }
    return 0;
}
