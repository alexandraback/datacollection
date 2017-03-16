#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int getLowestPossible(const long double& a, const vector<long double>& vec)
{
  long double lowest = 1.1f;
  long double true_lowest = 1.1f;
  int id_lowest = -1;
  int true_id = -1;
  for(int i = 0; i < (int) vec.size();i++)
  {
    if(vec[i] < true_lowest){
      true_lowest = vec[i];
      true_id = i;
    }
    if(vec[i] > a && vec[i] < lowest){
      id_lowest = i;
      lowest = vec[i];
    }
  }

  if(id_lowest == -1)
    return true_id;

  return id_lowest;
}

int getBestChoise(const vector<long double>& naomi, const vector<long double>& )
{
  return naomi.size()-1;
}

int main(int, char**)
{
  int test_cases;
  cin >> test_cases;

  for(int id = 1; id <= test_cases; id++)
  {
    int n_pieces;
    long double buffer;
    cin >> n_pieces;
    vector<long double> Naomi;
    vector<long double> Ken;
    vector<long double> Naomi2;
    vector<long double> Ken2;
    
    for(int i = 0; i < n_pieces;i++)
    {
      cin >> buffer;
      Naomi.push_back(buffer);
      Naomi2.push_back(buffer);
    }
    for(int i = 0; i < n_pieces;i++)
    {
      cin >> buffer;
      Ken.push_back(buffer);
      Ken2.push_back(buffer);
    }

    //Joga jogos

    sort(Naomi2.begin(), Naomi2.end());
    sort(Ken2.begin(), Ken2.end());
    // for(int i = 0; i < (int)Naomi2.size();i++)
    // {
    //   cout << "n("<<i<<"): " << Naomi2[i] <<endl;
    //   cout << "n("<<i<<"): " << Ken2[i] <<endl;
    // }

    int victories=0;
    int deceitful_victories=0;
    while(Naomi.empty() == false)
    {
      //Normal War
      long double a = Naomi[0];
      long double lowest = getLowestPossible(a, Ken);

      if(a > Ken[lowest]){
        victories++;
      }
      Naomi.erase(Naomi.begin());
      Ken.erase(Ken.begin()+lowest);

      //Deceitful war
      long double told = 0;
      long double chosenKen;
      //Verificar se não existe em Ken antes!!!!!!!!!!!!!
      if( Naomi2[0] > Ken2[0] )
      {
        told = Ken2[Ken2.size()-1]+1;
        deceitful_victories++;
      } else
      {
        told = Ken2[Ken2.size()-1]-0.001;
      }
      chosenKen = getLowestPossible(told, Ken2);
      
      Naomi2.erase(Naomi2.begin());
      Ken2.erase(Ken2.begin()+chosenKen);

    }
    cout << "Case #" << id << ": " << deceitful_victories << " " << victories  <<  endl;

  }
  return 0;
}