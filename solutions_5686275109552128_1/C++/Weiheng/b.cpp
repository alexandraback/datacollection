#include <iostream>
using namespace std;

int main()
{
    int n;
    int t = 1, i, j, k, ans;
    int num[1001];
    int maxl;
    cin>>n;
    while(t<=n) {
        cin>>k;
        maxl = 0;
        for (i=0; i<k; i++) {
            cin>>num[i];
            if (maxl < num[i])
                maxl = num[i];
        }
        ans = 0x7fffffff;
        int tmp;
        for (i=1; i<=maxl; i++) {
            tmp = i;
            for (j=0; j<k; j++) {
                tmp += num[j]/i;
                if (num[j]%i!=0)
                    tmp+=1;
                tmp -= 1;
            }
            if (ans > tmp)
                ans = tmp;
        }
        cout<<"Case #"<<t<<": "<<ans<<endl;
        t++;
    }

    return 0;
}
