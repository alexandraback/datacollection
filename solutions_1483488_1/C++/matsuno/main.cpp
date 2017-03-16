#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <set>

using namespace std;

set<pair<size_t, size_t> > nmpairs;

size_t D;
size_t K[9];
const size_t R[9] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};

void
get_digits(size_t A)
{
    size_t d = 0;
    do {
        K[++d] = A % 10;
        A = A / 10;
    } while(A>0);
}

size_t
compute_ndigits(size_t A)
{
    size_t d = 0;
    do {
        //K[++d] = A % 10;
        A = A / 10;
        ++d;
    } while(A>0);
    return d;
}

//size_t
void
count_npairs(const size_t &n, const size_t &A, const size_t &B)
{
    size_t d;
    //size_t c;
    //c = 0;
    get_digits(n);
    for (d=1;d<D;++d) {
        if(K[d]>0) {
            size_t q = n / R[d];
            size_t r = n % R[d];
            size_t m = r * (R[D]/R[d]) + q;
            //if(D==compute_ndigits(m)) {
            if((A<=n)&&(n<m)&&(m<=B)) {
                nmpairs.insert(pair<size_t, size_t>(n,m));
                //++c;
            }
            //}
        }
    }
    //return c;
}

int main()
{
    size_t a, T;
    cin >> T;
    for (a=0;a<T;++a) {
        size_t A, B, y, n;
        cin >> A >> B;
        y = 0;
        D = compute_ndigits(A);
        if (D > 1) {

            for (n=A;n<B;++n) {
                //y += count_npairs(n,A,B);
                count_npairs(n,A,B);
            }
            y = nmpairs.size();
        }
        cout << "Case #" << a+1 << ": " << y <<endl;
        nmpairs.clear();
    }
    return 0;
}
