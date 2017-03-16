#include<stdio.h>
#include<memory.h>
int n,l[1010],check[1010],two[1010],tc,check2[1010],gap2[1010];
FILE *fo = fopen("/Users/JungRockJoon/Desktop/Rock/Algorithm/Codejam2016/Roun1/3/input.txt","r");
FILE *fp = fopen("/Users/JungRockJoon/Desktop/Rock/Algorithm/Codejam2016/Roun1/3/output.txt","w");
int main(){
    int t,T,i,j;
    fscanf(fo,"%d",&T);
    for(t=1;t<=T;t++){
        memset(l,0,sizeof(l));
        memset(two,0,sizeof(two));
        memset(check2,0,sizeof(check2));
        memset(gap2,0,sizeof(gap2));
        tc = 0;

        fscanf(fo,"%d",&n);
        for(i=0;i<n;i++) {
            fscanf(fo, "%d", &l[i]);
            l[i] --;
        }
        // max cycle
        int max = 1;
        for(i=0;i<n;i++){
            memset(check,0,sizeof(check));
            int now = i,cnt = 0;
            while(check[now] == 0){
                check[now] = 1;
                cnt ++;
                now = l[now];
            }
            if(now == i) {
                if(cnt > max)
                    max = cnt;
                if(cnt == 2){
                    two[tc++] = i;
                    check2[i] = 1;
                }
            }
        }
        int add = tc;
        for(i=0;i<n;i++){
            if(check2[i] == 0){
                memset(check,0,sizeof(check));
                int now = i,cnt = 0;
                while(check[now] == 0){
                    check[now] = 1;
                    cnt ++;
                    now = l[now];
                    if(check2[now] == 1){
                        if(gap2[now] < cnt){
                            gap2[now] = cnt;
                        }
                        break;
                    }
                }
            }
        }
        for(i=0;i<n;i++){
            if(check2[i] == 1){
                add += gap2[i];
            }
        }
        fprintf(fp,"Case #%d: ",t);
        if(add < max){
            fprintf(fp,"%d\n",max);
        }else{
            fprintf(fp,"%d\n",add);
        }
    }
    return 0;
}

