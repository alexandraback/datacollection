#include <iostream>
#include <vector>
#include <cstdint>
#include <array>
using namespace std;

void updateUsedDigits(int64_t number, uint32_t& used)
{
    while(number > 0)
    {
        used |= 1 << (number % 10);
        number /= 10;
    }
}

int64_t test()
{
    int64_t n;
    cin >> n;

    if (n == 0) {
        return -1;
    }

    int64_t sum = 0;
    uint32_t used = 0;

    while (used != 1023) // not all digits used
    {
        sum += n;
        updateUsedDigits(sum, used);
    }

    return sum;
}

int main(int argc, char const *argv[])
{
    size_t t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        int64_t result = test();
        cout << "Case #" << i + 1 << ": ";
        if (result == -1)
            cout << "INSOMNIA";
        else
            cout << result;
        cout << endl;
    }
}
