#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define MAX 510

int T;
int S;
int a[MAX];
int sum = 0, thisSum;
map<int, vector<int> > nums;
int m1, m2;
inline bool check(int mask1, int mask2){
    for (int i = 0; i < S; i++) if (((mask1>>i)&1) && ((mask2>>i)&1)) return false;
    return true;
}
int main(){
    cin>>T;
    for (int tt = 1; tt <= T; tt++){
        cin>>S;
        sum = 0;
        for (int i = 0; i < S; i++) cin>>a[i], sum += a[i];
        bool found = false;
        nums.clear();
        int mask;
        for (mask = 0; mask < (1<<S); mask++){
            thisSum = 0;
            for (int i = 0; i < S; i++)
                if ((mask>>i)&1) thisSum += a[i];
            nums[thisSum].push_back(mask);
        }
        for (map<int, vector<int> >::iterator it = nums.begin(); !found && it != nums.end(); it++){
            vector<int> &a = it->second;
            int ss = it->first;
            
            for (int i = 0; !found && i < (int)a.size(); i++)
                for (int j = 0; !found && j < (int)a.size(); j++) if (i != j){
                    if (check(a[i],a[j])){
                        found = true;
                        m1 = a[i];
                        m2 = a[j];
                        //printf("ss:%d m1: %d m2:%d\n",ss,m1,m2);
                        break;
                    }
                }
        }
        printf("Case #%d:\n",tt);
        if (!found) printf("Impossible\n");
        else {
            for (int i = 0; i < S; i++)
                if ( (m1>>i)&1) printf("%d ",a[i]);printf("\n");
            for (int i = 0; i < S; i++)
                if (( (m2>>i)&1)) printf("%d ",a[i]);printf("\n");
            
        }
    }
}