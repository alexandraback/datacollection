#include <iostream>

using namespace std;

int data[1000];
int freez[1000];
int lenz[1000];

int cal(int start, int next, int lenz){
    if(freez[next]!=-1)
        return 0;
    freez[next] = start;
    if(next == start)
        return lenz;
    int res = cal(start, data[next], lenz + 1);
    if(res == 0){
        freez[next] = -1;
    }
    return res;
}

int cal2(int start, int len, int n){
    int res = len;
    for(int i = 0; i < n; i++)
        if(data[i] == start && freez[i] == -1)
            res = max(res, cal2(i, len + 1, n));
    return res;
}

int main()
{
    int t, n;
    cin >> t;
    for(int v = 0; v < t; v++){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> data[i];
            data[i]--;
            freez[i] = -1;
            lenz[i] = 0;
        }
        int res = 0;
        for(int i = 0; i < n; i++)
            if(freez[i] == -1){
                cal(i, data[i], 1);
            }
        int max_sida = 0;
        for(int i = 0; i < n ; i++)
            if(freez[i] == i){
                int x = i; int countz = 0;
                for(int j = 0; j < n; j++)
                    if(freez[j] == x){
                        countz++;
                    }
                if(countz <= 2){
                    int max1 = 0; int max2 = 0;
                    for(int j = 0; j < n; j++){
                        if(freez[j] == x){
                            int zz = cal2(j, 0, n);
                            if(max2 < zz){
                                if(max1 < zz){
                                    max2 = max1; max1 = zz;
                                }else{
                                    max2 = zz;
                                }
                            }
                        }
                    }
                    countz = countz + max1 + max2;
                    max_sida += countz;
                }
                res = max(res, countz);
            }
        res = max(res, max_sida);
        cout << "Case #" << v + 1 << ": " <<res << endl;
    }
    return 0;
}
