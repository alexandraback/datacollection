#include <iostream>

using namespace std;

int main()
{
    size_t a, T;
    cin >> T;
    for (a=0;a<T;++a) {
        size_t N, S, p, i, y;
        y = 0;
        cin >> N >> S >> p;
        //vector<size_t> t(N, 0);
        for (i=0;i<N;++i) {
            //cin >> t[i];
            size_t t;
            cin >> t;
            size_t q = t / 3;
            size_t r = t % 3;
            if(r==2) {
                if(p==0||p==1) {++y;/*continue*/;}
                else {
                    if(q>=p-1){++y;}
                    else if(q==p-2) {if(S>0){++y;--S;}}
                }
            }
            else if(r==1) {
                if(p==0) {++y;/*continue*/;}
                else {
                    if(q>=p-1){++y;}
                }
            }
            else { // r==0
                if(p==0) {++y;/*continue*/;}
                else if(q>0){
                    if(q>=p){++y;}
                    else if((q==p-1)&&(q>0)) {if(S>0){++y;--S;}}
                }
            }
        }
        //vector<size_t> r(3, 0);
        cout << "Case #" << a+1 << ": " << y <<endl;
    }
    return 0;
}
