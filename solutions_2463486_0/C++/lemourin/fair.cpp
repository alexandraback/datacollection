#include<cstdio>
#include<vector>
#include<algorithm>
typedef long long int LL;
const int MAXGEN = 1e7+5;

std::vector<LL> nums;

bool isPalindrome(LL n) {
    LL p10 = 1, a = n;

    while (a > 0)
        p10*=10, a/=10;
    
    LL rev = 0; a = n;
    while (a > 0)
        p10/=10, rev+=(a%10)*p10, a/=10;

    return rev == n;
}

int main() {
    for (int i=1; i<MAXGEN; i++)
        if (isPalindrome(i) && isPalindrome((LL)i*i)) {
            nums.push_back((LL)i*i);
            //printf("%Ld\n", nums.back());
        }
    nums.push_back(1LL << 62);
        
    int t; 
    scanf("%d", &t);

    int test = 0;
    while (t--) {
        test++;

        LL a, b; 
        scanf("%Ld%Ld", &a, &b);

        int p1 = std::lower_bound(nums.begin(), nums.end(), a)-nums.begin();
        int p2 = std::upper_bound(nums.begin(), nums.end(), b)-nums.begin()-1;
        //printf("%Ld %Ld\n", nums[p1], nums[p2]);

        printf("Case #%d: %d\n", test, p2-p1+1);
    }
}
