#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>

using namespace std;
int a[22];
int n;
map<int,int> st;
int main()
{
//    freopen("in","r",stdin);
//    freopen("out","w",stdout);
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C.out","w",stdout);
    int t,cas;
    
    int i;
    scanf("%d",&t);cas = 0;
    while(t--)
    {
        cas++;
        scanf("%d",&n);
        for(i = 0; i < n; i++)
            scanf("%d",&a[i]);
        st.clear();
        int tmp;
//        int x,y;
        for(i = 0; i < (1<<n); i++){
            tmp = 0;
            for(int j = 0; j < n; j++){
                if(i&(1<<j)) tmp += a[j];
            }
            if(st.find(tmp) != st.end()){
                break; 
            }
            else st[tmp] = i;
        }
        printf("Case #%d:\n",cas);
        if(i == (1<<n)){
            puts("Impossible");
        }
        else{
            for(int j = 0; j < n; j++){
                if(i&(1<<j)){
                    i ^= 1<<j;
                    printf("%d",a[j]);
                    if(i) printf(" ");
                    else printf("\n");
                }
            }
            i = st[tmp];
            for(int j = 0; j < n; j++){
                if(i&(1<<j)){
                    i ^= 1<<j;
                    printf("%d",a[j]);
                    if(i) printf(" ");
                    else printf("\n");
                }
            }
        }
    }

}
