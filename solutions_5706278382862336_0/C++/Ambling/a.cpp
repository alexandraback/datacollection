#include <iostream>

using namespace std;

typedef long long lint;

int main(int argc, char const *argv[])
{
    int T;
    cin>>T;

    for (int tt = 0; tt < T; ++tt)
    {
        lint a, b;
        char t;
        
        cin >> a >> t >> b;

        lint rb = b;
        int cnt = 0;
        int find = 0;
        while (rb % 2 == 0) 
        {
            if (a < rb)
            {
                cnt ++;
            }
            rb /= 2;
            // cout << rb << endl;
            
        }
        if (rb != 1 && a % rb != 0)
        {
            find = 1;
        }


        cout << "Case #" << tt+1 << ": " ;//<< a << " " << b << endl;
        switch (find)
        {
            case 0:
                cout << cnt << endl;
                break;
            case 1:
                cout << "impossible" << endl;
                break;
            default:
                cout << "impossible" << endl;
                break;
        }
    }
    return 0;
}