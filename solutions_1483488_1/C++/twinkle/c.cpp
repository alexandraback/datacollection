#include <iostream>
#include <map>
using namespace std;
int n,ten[11],A,B;
string str;
map <string,bool> used;
int getlen(int x){
    int tmp = x;
    int len = 0;
    while(tmp > 0){
        tmp /= 10;
        len ++;
    }
    return len;
}
int main(){
   // freopen("c.in","r",stdin);
    //freopen("c.out","w",stdout);
    cin >> n;
    ten[0] = 1;
    for(int i = 1; i <= 8; i ++){
        ten[i] = ten[i-1] * 10;
    }
    for(int Case = 1; Case <= n; Case ++){
        int ans = 0;
        cin >>  A >> B;
        used.clear();
        int len = getlen(A), ta, tb ;
        for(int i = A; i <= B; i ++){
            ta = i;
            for(int j = 1; j < len; j ++){
                tb = ta / ten[j] + (ta % ten[j]) * ten[len-j];
               // cout << ta << ' '<<tb<<endl;
                if(tb > ta && tb <= B){
                    int tmp = ta;
                    str = "";
                    while(tmp > 0){
                        str = str + char((tmp%10+'0'));
                        tmp/=10;
                    }
                    tmp = tb;
                    while(tmp > 0){
                        str = str + char((tmp%10+'0'));
                        tmp /= 10;
                    }

                    if(used[str] == 1)continue;
                    used[str] = 1;
                    ans ++;
                }
            }

        }
        cout <<"Case #"<<Case<<": "<< ans << endl;
    }
    return 0;
}
