// jam12

#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int cont[2500];

int main()
{
  int numTestes;
  cin >> numTestes;
  for(int i =0; i < numTestes; i++)
  {
    cout << "Case #" << i+1 << ": ";
    int dim = 0;
    cin >> dim;
    for(int i =0 ; i < 2499; i++)
    {
      cont[i] = 0;
    }
    int aux;
    for(int i = 0; i < (2*dim-1)*dim; i++)
    {
      cin >> aux;
      cont[aux]++;
    }
    bool first = true;
    for(int i = 0; i < 2500; i++)
    {
      if(cont[i] % 2 != 0)
      {
        if(!first) cout << " ";
        else first = false;
        cout << i ;
      }
    }
    cout << "\n";
  }
  return 0;
}
