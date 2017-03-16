#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  int cnt;
  cin >> cnt;
  for(int i = 0; i < cnt; ++i)
    {
      int ms;
      string str;
      cin >> ms >> str;
      vector<int> vec;
      int ans=0;
      for(int j = 0; j < str.size(); ++j)
	{
	  if(j==0)
	    vec.push_back(str[j]-'0');
	  else
	    {
	      vec.push_back(vec[j-1]+str[j]-'0');
	      int diff=j-vec[j-1];
	      if(diff>ans)
		{ans=diff;}
	    }
	}
      cout << "Case #" << i+1 << ": " << ans << endl;
    }
}
