#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fr first
#define sc second

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
    ios::sync_with_stdio(false);

    ifstream fin ("omino.in");
    ofstream fout ("omino.out");

    int t;
    fin >> t;

    int x, r, c;
    for (int test = 0; test < t; test++) {
        fin >> x >> r >> c;

        // CHECK IF ACTUALLY MULTIPLE
        if ((r*c)%x != 0) {
            //CANNOT BE DONE
            fout << "Case #" << (test+1) << ": " << "RICHARD" << "\n";
            continue;
        }

        if (x==1) {
            //CAN BE DONE
            fout << "Case #" << (test+1) << ": " << "GABRIEL" << "\n";
            continue;
        }

        if (x==2) {
            //IF SIDE EVEN THEN CAN BE DONE
            fout << "Case #" << (test+1) << ": " << "GABRIEL" << "\n";
            continue;
        }

        //COMPLETE
        if (x == 3) {
            //R CAN CHOOSE 1 BY 3, BUT THAT IS ALWAYS POSSIBLE
            //R CAN CHOOSE L SHAPED 3.
            if ((r==1) || (c==1)) {
                //NOT DONE
                fout << "Case #" << (test+1) << ": " << "RICHARD" << "\n";
                continue;
            } else {
                //CAN DONE
                fout << "Case #" << (test+1) << ": " << "GABRIEL" << "\n";
                continue;
            }
        }

        if (x==4) {
            if ((r==1) || (c==1)) {
                //NOT DONE
                fout << "Case #" << (test+1) << ": " << "RICHARD" << "\n";
                continue;
            }
            if ((r==2) && (c==2)) {
                //NOT DONE
                fout << "Case #" << (test+1) << ": " << "RICHARD" << "\n";
                continue;
            }
            if ((r==2) && (c==4)) {
                //NOT DONE, CHOOSE WIGGLE
                fout << "Case #" << (test+1) << ": " << "RICHARD" << "\n";
                continue;
            }
            if ((r==4) && (c==2)) {
                //NOT DONE, CHOOSE WIGGLE
                fout << "Case #" << (test+1) << ": " << "RICHARD" << "\n";
                continue;
            }
            if ((r==3) || (c==3)) {
                //MUST BE 3 BY 4, CAN DONE
                fout << "Case #" << (test+1) << ": " << "GABRIEL" << "\n";
                continue;
            }
            //ONLY 4 BY 4 LEFT
            fout << "Case #" << (test+1) << ": " << "GABRIEL" << "\n";
            continue;
        }

        if (x >= 7) {
            //RICHARD CHOOSE ONE WITH HOLE
            fout << "Case #" << (test+1) << ": " << "RICHARD" << "\n";
            continue;
        }

    }

    return 0;
}
