#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
bool palindrome(long long x){
    stack<int> st;
    queue<int> arr;
    while(x){
        int t = x%10;
        if(t == 0 && st.empty()) return false;
        x/=10;
        st.push(t);
        arr.push(t);
    }
    while(!st.empty()){
        if(st.top()!=arr.front()) return false;
        st.pop();
        arr.pop();
    }
    return true;
}
int main(void){
    freopen("C-large-1.in","r",stdin);
    freopen("out.txt","w",stdout);
    int tc,casecounter = 1;
    long long arr[39] = {1LL,4LL,9LL,121LL,484LL,10201LL,12321LL,14641LL,40804LL,
    44944LL,1002001LL,1234321LL,4008004LL,100020001LL,102030201LL,104060401LL,121242121LL,123454321LL,
    125686521LL,400080004LL,404090404LL,10000200001LL,10221412201LL,12102420121LL,12345654321LL,40000800004LL,
    1000002000001LL,1002003002001LL,1004006004001LL,1020304030201LL,1022325232201LL,1024348434201LL,
    1210024200121LL,1212225222121LL,1214428244121LL,1232346432321LL,1234567654321LL,4000008000004LL,4004009004004LL};
    vector<long long> v;

    scanf("%d",&tc);
    /*printf("{");
    for(long long i=0;i<10000000;i++){
        long long x = i*i;
        if( palindrome(i) && palindrome(x)){v.push_back(x);printf("%lldLL,",x);}
    }
    printf("}");*/
        /*for(int i=0;i<39;i++){
            printf("%lld\n",arr[i]);
        }*/
        while(tc--){
        long long a, b;
        int total = 0;
        scanf("%lld %lld",&a,&b);
        for(int i=0;i<39;i++) {
            if(a<=arr[i] && arr[i]<=b)total++;
        }
        printf("Case #%d: %d\n",casecounter++,total);

    }

    return 0;
}
