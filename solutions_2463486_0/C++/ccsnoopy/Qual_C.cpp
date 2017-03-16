#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
bool palindrome(int x){
    stack<int> st;
    queue<int> arr;
    while(x){
        int t = x%10;
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
    freopen("C-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int tc,casecounter = 1;
    int arr[1010];
    memset(arr,0,sizeof arr);
    scanf("%d",&tc);
    for(int i=0;i<32;i++){
        int x = i*i;
        if(palindrome(x) && palindrome(i))arr[x] = 1;
    }
    while(tc--){
        int a, b;
        int total = 0;
        scanf("%d %d",&a,&b);
        for(int i=a;i<=b;i++) if(arr[i] == 1){total++;}
        printf("Case #%d: %d\n",casecounter++,total);

    }

    return 0;
}
