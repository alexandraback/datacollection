#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        int D;
        cin >> D;

        vector<int> diners(D);
        for(int i = 0; i < D; ++i)
            cin >> diners[i];
       
       int best = (1<<30); 
        for(int threshold = 1; threshold <= 1000; ++threshold) {
            int largest = 0;
            int splits = 0;

            for(int i = 0; i < diners.size(); ++i) {
                int div = diners[i]/threshold + (diners[i]%threshold != 0);
                largest = max(largest,
                    diners[i]/div + (diners[i]%div != 0));
                splits += div-1;
            }
            
            best = min(best, splits+largest);
        }

        cout << "Case #" << t << ": " << best << endl;
    }

    return 0;
}
