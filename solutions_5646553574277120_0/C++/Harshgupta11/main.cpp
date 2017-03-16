#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool isSubsetSum(vector<int> set, int n, int sum)
{
   
   if (sum == 0)
     return true;
   if (n == 0 && sum != 0)
     return false;
 
 
   if (set[n-1] > sum)
     return isSubsetSum(set, n-1, sum);

   return isSubsetSum(set, n-1, sum) || isSubsetSum(set, n-1, sum-set[n-1]);
}

int main()
{
    int T;
    int C,D,V,denomination;
    scanf("%d",&T);
    for(int i = 1;i<=T;++i){
        denomination = 0;    
        scanf("%d%d%d",&C,&D,&V);
        vector<int> num;
        int temp;
        for(int k = 0;k<D;++k){
            scanf("%d",&temp);
            num.push_back(temp);
        }
        sort(num.begin(),num.end());
        for(int j = 1;j<=V;++j){
            if(isSubsetSum(num,D+denomination,j) == false){
               ++denomination;
               num.push_back(j);
            }     
        }
        printf("Case #%d: %d\n",i,denomination);
    }                                    
    return 0;
}
