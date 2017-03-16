#include <iostream>

using namespace std;

int main()
{
    freopen("A-small-attempt2.in", "r", stdin);
    freopen("A-small-attempt2.out", "w", stdout);

    int T;

    cin >> T;

    for(int i=0; i < T; i++){
        int R,C;
        cin >> R;
        cin >> C;

        int W;
        cin >> W;


        cout << "Case #" << i + 1 << ": ";
        if((C % W) != 0){
            cout << (R * (C/W)) + W << endl;
        }else{
            cout << (R * (C/W)) + W-1 << endl;
        }

    }

    return 0;
}

