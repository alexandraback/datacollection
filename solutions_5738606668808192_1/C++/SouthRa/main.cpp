#include <cstdio>

using namespace std;

int cnt, N, J;

void produce(int a)
{
    if(cnt==J) return;
    char s[40];
    int base[40];
    int index=0, len=0, i, tmp, add, j;
    while(a){
        len++;
        if(a%2) base[index]=1;
        else base[index]=0;
        index++;
        a/=2;
    }
    for(i=0;i<len;i++) s[len-1-i]='0'+base[i];
    for(i=0;i<len;i++) s[N-1-i]='0'+base[i];
    for(i=len;i<N-len;i++) s[i]='0';
    s[N]='\0';
    printf("%s ", s);
    for(i=2;i<=10;i++){
        tmp=0;
        add=1;
        for(j=0;j<len;j++){
            if(base[j]==1) tmp+=add;
            add*=i;
        }
        printf("%d ", tmp);
    }
    puts("");
    cnt++;
}

int main()
{
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);
    int t, i;
    scanf("%d", &t);
    scanf("%d %d", &N, &J);
    cnt=0;
    puts("Case #1:");
    for(i=1;;i++){
        if(cnt==J) break;
        produce(i*2+1);
    }
    return 0;
}
