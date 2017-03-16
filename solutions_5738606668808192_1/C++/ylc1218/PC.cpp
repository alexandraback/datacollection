#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<set>
using namespace std;

int N=32, J=500;
set<long long> used;


void output(long long num, int p, int b){
    //printf("num=%lld, p=%d, b=%d\n", num, p, b);
    for(int i=N-1;i>=0;i--)
        printf("%d", (num&(1<<i))!=0);

    for(int i=2;i<=10;i++){
        long long div = 0;
        for(int j=b-1;j>=0;j--)
           div = div*i+((p&(1<<j))!=0);
        printf(" %lld", div);
        //assert(num%div == 0);
    }
    printf("\n");
}

int main(){
    int l[] = {4, 8, 16, 32};
    int cnt = 0;
    printf("Case #1:\n");
    for(int i=0;i<4;i++){
        int b = l[i];
        for(int j=0;j<(1<<(b-2));j++){
            int p = ((j<<1)|1)|(1<<(b-1));
            long long n = 0;
            for(int k=0;k<N/b;k++) n = (n<<b)|p;
            if(used.count(n) != 0) continue;

            output(n, p, b);
            used.insert(n);
            cnt++;
            if(cnt == J) break;
        }
        if(cnt == J) break;
    }
    assert(cnt == J);

    return 0;
}


