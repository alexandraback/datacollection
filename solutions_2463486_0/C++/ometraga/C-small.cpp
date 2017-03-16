#include <iostream>
#include <string>
using namespace std;
bool isFS[1001];

void init()
{
    memset(isFS, 0, sizeof(isFS));
    int arr[5] = {1, 4, 9, 121, 484};
    for(int i=0; i<5; i++) isFS[arr[i]] = 1;
}

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    init();
    int T;
    cin >> T;
    for(int t=1; t<=T; t++)
    {
        int A, B;
        cin >> A >> B;

        int count = 0;
        for(int i=A; i<=B; i++) count += isFS[i];
        cout << "Case #" << t << ": " << count << endl;
    }
}
