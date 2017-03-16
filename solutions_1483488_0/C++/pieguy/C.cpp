#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
using namespace std;

int main(){
    int T, A, B;
    scanf("%d", &T);
    for(int c=1; c<=T; c++){
        scanf("%d %d", &A, &B);
        map<int, int> m;
        for(int i=A; i<=B; i++)
        {
            char buf[10];
            sprintf(buf, "%d", i);
            int len=strlen(buf);
            int x=strtol(buf, NULL, 16);
            int l=x;
            for(int j=0; j<len; j++){
                l=min(l, x);
                x=(x>>4)|((x&15)<<(4*(len-1)));
            }
            m[l]++;
        }
        int res=0;
        for(map<int, int>::iterator it=m.begin(); it!=m.end(); it++){
            res+=it->second*(it->second-1)/2;
        }
        printf("Case #%d: %d\n", c, res);
    }
}
