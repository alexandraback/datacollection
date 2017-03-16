#include <iostream>


int main(void)
{
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; i++) {
        int k, c, s;
        std::cin >> k >> c >> s;
        std::cout << "Case #" << i << ":";
        // firstly, renumber all tiles from 0.
        // then let f(a_1, ..., a_c) = sum [i = 1 .. c] a_i * k^(i - 1).
        // if 0 <= f(a_1, ..., a_c) < k^c and f(a_1, ..., a_c)+1-th tile
        // is L, then all of the a_i-th tiles of the original puzzle were
        // also L. so we find out that c tiles are L in one go.
        if (s * c < k) {
            std::cout << " IMPOSSIBLE" << std::endl;
            continue;
        }

        long long powersOfK[c];
        powersOfK[0] = 1;
        for (int j = 1; j < c; j++)
            powersOfK[j] = powersOfK[j - 1] * k;

        for (int j = 0; j < k; j += c) {
            long long index = 0;
            //                            if j + c > k
            //                              |-------|
            // a_1, ..., a_c = j, j+1, ..., 0, ..., 0
            for (int q = 0; q < c; q++)
                index += powersOfK[q] * (j + q >= k ? 0 : j + q);
            // and convert back to 1-based indexing
            std::cout << " " << (index + 1);
        }
        std::cout << std::endl;
    }
    return 0;
}