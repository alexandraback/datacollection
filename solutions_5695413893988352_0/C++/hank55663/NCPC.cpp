#include<bits/stdc++.h>
using namespace std;
main(){
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        char a[100],b[100];
        scanf("%s %s",a,b);
        int length=strlen(a);
        int Min=1000;
        char ansa[4],ansb[4];
        memset(ansa,0,sizeof(ansa));
        memset(ansb,0,sizeof(ansb));
        for(int i=0;i<1000;i++)
        for(int j=0;j<1000;j++){
            char c[4],d[4];
            memset(c,0,sizeof(c));
            memset(d,0,sizeof(d));
            int e=i,f=j;
            while(length){
                c[length-1]=e%10+'0';
                d[length-1]=f%10+'0';
                length--;
                e/=10;
                f/=10;
            }
            length=strlen(a);
            if(e!=0||f!=0)
                break;
            int ok=1;
            for(int k=0;k<length;k++){
                if(a[k]!='?'&&a[k]!=c[k])
                    ok=0;
                if(b[k]!='?'&&b[k]!=d[k])
                    ok=0;
            }
            if(ok){
                if(Min>abs(i-j))
                {
                    Min=(abs(i-j)+0.5);
                    for(int i=0;i<4;i++)
                    {ansa[i]=c[i];
                    ansb[i]=d[i];

}                }
            }
        }
        printf("Case #%d: %s %s\n",t,ansa,ansb);
    }
}
