#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

#define MAX 1000010

char input[MAX];
vector<int> st, en;

bool isConsonant(char c){
    if (c=='a' or c=='e' or c=='i' or c=='o' or c=='u') return false;
    return true;
}

long long Solve(int n){
    int i, j;
    long long l = strlen(input);
    int size, prev;
    long long ans = 0LL;
    queue<int> q;
    i = 0;
    size = 0;
    st.clear();
    en.clear();
    
    if (n == 1){
        for (i=0; i<l; i++){
            if (not isConsonant(input[i]))
                continue;
            st.push_back(i);
            en.push_back(i);
        }
    }
    else{
        while (i<l){
            if (not isConsonant(input[i])){
                size = 0;
                while (not q.empty())
                    q.pop();
            }
            else if (size<n-1){
                q.push(i);
                size++;
            }
            else{
                st.push_back(q.front());
                q.pop();
                q.push(i);
                en.push_back(i);
            }
            i++;
        }
    }
    /*
    printf("patterns\n");
    for (i=0; i<st.size(); i++)
        printf("%d--%d\n", st[i], en[i]);
    */
    prev = 0;
    for (i=0; i<st.size(); i++){
        ans += (st[i]-prev+1LL)*(l-en[i]);
        prev = st[i]+1;
    }
    return ans;
}

int main(){
    int T, n;
    scanf("%d", &T);
    for (int t=1; t<=T; t++){
        scanf("%s %d", input, &n);
        printf("Case #%d: %lld\n", t, Solve(n));
    }
    return 0;
}

