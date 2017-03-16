#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
using namespace std;
typedef long long LL;
#define MAXN 100


int main()
{
    int T;
    
    freopen("/Users/thedream/Desktop/cpp/cpp/input","r",stdin);
    freopen("/Users/thedream/Desktop/cpp/cpp/output","w",stdout);
    
    scanf("%d",&T);
    
    for (int t=1;t<=T;t++) {
        int N;
        cin >> N;
        int heights[2555] = {0,};
        int h;
        for(int i=1;i<N*2;i++){
            for(int j=0;j<N;j++){
                cin >> h;
                heights[h] ++;
            }
        }
        printf("Case #%d: ",t);
        for(int i=1;i<=2500;i++){
            if(heights[i]%2==1){
                cout << i << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}