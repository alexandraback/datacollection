#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

int t;

int e, r, n;
int mas[100];

int req(int num, int te, int sum){
    if (num == n - 1)
        return sum + te * mas[n - 1];
    int maxres = 0;
    for (int i = 0; i <= te; i++)
        maxres = max(req(num + 1, min(te - i + r, e), sum + mas[num] * i), maxres);
    
    return maxres;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &t);
    for (int i = 0; i < t; i++){
        
        scanf("%d%d%d", &e, &r, &n);
        for (int j = 0; j < n; j++)
            scanf("%d", &mas[j]);
        printf("Case #%d: %d\n", i + 1, req(0, e, 0));

       
    }


    return 0;
}
