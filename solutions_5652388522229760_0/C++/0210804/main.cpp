#include <cstdio>
using namespace std;

int doCounting(int base){
    int counter = 0;
    bool found[10] = {0};
    int ans = 0;
    while(counter!=10){
        ans += base;
        int tmp = ans;
        while(tmp){
            if(!found[tmp%10]){
                found[tmp%10] = 1;
                counter++;
            }
            tmp /= 10;
        }
    }
    return ans;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int base;
        scanf("%d",&base);
        if(base==0) printf("Case #%d: INSOMNIA\n",i+1);
        else printf("Case #%d: %d\n",i+1,doCounting(base));
    }
    return 0;
}
