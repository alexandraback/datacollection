#include <cstdio>
int data[1010];
int s;

int main()
{
    freopen("D:\\input","r",stdin);
    freopen("D:\\output","w",stdout);
    int t;
    scanf("%d",&t);
    for(int _=0;_<t;++_){
        scanf("%d",&s);
        int i;
        int needed=0;
        for(i=0;i<=s;++i) scanf("%1d",data+i);
        int cursum=0;
        for(i=0;i<=s;++i){
            cursum+=data[i];
            if(cursum==0) ++needed;
            else --cursum;
        }
        printf("Case #%d: %d\n",_+1,needed);
    }
    return 0;
}
