#include <iostream>
#include <stdlib.h>

#define MAX 200000

using namespace std;

int main(int argc, char *argv[])
{
    int T;
    cin >> T;

    long double p[MAX];
    long double probability[MAX]; // Probability that the first [index] elements are correct.
    for(int counter = 1; counter <= T; counter++)
    {
        int A, B;
        cin >> A >> B;

        for(int c = 0; c < A; c++)
        {
            cin >> p[c];
        }

        probability[0] = 1;
        for(int c = 1; c <= A; c++)
        {
            probability[c] = probability[c-1] * p[c-1];
        }

        // Default: Give up and retype.
        long double ans = B + 2;

        // Finish typing and hit enter.
        ans = min(ans, probability[A] * (B - A + 1) + (1 - probability[A]) * (2 * B - A + 2));

        for(int c = 0; c < A; c++)
        {
            // Delete until c characters remain and retype.
            ans = min(ans, probability[c] * (A + B - 2 * c + 1) + (1 - probability[c]) * (A + 2 * B - 2 * c + 2));
        }

        cout << "Case #" << counter << ": " << ans << "\n";
    }
}
