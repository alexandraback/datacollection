#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;


int main (){
    int T;
    scanf("%d",&T);
    for(int I=1; I<=T ; I ++){
        set<int> s;
        int n;
        scanf("%d",&n);
        for(int i = 0 ; i < 2*n-1 ; i ++){
            for(int j = 0 ; j < n ; j ++){
                int tmp;
                scanf("%d",&tmp);
                if(s.find(tmp)==s.end())s.insert(tmp);
                else s.erase(tmp);
            }
        }
        printf("Case #%d:",I);
        for(auto x=s.begin() ; x != s.end() ; x++){
            printf(" %d",*x);
        }
        puts("");
    }
}
