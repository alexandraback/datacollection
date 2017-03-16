#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<map>
#include<set>
#include<time.h>
using namespace std;
set<pair<int, int> > chk;
int lo, hi, len;
int arr[20];
int main(){
    int cas, ans;
    scanf("%d",&cas);
    for(int iii=0;iii<cas;iii++){
        scanf("%d%d",&lo, &hi);
        chk.clear();
        ans = 0;
        
        int len = 0, ten = 1;
        int cp = lo;
        while(cp>0){
            cp = cp/10;
            len++;
            ten = ten*10;
        }
        ten/=10;
        for(int i=lo; i<=hi;i++){
            cp = i;
            for(int j=0;j<len;j++){
                arr[j] = cp%10;
                cp/=10;
            }
            cp = i;
            for(int j=0;j<len;j++){
                cp = cp/10+arr[j]*ten;
                if(cp<=i || cp>hi) continue;
                if(arr[j] == 0) continue;
                pair<int, int> nnn = pair<int, int>(i, cp);
                if(chk.find(nnn) == chk.end()){
                    chk.insert(nnn);
                    ans++;   
                }
            }
        }
        printf("Case #%d: %d\n", iii+1, ans);
    }
    scanf(" ");
    return 0;
}
