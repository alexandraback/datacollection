#include <iostream>
#include <vector>
#include <set>

using namespace std;

set < unsigned long long int> squares;
bool isPal(unsigned long long int n) {
    unsigned long long int n2 = n;
    unsigned long long int r=0;
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

    //cout << sizeof(unsigned long long int) << endl;

    for (unsigned long long int i=1; i<10000001; i++) {
        if (isPal(i) && isPal(i*i)) {
            squares.insert(i*i);
            //cout << i*i << endl;
        }
    }

    for (int c=0; c<T; c++) {
        unsigned long long int A,B;
        cin >> A >> B;
        int ans=0;
        for (set<unsigned long long int>::iterator it = squares.begin(); it!=squares.end(); it++ ) {
            if (*it >=A && *it <= B) {
                ans++;
                //cout << *it << endl;
            }
        }

        cout << "Case #"<< c+1<<": "<<ans<<endl;
    }

    return 0;
}

