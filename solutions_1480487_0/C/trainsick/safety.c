
#include <stdio.h>

int main(int argc, char **argv) {
    int tc,cn;
    int n,n2,i;
    int v[220];
    int z[220];
    int total,t2;
    double f,m,nz;
    scanf("%d",&tc);
    for (cn=1;cn<=tc;cn++) {
        printf("Case #%d: ",cn);
        scanf("%d",&n);
        total=0;
        for (i=0;i<n;i++) {scanf("%d",v+i);total+=v[i];z[i]=0;}
        //if (n==2) m=1.0;
        //else 
        do {
            t2=0;nz=0;n2=0;
            for (i=0;i<n;i++) if (!z[i]) {t2+=v[i];n2++;}
            m=(1.0*(total+t2)/total)/n2;
            for (i=0;i<n;i++) {
                f=m-1.0*v[i]/total;
                if (f<0.0 && !z[i]) {z[i]=1;nz++;}
            }
        } while (nz);
        //printf("m=%.3f to=%d t2=%d\n",m);
        for (i=0;i<n;i++) {
            f=m-1.0*v[i]/total;
            if (z[i]) {f=0.0;}
            f*=100.0;
            printf("%.8f ",f);
        }
        
        printf("\n");
    }
    return 0;
}
