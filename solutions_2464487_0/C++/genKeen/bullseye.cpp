#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int numTests;
    cin >> numTests;
    for(int test = 0; test < numTests; ++test)
    {
        unsigned long long radius, mlPaint, numRings = 0;
        cin >> radius >> mlPaint;

        ++radius;

        while(true) {
            int less = radius-1;
            int paintUsed = radius*radius-less*less;

            if (paintUsed > mlPaint) break;

            mlPaint -= paintUsed;
            ++numRings;
            radius += 2;
        }

        cout << "Case #" << test+1 << ": " << numRings << endl;
    }
}
