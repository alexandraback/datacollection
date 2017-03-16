#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    for(int _=0; _< T;_++){
        int n;
        scanf("%d",&n);
        int tmp;

        vector<double> naomi;
        vector<double> ken;

        for(int i = 0 ;i<n;i++){
            scanf("%f",&tmp);
            naomi.push_back(tmp);

        }
        for(int i = 0 ;i<n;i++){
            scanf("%f",&tmp);
            ken.push_back(tmp);
        }
        sort(naomi.begin(), naomi.end());
        sort(ken.begin(), ken.end());
        int ans_ken = 0;
        int ans_naomi = 0;
        int ken_r = n-1, ken_l = 0;
        for(int i = 0 ; i< n;i++){
            if(naomi[i] < ken[ken_l]){
                ken_r--;
            }else{
                ans_naomi++;
                ken_l++;
            }
        }
        ken_l = 0;
        for(int i = 0 ;i < n ;i++){
            while(ken_l < n && naomi[i]> ken[ken_l]){
                ans_ken++;
                ken_l++;
            }
            ken_l++;
            if(ken_l >= n) break;
        }
        printf("Case #%d: ",_+1);
        printf("%d %d\n",ans_naomi, ans_ken);
    }
    return 0;
}
