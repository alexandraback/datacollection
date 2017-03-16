#include <iostream>
#include <fstream>
#include <cmath>
#include <map>
using namespace std;

int calc(double n, double x, double k){
    return ceil(n / x) + k * (x - 1);
}

int main()
{
    ifstream fin("B-small-attempt2.in");
    ofstream fout("fout.out");
    int T;
    fin >> T;
    for(int CASE = 0; CASE < T; ++CASE){
        int d;
        fin >> d;
        int p[1000];
        map<int, int> Map;
        for(int i = 0; i < d; ++i){
            fin >> p[i];
            Map[p[i]]++;
        }
        int ans = -1;
        int total;
        for(int i = round(sqrt(double(Map.rbegin()->first) / double(Map.rbegin()->second))); i >= 1; --i){
            int bar = ceil(double(Map.rbegin()->first) / double(i));
            total = calc(Map.rbegin()->first, i, Map.rbegin()->second);
            auto iter = Map.rbegin();
            for(++iter; iter != Map.rend(); ++iter){
                int k = 1;
                while(ceil(double(iter->first) / double(k)) > bar){
                    ++k;
                }
                int minn = iter->second * (k - 1);
                for(k = k - 1; k >= 1; --k){
                    int tmp = iter->second * (k - 1) + ceil(double(iter->first) / double(k)) - bar;
                    if(minn >= tmp){
                        minn = tmp;
                        bar = ceil(double(iter->first) / double(k));
                    }
                }
                total += minn;
            }
            if(ans == -1 || ans > total){
                ans = total;
            }
        }
        fout << "Case #" << CASE + 1 << ": " << ans << endl;
    }
    return 0;
}
