#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int coden, t;
    cin >> t;
    // define vars
    unsigned long a;
    int n;
    unsigned long mote[105];
    int i;
    int delnum;
    int remain; //number of mote remained after deleting
    unsigned long curmote;
    int addnum;
    int minnum;

    for (coden = 1; coden <= t; coden++) {
        cin >> a; // first mote
        cin >> n; // number of motes in sequence
        for (i = 0; i < n; i++) {
            cin >> mote[i];
        }
        sort (mote, mote+n);
        /*
        for (i = 0; i < n; i++) {
            cout << mote[i] << " ";
        }
        cout << endl;
        */

        if (a > 1) {
            minnum = n;
            for (delnum = 0; delnum < n; delnum++) {
                remain = n - delnum;
                addnum = 0;
                curmote = a;

                // have a try
                for (int i = 0; i < remain; i++) {
                    while (curmote <= mote[i]) {
                        //cout << "curmote = " << curmote << ", mote[" << i << "]=" << mote[i] << endl;
                        // add one mote
                        curmote *= 2;
                        curmote -= 1;
                        ++addnum;
                    }
                    curmote += mote[i];
                }

                // find the minimum
                if (addnum + delnum < minnum) {
                    //cout << "minnum = " << minnum;
                    //cout << ";addnum = " << addnum;
                    //cout << ";delnum = " << delnum;
                    minnum = addnum + delnum;
                }
            }
        } else {
            minnum = n;
        }

        // output result
        cout << "Case #" << coden << ": ";
        cout << minnum << endl;
    }
    return 0;
}

