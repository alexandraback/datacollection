#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

const int max_N = 209;
int points[max_N];
int points2[max_N];

// returns cost
int setAllAt(int value, int size) {
    int cost = 0;
    for(int i=0; i<size; i++) {
        if(points2[i] < value) {
            cost += value - points2[i];
            points2[i] = value;
        }
    }
    return cost;
}
int minGreater(int value, int size) {
    int minn = -1;
    for(int i=0; i<size; i++) 
        if(points2[i] > value)
            if(minn == -1 || minn > points2[i])
                minn = points2[i];
    return minn;
}
int howManyLess(int value, int size) {
    int count = 0;
    for(int i=0; i<size; i++) {
        if(points2[i] < value)
            count++;
    }
    return count;
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int ttc=1; ttc<=tc; ttc++) {
        int N;
        scanf("%d", &N);
        int mySum = 0;
        for(int i=0; i<N; i++) {
            scanf("%d", &points[i]);
            mySum += points[i];
        }
        printf("Case #%d: ", ttc);
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++)
                points2[j] = points[j];
            int sum = mySum;
            sum -= setAllAt(points2[i], N);
            if(sum <= 0)
                printf("%lf ", (double) 0);
 
            
            while(sum > 0) {
              //  printf("sum %d\n", sum);
                int next = minGreater(points2[i], N);
                if(next == -1) {
                    next = points2[i] + max(sum/N, 1);
                }
                int cost = howManyLess(next, N) * (next-points2[i]);
                if(cost <= sum) { 
                    sum -= setAllAt(next, N);
                    if(sum == 0) {                    
                        int haveToAdd = points2[i] - points[i];
                        printf("%lf ", (((double) haveToAdd) / mySum)*100);           
                    }
                    continue;
                }
                sum -= setAllAt(next-1, N);
                int count = howManyLess(next, N);
                // kazdemu dodamy sum/count punkta
                double haveToAdd = points2[i] - points[i];
                haveToAdd += ((double) sum)/ count;
                sum = 0;
                printf("%lf ", (((double) haveToAdd) / mySum)*100);           
            }
        }
        printf("\n");
    }

}
