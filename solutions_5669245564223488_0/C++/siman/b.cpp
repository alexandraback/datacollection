#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits.h>
#include <string>
#include <string.h>
#include <sstream>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

typedef long long ll;

int solver(){
  int size;
  int cnt = 0;
  string str;
  vector<string> word_list;
  vector<int> index_list;
  cin >> size;
  vector<string> wlist(size);

  for(int i = 0; i < size; i++){
    cin >> str;
    if( str.size() > 4 ){
      str.erase( 2, str.size() - 4 );
    }
    word_list.push_back(str);
  }

  for(int i = 0; i < size; i++){
    index_list.push_back(i);
  }

  int length;

  do{
    bool flag = true;

    //cout << "check: ";
    for(int j = 0; j < size; j++){
      //cout << word_list[j] << " ";
      wlist[j]= word_list[index_list[j]];
    }
    //cout << endl;

    for(int i = 0; i < size && flag; i++){
      str = wlist[i];
      length = str.size();

      if( i == 0 ){
        string str2 = wlist[i+1];
        if( str[length-1] == str2[0] ){
          continue;
        }
        //cout << "type1:" << str << " " << str2 << endl;
        flag = false;
      }else if( i == size-1 ){
        string str2 = wlist[i-1];
        if( str[0] == str2[str2.size()-1] ){
          continue;
        }
        //cout << "type3:" << str2 << " " << str << endl;
        flag = false;
      }else{
        string str2 = wlist[i-1];
        string str3 = wlist[i+1];
        if( str[0] == str2[str2.size()-1] || 
            str[length-1] == str3[0] ||
            ( length > 1 && str[0] == str[1] ) ||
            ( str[length-1] == str[length-2] ) ){
          continue;
        }
        //cout << "type2:" << str2 << " " << str << " " << str3 << endl;
        flag = false;
      }
    }
    if(flag) cnt++;
  }while(next_permutation(index_list.begin(), index_list.end()));

  return cnt;
}

int main(){
  int test_case;
  cin >> test_case;

  for(int i = 1; i <= test_case; i++){
    printf("Case #%d: %d\n", i, solver() );
  }
  return 0;
}
