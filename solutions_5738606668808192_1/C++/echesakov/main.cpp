#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void jamcoins(int N, int J)
{
  const int numPositives = N / 2 - 1;
  const int numNegatives = numPositives;

  vector<char> positives(numPositives);
  vector<char> negatives(numNegatives);

  string jamcoin(N, '\0');
  jamcoin[0] = '1';
  jamcoin[N - 1] = '1';

  for (int numPositivesZeros = 0; (J > 0) && (numPositivesZeros <= numPositives); ++numPositivesZeros)
  {
    const int numPositivesOnes = numPositives - numPositivesZeros;
    const int numNegativesOnes = numPositivesOnes;
    const int numNegativesZeros = numNegatives - numNegativesOnes;

    fill(negatives.begin(), negatives.begin() + numNegativesZeros, '0');
    fill(negatives.begin() + numNegativesZeros, negatives.end(), '1');

    do
    {
      fill(positives.begin(), positives.begin() + numPositivesZeros, '0');
      fill(positives.begin() + numPositivesZeros, positives.end(), '1');

      do
      {
        for (int i = 0; i < numPositives; i++)
        {
          jamcoin[2 * i + 1] = positives[i];
        }
        for (int i = 0; i < numNegatives; i++)
        {
          jamcoin[2 * i + 2] = negatives[i];
        }

        cout << jamcoin;

        for (int b = 2; b <= 10; b++)
        {
          cout << " " << b + 1;
        }
        cout << endl;

        --J;
      } while ((J > 0) && next_permutation(positives.begin(), positives.end()));
    } while ((J > 0) && next_permutation(negatives.begin(), negatives.end()));
  }
}

int main()
{
  int T;
  cin >> T;

  for (int i = 0; i < T; ++i)
  {
    int N, J;
    cin >> N >> J;
    
    cout << "Case #" << (i + 1) << ":" << endl;
    jamcoins(N, J);
  }
}