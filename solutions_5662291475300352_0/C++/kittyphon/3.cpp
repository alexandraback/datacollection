#include<stdio.h>

int main() {
    FILE* fin = fopen("C-small-1-attempt2.in","r");
    FILE* fout = fopen("out.txt","w");
    int t;
    fscanf(fin,"%d",&t);
    for(int tt=1;tt<=t;tt++) {
        int n;
        int ans=0;
        fscanf(fin,"%d",&n);
        if(n==1) {
            int a,b,c;
            fscanf(fin,"%d %d %d",&a,&b,&c);
            ans = 0;
        }
        else {
            double a,b,c,d,e,f;
            fscanf(fin,"%lf %lf %lf",&a,&b,&c); // first
            fscanf(fin,"%lf %lf %lf",&d,&e,&f); // second
            if(c==f)
                ans=0;
            else {
                if(a>d) {
                    double temp = a;
                    a=d;
                    d=temp;
                    temp=c;
                    c=f;
                    f=temp;
                }
                if(c<f) {
                    double meet = d+(c*(d-a)/(f-c));
                    if(meet>=360)
                        ans = 0;
                    else {
                        double nextmeet = meet+(c*360/(f-c));
                        if(nextmeet<=360)
                            ans = 1;
                        else
                            ans = 0;
                    }
                }
                else {
                    double meet = a+(f*(360-d+a)/(c-f));
                    if(meet<=360)
                        ans=1;
                    else
                        ans=0;
                }
            }
        }
        fprintf(fout,"Case #%d: %d\n",tt,ans);
    }
    return 0;
}
