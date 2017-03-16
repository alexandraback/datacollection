#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    long long cases = 0;
    cin >> cases;
    for(long long c=0;c<cases;c++){
        long long plates = 0;
        cin >> plates;
        vector<long long> vs;
        for(long long i=0;i<plates;i++){
            long long temp;
            cin >> temp;
            vs.push_back(temp);
        }
        sort(vs.begin(),vs.end());
        long long best = 2000000;
        for(long long i=1;i<vs.back()+2;i++){
            long long penal = 0;
            for(long long j=0;j<plates;j++){
                long long parts = vs[j]/i;
                if(vs[j] % i != 0) parts ++;
                penal += parts-1;
            }
            best = min(best, i+penal);
        }
        cout << "Case #" << c+1 << ": " << best << endl;
    }
}