#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cstdint>
using namespace std;
int count[10000001];
vector<bool> palin(10000001);
int main()
{
    for (int64_t i=1;i<=10000000;i++) {
        string istr = to_string(i), i2str = to_string(i*i);
        if (i==atoll(string(istr.rbegin(),istr.rend()).c_str())&&i*i==atoll(string(i2str.rbegin(),i2str.rend()).c_str())) count[i] = palin[i] = 1;
        count[i] += count[i-1];
    }
    int cases;
    cin >> cases;
    for (int t=1;t<=cases;t++) {
        int64_t a,b;
        cin >> a >> b;
        int x = int(ceil(sqrt((long double)a)));
        //cout<<count[int(sqrt((long double)b))]<<' '<<count[x]<<endl;
        cout<<"Case #"<<t<<": "<<(count[int(sqrt((long double)b))]-count[x]+palin[x])<<endl;
    }
    return 0;
}
