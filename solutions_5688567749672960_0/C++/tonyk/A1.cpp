#include <iostream>

using namespace std;

int digits(long long x) {
    int r = 0;
    while (x > 0) {
        x = x / 10;
        r++;
    }
    return r;
}
    
int first_digit(long long x) {
    while (x > 9) {
        x /= 10;
    }
    return (int)x;
}
    
int last_digit(long long x) {
    int r;
    r = (int)(x % 10);
    if (r < 0) r += 10;
    return r;
}

long long reverse(long long x) {
    long long r;
    r = 0;
    while (x > 0) {
        r = 10*r + last_digit(x);
        x /= 10;
    }
    return r;
}

int main() {
    long long t, i, n, c, r, tmp;
    int dn, j, k, fd, ld;
    
    cin >> t;
    for (i = 0; i < t; i++) {
        cin >> n;
        dn = digits(n);
        if (dn == 1) {
            r = n;
        } else {
            r = 10;
            for (j = 3; j <= dn; j++) {
                r += 10;
                tmp = 0;
                for (k = 0; k < j-2; k++)
                    tmp = tmp*10+9;
                r += tmp;
            }
            c = 1;
            for (j = 0; j < dn-1; j++)
                c *= 10;
            ld = last_digit(n);
            fd = first_digit(n);
            //cout << fd << " " << ld <<  endl;
            //cout << c <<  " " << r << endl;
            if (ld == 0) {
                if (fd > 2) {
                    c += fd - 1;
                    c = reverse(c);
                    r += fd;
                }
                //cout << c <<  " " << r << endl;
            } else {
                if (fd > 1) {
                    c += fd;
                    c = reverse(c);
                    r += fd + 1;
                }
                //cout << c <<  " " << r << endl;
            }
            r += n-c;
        }
        
        cout << "Case #" << i+1 << ": " << r << endl;
    }

    return 0;
}
