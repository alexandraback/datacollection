#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<cstring>
#include<set>
#include<cmath>

using namespace std;
vector<long long> pal;
const int print = 0;
bool ispal(long long i){
    int a[10];
    int idx = 0;
    while(i){
        a[idx] = i%10;
        i/=10;
        idx++;
    }
    for(int j=0;j<idx;++j){
        if(a[j]!=a[idx-j-1])
            return false;
    }
    return true;
}
void init()
{
    for(long long i=1;i<10000000;++i){
        if(ispal(i) and ispal(i*i)){
            pal.push_back(i*i);
        }
    }
    if(print) cout << pal.size() << endl;
}
int gao(int a,int b)
{
    int cnt = 0;
    for(int i=0;i<pal.size();++i){
       if(pal[i]>=a && pal[i]<=b)
           cnt++;
    }
    return cnt;
}
int main()
{
    init();
    int T; cin >> T;
    int idx = 0;
    while(T--){
       idx ++;
       int A,B; cin >>A >> B;
       cout << "Case #" << idx << ": " << gao(A,B) << endl;
    }
}
