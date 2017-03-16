#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
#include <string>
using namespace std;

#define N 20
#define MAX 100000 * 20

int t;

int n;


int l[N];

vector< vector<int> > a[MAX];
int main(){

    scanf("%d", &t);

    for(int z = 0; z < t; z++){
        for(int i = 0; i < MAX; i++){
            a[i].clear();
        }
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", l + i);
        }

        int found = -1;

        for(int i = 0; i < (1<<N); i++){
            int sum = 0;
            vector<int> v;
            int k = 0;
            int d = i;
            while(d > 0){
                if(d % 2){
                    v.push_back(l[k]);
                    sum += l[k];
                }
                d /= 2;
                k++;
            }

            a[sum].push_back(v);
            if(a[sum].size() > 1){
                found = sum;
                break;

            }
        }

        printf("Case #%d:\n", z + 1);
        if(found){
            for(int i = 0; i < 2; i++){
                for(int k = 0; k < a[found][i].size(); k++){
                    printf("%d ", a[found][i][k]);
                }

                printf("\n");
            }

        }
        else{
            printf("Impossible\n");
        }
    }

    return 0;
}
