#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

char number[2001];
int freq[27];
int digits[10];

void compute_freq()
{
    int l = strlen(number);
    int i;
    for (i = 0; i < 27; i++)
        freq[i] = 0;
    for (i = 0; i < l; i++)
        freq[number[i] - 'A']++;
}

void compute_digits()
{
    int i;
    for (i = 0; i < 10; i++)
        digits[i] = 0;
    //ZERO
    freq['E' - 'A'] -= freq['Z' - 'A'];
    freq['R' - 'A'] -= freq['Z' - 'A'];
    freq['O' - 'A'] -= freq['Z' - 'A'];
    digits[0] = freq['Z' - 'A'];
    freq['Z' - 'A'] = 0;

    //SIX
    freq['S' - 'A'] -= freq['X' - 'A'];
    freq['I' - 'A'] -= freq['X' - 'A'];
    digits[6] = freq['X' - 'A'];
    freq['X' - 'A'] = 0;

    //SEVEN
    freq['E' - 'A'] -= 2 * freq['S' - 'A'];
    freq['V' - 'A'] -= freq['S' - 'A'];
    freq['N' - 'A'] -= freq['S' - 'A'];
    digits[7] = freq['S' - 'A'];
    freq['S' - 'A'] = 0;

    //FIVE
    freq['F' - 'A'] -= freq['V' - 'A'];
    freq['I' - 'A'] -= freq['V' - 'A'];
    freq['E' - 'A'] -= freq['V' - 'A'];
    digits[5] = freq['V' - 'A'];
    freq['V' - 'A'] = 0;

    //TWO
    freq['T' - 'A'] -= freq['W' - 'A'];
    freq['O' - 'A'] -= freq['W' - 'A'];
    digits[2] = freq['W' - 'A'];
    freq['W' - 'A'] = 0;

    //FOUR
    freq['F' - 'A'] -= freq['U' - 'A'];
    freq['O' - 'A'] -= freq['U' - 'A'];
    freq['R' - 'A'] -= freq['U' - 'A'];
    digits[4] = freq['U' - 'A'];
    freq['U' - 'A'] = 0;

    //ONE
    freq['N' - 'A'] -= freq['O' - 'A'];
    freq['E' - 'A'] -= freq['O' - 'A'];
    digits[1] = freq['O' - 'A'];
    freq['O' - 'A'] = 0;

    //NINE
    freq['I' - 'A'] -= freq['N' - 'A'] / 2;
    freq['E' - 'A'] -= freq['N' - 'A'] / 2;
    digits[9] = freq['N' - 'A'] / 2;
    freq['N' - 'A'] = 0;

    //EIGHT
    freq['E' - 'A'] -= freq['G' - 'A'];
    freq['I' - 'A'] -= freq['G' - 'A'];
    freq['H' - 'A'] -= freq['G' - 'A'];
    freq['T' - 'A'] -= freq['G' - 'A'];
    digits[8] = freq['G' - 'A'];
    freq['G' - 'A'] = 0;

    //THREE
    freq['H' - 'A'] -= freq['T' - 'A'];
    freq['R' - 'A'] -= freq['T' - 'A'];
    freq['E' - 'A'] -= 2 * freq['T' - 'A'];
    digits[3] = freq['T' - 'A'];
    freq['T' - 'A'] = 0;

    for (i = 0; i < 17; i++)
        if (freq[i] > 0)
            cout << i << '\n';
}

int main()
{
    int ii, t;
    int i, j;
    ifstream f("digits.in");
    ofstream g("digits.out");
    f >> t;
    for (ii = 1; ii <= t; ii++)
    {
        f >> number;
        if (ii == 100)
            ii = 100;
        compute_freq();
        compute_digits();
        g << "Case #" << ii << ": ";
        for (i = 0; i < 10; i++)
            for (j = 0; j < digits[i]; j++)
                g << i;
        g << "\n";
    }
    f.close();
    g.close();
    return 0;
}
