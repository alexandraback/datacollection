#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int T;
  cin>>T;
  for (int t = 1; t <= T; t++)
  {
    int a1=0, a2=0;

    int N = 0, i;
    double tmp;
    cin>>N;
    vector<double> Ken1(0), Ken2(N), Naomi1(0), Naomi2(N);
    for (i = 0; i < N; i++)
    {
      cin>>tmp;
      Naomi1.push_back(tmp);

    }
    for (i = 0; i < N; i++)
    {
      cin>>tmp;
      Ken1.push_back(tmp);
    }

    sort(Naomi1.begin(), Naomi1.end());
    sort(Ken1.begin(), Ken1.end());

    copy(Naomi1.begin(), Naomi1.end(), Naomi2.begin());
    copy(Ken1.begin(), Ken1.end(), Ken2.begin());

    for (i = 0; i < N; i++)
    {
      double k_min = Ken1.front();
      vector<double>::iterator itr0 = Naomi1.begin();
      while (itr0 < Naomi1.end() && *itr0 < k_min)
        itr0++;
      double nv;
      if (itr0 == Naomi1.end())
      {
        Naomi1.erase(Naomi1.begin());
        Ken1.erase(Ken1.begin());
      }
      else
      {
        a1++;
        Naomi1.erase(itr0);
        Ken1.erase(Ken1.begin());
      }

      //right rule
      double nv2 = Naomi2.front();
      Naomi2.erase(Naomi2.begin());
      vector<double>::iterator itr2 = Ken2.begin();
      while (itr2 < Ken2.end() && *itr2 < nv2)
        itr2++;
      if (itr2 == Ken2.end())
      {
        a2++;
        Ken2.erase(Ken2.begin());
      }
      else
      {
        Ken2.erase(itr2);
      }
    }

    cout<<"Case #"<<t<<": "<<a1<<" "<<a2<<"\n";
  }
  return 0;
}
