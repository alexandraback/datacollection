#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    long long int t, T, x, y, ax, ay;
    long long int i, j, k, jumpsn, more;

    cin >> T;

    for( t = 1; t<= T; t++ ) {
        cin >> x >> y;
        ax = x >= 0 ? x : -x;
        ay = y >= 0 ? y : -y;

        for( i = 1; i*(i+1)/2 < ax+ay; i++ );

        more = i*(i+1)/2 - ax-ay;
        if( more % 2 ) {
            i++;
        }
        more = i*(i+1)/2 - ax-ay;
        more /= 2;
        jumpsn = i;

        //cout << jumpsn << " " << more << " ";
        cout << "Case #" << t << ": ";


        if( ax < ay ) {
            for( i = 1; i <= jumpsn; i++ ) {
                if( ax > jumpsn ? (ax == jumpsn + i || i == jumpsn) : ax == i) {
                    if( x > 0 ) {
                        cout << 'E';
                    } else {
                        cout << 'W';
                    }
                } else {
                    if( ((ax > jumpsn && ( ax == jumpsn + more )) || (ax == more)) ? (i == 1 || i == more-1) : (i == more) ) {
                        if( y > 0 ) {
                            cout << 'S';
                        } else {
                            cout << 'N';
                        }
                    } else {
                        if( y > 0 ) {
                            cout << 'N';
                        } else {
                            cout << 'S';
                        }
                    }
                }
            }
        } else {
            for( i = 1; i <= jumpsn; i++ ) {
                if( ay > jumpsn ? (ay == jumpsn + i || i == jumpsn) : ay == i) {
                    if( y > 0 ) {
                        cout << 'N';
                    } else {
                        cout << 'S';
                    }
                } else {
                    if( ((ay > jumpsn && ( ay == jumpsn + more )) || (ay == more)) ? (i == 1 || i == more-1) : (i == more) ) {
                        if( x > 0 ) {
                            cout << 'W';
                        } else {
                            cout << 'E';
                        }
                    } else {
                        if( x > 0 ) {
                            cout << 'E';
                        } else {
                            cout << 'W';
                        }
                    }
                }
            }
        }

        cout << endl;
    }

    return 0;
}
