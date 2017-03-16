#include <cstdio>
#include <vector>
#include <map>
#define pb push_back
using namespace std;

int i, j, n, sum;
bool l;
int a[30];
vector <int> ans;
map <int, int> M[30];

void PrintAns(int v){
     ans.clear();
     for (j = 0; j < n; j++)
         if (v & (1 << j))
            ans.pb(a[j]);
     printf("%d", ans[0]);
     for (j = 1; j < ans.size(); j++)
         printf(" %d", ans[j]);
     printf("\n");
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for (int test = 1; test <= t; test++){
        scanf("%d",&n);
        for (i = 0; i < n; i++){
            scanf("%d",&a[i]);
            sum += a[i];
        }
        l = true;
        printf("Case #%d:\n", test);
        for (i = 0; i < (1 << n); i++){
            sum = 0;
            for (j = 0; j < n; j++)
                if (i & (1 << j))
                   sum += a[j];
            if (M[test][sum]){
               l = false;
               PrintAns(i);
               PrintAns(M[test][sum]);
               break;
            }
            M[test][sum] = i;
        }
        if (l) printf("Impossible\n");
    }
    return 0;
}
