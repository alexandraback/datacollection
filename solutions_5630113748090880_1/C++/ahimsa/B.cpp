#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<map>
using namespace std;


int main()
{
  int t;
  cin>>t;
  for(int test = 0; test < t; test++)
    {
      long long N;
      cin>>N;
      map<int, int> count;
      for(int i=0; i< 2 * N - 1 ; i++)
        {
          for(int j=0; j < N ; j++)
            {
              long long temp;
              cin>>temp;
              count[temp]++;
            }
        }
      vector<int> numbers;
      for(auto it = count.begin(); it != count.end(); it++)
        {
          if((it->second % 2) !=0)
            numbers.push_back(it->first);
        }
      sort(numbers.begin(), numbers.end());
      printf("Case #%d: ", test + 1);
      for(int i=0; i < numbers.size();i++)
        {
          cout<<numbers[i]<<" ";
        }
      cout<<endl;
      
    }
}
