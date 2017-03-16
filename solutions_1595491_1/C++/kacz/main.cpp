#include <QtCore/QCoreApplication>
#include <cmath>
#include <iostream>

#define ABS(x) ((x<0) ? (-(x)) : (x))
using namespace std;

int main(int argc, char *argv[])
{
    int cases;
    cin >> cases;
    for(int i = 0; i<cases;++i)
    {
        int n, s, p;
        cin >> n >> s >> p;
        int result = 0;

        for(int i = 0; i < n; ++i){
            int g;
            cin >> g;

            int avr = g/3;
            int mod = g%3;
            if( avr >= p) {
                result++;
                continue;
            }

            if(avr < p-2) {
                continue;
            }

            if(avr == p-2){
                if(mod == 2 && s > 0) {
                    --s;
                    ++result;
                    continue;
                }
            }
            if(avr == p-1){
                if(mod == 0) {
                    if(avr>0 && s>0) {
                        --s;
                        ++result;
                    }
                }else{
                    result++;
                }
                continue;
            }
        }
        cout << "Case #" << i+1 << ": ";
        cout << result << endl;
    }
    return 0;
}
