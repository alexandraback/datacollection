#include<cstdio>
#include<cstring>
#include<deque>
#include<algorithm>
using namespace std;
int tc,len;
char ipt[1005];

deque<int>dq;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int i,j;
    scanf("%d",&tc);
    for(j=1;j<=tc;j++) {
        scanf("%s",&ipt);
        len = strlen(ipt);
        dq.push_back(ipt[0]);
        for(i=1;i<len;i++) {
            if(dq.front()<=ipt[i]) {
                dq.push_front(ipt[i]);
            }
            else dq.push_back(ipt[i]);
        }
        printf("Case #%d: ",j);
        for(i=0;i<len;i++) {
            printf("%c",dq.front());
            dq.pop_front();
            ipt[i] = 0;
        }
        puts("");
    }
}
