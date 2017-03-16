#include <iostream>
#include <map>

using namespace std;

int main()
{
    int T, N;
    cin >> T;
    map<int, int> m;
    int t;
    for(int c = 1; c <= T; c++){
        m.clear();
        cin >> N;
        for(int i=0; i<2*N - 1; i++){
            for(int j=0; j<N; j++){
                cin >> t;
                auto it = m.find(t);
                if(it == m.end())
                    m[t] = 1;
                else
                    it->second++;
            }
        }
        int index = 0;
        cout << "Case #" << c << ":";
        for(auto it=m.begin(); it!=m.end(); it++){
            if(it->second & 1){
                ++index;
                cout << " " << it->first;
                if(index == N)
                    break;
            }
        }
        cout << endl;
    }
    return 0;
}
