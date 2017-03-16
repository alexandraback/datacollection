#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        int Smax, num = 0, need = 0;
        string shystr;
        cin >> Smax >> shystr;
        for (int i = 0; i <= Smax; i++) {
            if (num < i) {
                need++; num++;
            }
            num += (shystr[i] - '0');
        }
        cout << "Case #" << c << ": " << need << endl;
    }
    return 0;
}
