#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <bitset>

#define INF (1<<30)
using namespace std;
typedef long long LL;
string decode="yhesocvxduiglbkrztnwjpfmaq";
int main()
{
      freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
      int T;
      string line;
      cin>>T; cin.ignore();
      for(int t=1;t<=T;t++)
      {
              getline(cin,line);
              cout<<"Case #"<<t<<": ";
              for(int i=0;i<line.length();i++) 
                 if(line[i]>='a' && line[i]<='z') cout<<decode[line[i]-'a'];
                 else cout<<line[i];
              cout<<endl;
      }
      //system("pause");
      return 0;
}
