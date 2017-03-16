#include <iostream>
#include <string.h>

using namespace std;

const char c[26] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

int main ()
{
  int n;
  cin >> n;
  string str;
    getline(cin, str);
  for (int i=0; i<n; i++) {
    getline(cin, str);
    for (int j=0; j<str.size(); j++) {
      if (str[j]!=' ')
        str[j] = c[str[j]-'a'];
    }
    cout << "Case #"<<i+1<<": "<<str<<endl;
  }
  return 0;
}
