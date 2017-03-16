#include <iostream>


int main(void)
{
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; i++) {
        int n;
        int seen = 0;
        std::cin >> n;
        int k = n;

        if (k) while (1) {
            int q = k;
            while (q) {
                seen |= 1 << (q % 10);
                q /= 10;
                if (seen == 0x3FF) {
                    std::cout << "Case #" << i << ": " << k << std::endl;
                    goto end;
                }
            }
            k += n;
        }
        std::cout << "Case #" << i << ": INSOMNIA" << std::endl;
    end:
        (void) 0;
    }
    return 0;
}
