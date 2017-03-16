#include <iostream>

using namespace std;

int freez[2501];
int data[100][50];
int ty[100];
int res[100];

int main()
{
    int t, n;
    cin >> t;
    for(int v = 0; v < t; v++){
        cin >> n;
        for(int i = 0; i < 2501; i++){
            freez[i] = 0;
        }
        for(int i = 0; i < 2*n - 1; i++){
            for(int j = 0; j < n; j++)
            {
                cin >> data[i][j];
                freez[data[i][j]]++;
            }
            ty[i] = 0;
        }
        cout << "Case #" << v + 1 << ": ";
        for(int i = 0; i < 2501; i++)
            if(freez[i] % 2 == 1)
                cout << i << " ";
        cout << endl;
    }
    return 0;
}
