#include<cstdio>
#include<cstdlib>
#include<algorithm>

const int MAXN = 100;
int a[MAXN];
int n,m,noc;

int main(int argc,char* argv[]){
    scanf("%d",&noc);
    for (int tnoc=1;tnoc<=noc;++tnoc){
        printf("Case #%d: ",tnoc);
        scanf("%d%d",&m,&n);
        for (int i=0;i<n;++i){
            scanf("%d",&a[i]);
        }
        std::sort(a,a+n);
        int answer = n;
        int count = 0;
        int tmp = m;
        for (int i=0;i<n;++i){
            while (tmp<=a[i]){
                ++count;
                if (count>answer){
                    break;
                }
                tmp += tmp-1;
            }
            if (count>answer){
                break;
            }
            tmp += a[i];
            if (count+(n-1-i)<answer){
                answer = count+(n-1-i);
            }
        }
        printf("%d\n",answer);
    }
    return 0;
}
