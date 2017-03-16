#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int64_t pow (int64_t base, int64_t exponent)
{
    int64_t i, result = 1;
    for (i = 0; i < exponent; i++)
        result *= base;
    return result;
}

int64_t j_incrementor (int64_t j)
{
    int64_t k, i = 10;
    for (k = 0; (j / i) % 10 != 0; k++, i *= 10);
    j += pow (10, k + 1);
    for (;k != 0; k--)
        j -= pow (10, k);
    return j;
}

int64_t any_to_ten (int64_t num, int64_t base)
{
    stringstream ss; string line;
    ss << num;
    ss >> line;
    int64_t sum=0;
    cout << line;
   /* for(int64_t i=line.length()-1; i>=0; i--)*/
    for (int64_t i = 0; i < line.length (); i++)
        {
            int64_t x=line[i]-'0';
            if(x==1)
                sum+=pow(base,line.length () - 1 - i);
        }
    return sum;
}

int main()
{
    int64_t cases, number, array[17], i, j, k, l, N, J, temp, factor[9];
    int64_t prime[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
    ifstream fin;
    ofstream fout;
    fin.open ("input.txt");
    fout.open ("output.txt");
    fout << "Case #1:";
    fin >> cases;
    fin >> N;
    fin >> J;
    /*
    for (i = 0; i < 17; i++)
        array[i] = 0;
    temp = N;
    for (i = 0; i < N; i++)
    {
        array[i] = temp % 10;
        temp /= 10;
    }
    */
    for (i = 0, j = pow (10, N - 1) + 1; i < J && j < pow (10, N) - 1; j = j_incrementor (j))
    {
        for (k = 2; k <= 10; k++)
        {
            number = any_to_ten (j, k);
            cout << number << endl;
            for (l = 0; l < 26; l++)
            {
                if (number % prime[l] == 0)
                {
                    factor[k - 2] = prime[l];
                    break;
                }
            }
            if (l == 26)
                break;
        }
        if (k == 11)
        {
            fout << endl << j;
            for (l = 0; l < 9; l++)
            {
                fout << " " << factor[l];
            }
            i++;
        }
    }
    fin.close ();
    fout.close ();
    return 0;
}
