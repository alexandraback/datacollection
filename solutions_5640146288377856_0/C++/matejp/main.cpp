#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int T, R, C, W;
    ifstream input ("input.in");
    if (input.is_open())
    {
        ofstream output ("output.out");
        input >> T;
        for (int i = 0; i < T; i++)
        {
            int result = 0;
            input >> R >> C >> W;
            if (C != W)
            {
                if (C % W != 0)
                    result = (R * (C / W)) + W;
                else
                   result = (R * (C / W)) + (W-1);
            }
            else
                result = R + W - 1;
            output << "Case #" << i + 1 << ": " << result << endl;
        }
    input.close();
    output.close();
    }
    return 0;
}

