#include<cstdio>
#include<cstring>
using namespace std;

typedef long long ll;

#define fo(i , st , en) for (int i = st; i <= en; i++)

int T;
ll r , t;

int main(){
    freopen("A.in" , "r" , stdin);
    freopen("A.out" , "w" , stdout);
    scanf("%d" , &T);
    fo (p , 1 , T){
        printf("Case #%d: " , p);
        scanf("%I64d %I64d" , &r , &t);
        ll left = 1 , right = t , mid , temp = 0;
        while (left <= right){
            mid = (left + right) >> 1;
            if (t / mid >= mid + mid + r + r - 1){
                temp = mid; left = mid + 1;
            }
            else
                right = mid - 1;
        }
        printf("%I64d\n" , temp);
    }
    return 0;
}
