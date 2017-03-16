#include<iostream>
#include<string>
#include<sstream>
#include<cstdio>
#include<stack>
#include<vector>
#include<algorithm>
#include<map>
#include<climits>
#include<cmath>
#include<memory.h>
#include<sstream>
#include<queue>
#include<time.h>

using namespace std;
typedef long long ll;

int main(){
    #ifdef LOCAL
        //freopen("input.txt", "r", stdin);
        freopen("A-large.in", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif


    int ntest;
    while(cin>>ntest){
        for(int tt=1; tt<=ntest; tt++){
            ll r, t;
            cin>>r>>t;
            ll init = 2*r + 1;

            ll left = 0;
            ll right = 1e9;
            ll tmp = 2*1e18;
            right = min( tmp/init, right);
            ll mid = (left+right)/2;
            while(left<right){
                mid = (left+right)/2;
                if( (init+2*mid)*(mid+1) < t){
                    left = mid+1;
                }else if((init+2*mid)*(mid+1) == t){
                    break;
                }else {
                    right = mid;
                }
            }

            if( (init+2* (mid+1) )* ((mid+1)+1) == t){
                mid++;
            }else if( (init+2* (mid-1) )* ((mid-1)+1) == t){
                mid--;
            }else {
                if( (init+2* (mid+1) )* ((mid+1)+1) < t){
                    mid++;
                }
            }

            while((init+2*mid)*(mid+1) > t){
                mid--;
            }

            printf("Case #%d: %lld\n", tt, mid+1);
        }

    }


    return 0;
}
