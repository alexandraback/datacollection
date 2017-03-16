#include<cstdio>

using namespace std;

const int max_S = 2000009;
const int max_N = 29;
bool sums[max_S];
int nums[max_N];

void clear() {
    for(int i=0; i<max_S; i++)
        sums[i] = false;
}
int add_sum(int bin) {
    int sum = 0;
    for(int i=1, j=0; i<=bin; i<<=1, j++)
        if(i & bin) {
            sum += nums[j];
        }
    if(sums[sum] == false) {
        sums[sum] = true;
        return -1;
    }
    return sum;
}
int print_sum(int bin) {
    for(int i=1, j=0; i<=bin; i<<=1, j++) {
        if(i & bin)
            printf("%d ", nums[j]);
    }
    printf("\n");
}
int main() {
    int tc;
    scanf("%d", &tc);
    for(int ttc=1; ttc<=tc; ttc++) {
        int N;
        scanf("%d", &N);
        for(int i=0; i<N; i++)
            scanf("%d", &nums[i]);
        printf("Case #%d: ", ttc);
        clear();
        int maxx = 1 << N;
        int res = -1;
        for(int bin=1; bin < maxx; bin++) {
            res = add_sum(bin);
            if(res > -1)
                break;
        }
        printf("\n");
        if(res == -1) {
            printf("Impossible\n");
            continue;
        }
        clear();
        int times = 0;
        for(int bin=1; bin < maxx; bin++) {
            add_sum(bin);
            if(sums[res]) {
                print_sum(bin);
                sums[res] = false;
                times++;
            }
            if(times==2)
                break;
        }

        
    }

}
