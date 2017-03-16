#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

int main(){
  int cases;
  cin >> cases;
  cout << fixed;
  cout << setprecision(6);
  for(int i=0; i<cases; ++i)
  {
    cout << "Case #" << i+1 << ":";
    int contestants; cin >> contestants;
    vector<int> judgescores = vector<int>(contestants);
    int sum = 0;
    for(int j=0; j<contestants; ++j)
    {
      cin >> judgescores[j];
      sum += judgescores[j];
    }
    vector<double> results(contestants,0);
    vector<bool> participants(contestants,true);
    while(true)
    {
      bool flag = true;
      for(int j=0; j<contestants; ++j)
      {
        double sum1=0.0;

        for(int k=0; k<contestants; ++k)
        {
          if(participants[k])
          {
            sum1 += judgescores[j] - judgescores[k];
          }
        }
        int howmany = 0;
        for(int k=0; k<contestants; ++k)
        {
          if(participants[k])
          {
            howmany++;
          }
        }
        if(participants[j])
        {
          double result = 100*(1/(double)howmany)*(1-(sum1/((double) sum)));
          if(result<0)
          {
            results[j] = 0.0;
            participants[j] = false;
            flag = false;
          }
          else
          {
            results[j] = result;
          }
        }
      }
      if(flag)
      {
        break;
      }
    }
    for(int j=0; j<contestants; ++j)
    {
      cout << " " << results[j];
    }
    
    cout << "\n";
  }
  return 0;
}