#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
  unsigned long long Test;
  cin >> Test;
  for(int tt=1 ; tt<=Test ; tt++)
  {
    int Data[2500] = {0};
    int N;
    cin >> N ;
    for(int ii = 0 ; ii < 2 * N -1; ii++)
    {  for(int jj = 0 ; jj< N ; jj++)
      {
        int x;
        cin >> x;
        Data[x]++;
      }
    }

    vector<int>Out;
    for(int ii=0 ; ii<2500 ; ii++)
      if(Data[ii]%2 == 1)
        Out.push_back(ii);
    sort(Out.begin(), Out.end());
    cout << "Case #"<< tt << ":";
    for(int ii=0 ; ii<Out.size() ; ii++)
      cout << " " << Out[ii];
    cout << endl;
  }
  return 0;
}
