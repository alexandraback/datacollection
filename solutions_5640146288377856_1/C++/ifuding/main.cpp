#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;
#define maxN 1005
#define INF 0X7F7F7F7F

int R,C,W;

//int calMinStep(int c,int m)
//{
//    int size;
//    int t1,t2;
//    int ans;
//    int last;
//    size = c/m;
//    last = c%m;
//    t1 = m*size;
//    //t2 = c-t1;
//    if(last>0)
//    {
//        ans = size+m;
//    }
//    else
//    {
//        ans = size+m-1;
//    }
//    return ans;
//}
//
//int main()
//{
//    int T,R,C,M;
//    int minAns;
//    int curCase;
//    freopen("D:\\ccpptrain\\codejamround1c2\\A-large.in","r",stdin);
//    freopen("D:\\ccpptrain\\codejamround1c2\\testout3.txt","w",stdout);
//    cin>>T;
//    curCase = 0;
//    while(T)
//    {
//        T--;
//        curCase++;
//        cin>>R>>C>>M;
//        minAns = calMinStep(C,M);
//        if(R>1)
//        {
//            minAns += (R-1)*(C/M);
//        }
//
//
//        cout<<"Case #"<<curCase<<": "<<minAns<<endl;
//    }
//    return 0;
//}

int solve() {
    int ans = C/W+W;
    if(C%W == 0) {
        ans--;
    }
    if(R > 1) {
        ans += (R-1)*(C/W);
    }
    cout<<ans<<endl;
    return 0;
}

int main() {
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int t = 1;t <= T;t++) {
        cout<<"Case #"<<t<<": ";
        cin>>R>>C>>W;
        solve();
    }
    return 0;
}


