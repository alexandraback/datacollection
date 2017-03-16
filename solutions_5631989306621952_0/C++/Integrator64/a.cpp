#include<iostream>
#include<string>

using namespace std;

int main()
{
  unsigned long long Test;
  cin >> Test;
  for(int tt=1 ; tt<=Test ; tt++)
  {
    string Input;
    cin >> Input;
    string Output = Input.substr(0,1);
    for(int ii = 1 ; ii < Input.size() ; ii++)
    {
      if(Input[ii]>=Output[0])
        Output = Input.substr(ii,1) + Output;
      else
        Output += Input.substr(ii,1);
    }
    cout << "Case #"<< tt << ": " << Output << endl;
  }
  return 0;
}
