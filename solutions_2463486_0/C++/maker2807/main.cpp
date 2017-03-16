#include <iostream>
#include <vector>

using namespace std;

bool isPal(int n) {
    int n2 = n;
    int r=0;
    while (n>0) {
        r=r*10+n%10;
        n/=10;
    }
    return n2==r;
}

int main()
{
    int T;
    cin >> T;
    vector <bool> isSquare (1500,false);
    for (int i=1; i<33; i++) {
        if (isPal(i)) isSquare[i*i]=true;
    }

    for (int c=0; c<T; c++) {
        int A,B;
        cin >> A >> B;
        int ans=0;
        for (int i=A; i<=B; i++) {
            if (isSquare[i] && isPal(i)) {
                ans++;
                //cout << i << endl;
            }
        }

        cout << "Case #"<< c+1<<": "<<ans<<endl;
    }
    return 0;
}

