#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    #if 1
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("output1.txt", "w+", stdout);
    #endif

    static bool is_consonant[256];
    for (int c = 0; c < 256; ++c)
    {
        is_consonant[c] = (c > 'a' and c <= 'z' and c != 'e' and
        c != 'i' and c != 'o' and c != 'u');
    }

    int total;
    cin >> total;
    for (int current = 0; current < total; ++current)
    {
        cout << "Case #" << current+1 << ": ";

        string word;
        int n;

        cin >> word >> n;

        int score = 0;
        int size = word.size();
        for (int i = 0; i < size; ++i)
        {
            int c = 0;
            int j;
            for (j = i; j < size; ++j)
            {
                if (is_consonant[word[j]])
                {
                    ++c;
                    if (c == n)
                    {
                        score += size-j;
                        break;
                    }
                }
                else
                {
                    c = 0;
                }
            }
            if (j == size)
                break;
        }

        cout << score << endl;

    }
}
