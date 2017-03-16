#include <iostream>
#include <string>
using namespace std;

int main(void){
  int T;
  cin >> T;
  string G;
  char map[] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
  getline(cin,G);
  for(int t = 1; t <= T; ++t){
   getline(cin,G);
   cout << "Case #" << t << ": ";
   for(unsigned int j = 0; j < G.size(); ++j){
    if(G[j] == ' '){
     cout << " ";
    }else{
     cout << map[G[j] - 'a'];
    }
   }
   cout << endl;
  }
}
