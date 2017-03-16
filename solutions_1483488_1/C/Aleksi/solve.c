#include<stdio.h>
#include<string.h>

char buf[1000];
char* cb=buf+900;
int len;

int recycle(){
    int ret;
    cb--;
    cb[0]=cb[len];
    cb[len]=0;
    ret = atoi(cb);
    return ret;
}


int main(){
    int t;
    int tn;
    scanf("%i\n",&t);
    
    for(tn=1;tn<=t;tn++){
        int a,b;
        int n,m;
        int result=0;
        scanf("%i %i",&a,&b);
        for(n = a;n<=b;n++){
            cb = buf+900;
            len = sprintf(cb,"%i",n);
            do{
                m = recycle();
                if(m>n && m <= b)
                    result++;
            }while(n!=m);

        }
        printf("Case #%i: %i\n",tn,result);
    }
    return 0;
}
