#include<cstdio>
#include<cstring>
#include<deque>
using namespace std;

const int MAX = 1000 + 10;
char arr[MAX];
deque<char> ans;

int main(){
    int TN;
    scanf("%d ", &TN);
    for(int casen = 1 ; casen <= TN ; casen++){
        printf("Case #%d: ", casen);
        gets(arr);
        int len = strlen(arr);
        ans.push_front(arr[0]);
        for(int i = 1 ; i < len ; i++){
            if(arr[i] >= ans.front()) ans.push_front(arr[i]);
            else ans.push_back(arr[i]);
        }
        while(!ans.empty()){
            putchar(ans.front());
            ans.pop_front();
        }
        puts("");
    }
    return 0;
}
