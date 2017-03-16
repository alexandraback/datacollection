#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;
const int N=1005;
char str[N];
deque<char> q;
bool check() {
    for(int i=0; i<q.size()-1; ++i) {
        if(q[i]==q[i+1])
            continue;
        return q[i]<q[i+1];
    }
    return true;
}
int main() {
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cas=1; cas<=t; ++cas) {
        scanf("%s",&str);
        q.push_back(str[0]);
        for(int i=1,len=strlen(str); i<len; ++i) {
            if(str[i]<q.front()||(str[i]==q.front()&&check()))
                q.push_back(str[i]);
            else
                q.push_front(str[i]);
        }
        printf("Case #%d: ",cas);
        for(; !q.empty(); q.pop_front())
            putchar(q.front());
        putchar('\n');
    }
    return 0;
}
