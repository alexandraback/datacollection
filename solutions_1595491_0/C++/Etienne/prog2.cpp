#include <iostream>

using namespace std;

// When desperate static beats the silence up
// A quiet truth to calm you down

void doCase();

int main()
{
  int cases;
  cin >> cases;

  for(int c=0; c<cases; c++)
    {
      cout << "Case #" << c+1 << ": ";
      doCase();
    }
}

void doCase()
{
  int N;
  cin >> N;
  int S;
  cin >> S;
  int p;
  cin >> p;
  int result=0;
  for(int i=0; i<N; i++)
    {
      int score;
      cin >> score;
      int max = (score==0 ? 0 : 1+(score-1)/3);
      if(max >= p)
	result++;
      if( p>1 && max == p-1 && ((score%3 == 0) || (score%3 == 2)) && S > 0)
	{
	  S--;
	  result++;
	}
    }
  cout << result << endl;
}
