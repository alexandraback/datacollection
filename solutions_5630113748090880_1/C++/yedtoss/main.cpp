// C++11
#include <iostream>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <cassert>

using namespace std;

int test_small(){

    int T;
    cin>>T;


    for(int c=1; c<=T; c++){

        int N;
        cin>>N;

        vector<vector<int> > l(2*N-1, vector<int>(N, 0));

        vector<int> num_present(2501, 0);

        for(int i=0; i<2*N-1; i++){

            for(int j=0; j<N; j++){

                cin >> l[i][j];

                num_present[l[i][j]]++;
            }

        }

        vector<int> missing;

        for(int i=1; i<2501; i++){

            if(num_present[i]%2 != 0){
                missing.push_back(i);
            }
        }

        assert(N == missing.size());

        sort(missing.begin(), missing.end());
        cout<<"Case #"<<c<<":";

        for(int i=0; i<N; i++){

            cout<<" "<<missing[i];
        }


        cout<<endl;
    }

}

int main()
{
    test_small();
    return 0;
}

