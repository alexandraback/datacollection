#include <iostream>
#include <set>

using namespace std;

int main(int argc, char **argv) {
    int t,T, i,j;
    int A,N,m;
    int counts[100];
    
    cin >> T;
    
    for( t = 1; t <= T; t++ ) {
        cin >> A >> N;
        
        multiset<int> motes;
        for( i = 0; i < N; i++ ) {
            cin >> m;
            motes.insert(m);
        }
        
        int count = 0;
        
        if( A > 1 ) {
            i = 0;
            while(!motes.empty() ) {
                m = *motes.begin();
                motes.erase(motes.begin());
                
                while( A <= m ) {
                    A = A+A-1;
                    count++;
                }
                A += m;
                
                counts[i++] = count;;
            }
            count = N;
            for( i = 0; i < N;i++ ) {
                count = min(count, counts[i] + N-i-1);
            }
            cout << "Case #"<<t<<": "<<min(count,N)<<"\n";
        }else {
            cout << "Case #"<<t<<": "<<N<<"\n";
        }
        
    }
    
    return 0;
}
