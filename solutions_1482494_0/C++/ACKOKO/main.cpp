#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


typedef struct NODE{
    int num;
    int no;
}NODE;

NODE Node[1010];

int tag;
int N, n, ans, cur;
int a[1010], flag[1010];


bool cmp(NODE aa, NODE bb){
    return aa.num < bb.num;
}


int main()
{
//    freopen("B-small-attempt1.in", "r", stdin);
//    freopen("bsmall.out", "w", stdout);
    scanf("%d", &N);
    for(int T = 1;T <= N;T++){
        for(int i = 0;i < 1010;i++){
            flag[i] = 0;
        }
        scanf("%d", &n);
        for(int i = 0;i < n;i++){
            scanf("%d%d", &a[i], &Node[i].num);
            Node[i].no = i;
        }
        printf("Case #%d: ", T);
        sort(a, a+n);
        sort(Node, Node+n, cmp);
        cur = 0;
        ans = 0;
        tag = 0;
        for(int i = 0;i < n;i++){
            if(cur >= Node[i].num){
                ans++;
                cur += 2;
            }else{
                for(int j = 0;j < n;j++){
                    if(flag[j] == 0&&cur >= a[j]){
                        cur++;
                        ans++;
                        flag[j] = 1;
                        if(cur >= Node[i].num){
                            ans++;
                            cur += 2;
                            break;
                        }
                    }
                }
                if(cur < Node[i].num){
                    tag = 1;
                    break;
                }
            }
        }
        if(tag == 0){
            printf("%d\n", ans);
        }else{
            printf("Too Bad\n");
        }
    }
    return 0;
}
