#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

/*
int main ()
{
  char map[26];
  int done[26];
  
  string words[200], codes[100], code;
  
  //int i = 0;
  for(int i = 0; i < 26; i++)
  {
    map[i] = '\0';
    done[i] = 0;
    
  }  
  map[25] = 'q';
  done['q' - 'a'] = 1;
  
  for(int i = 0; i < 23; i++)
  {
    cin>>words[i];    
  }
  for(int i = 0; i < 23; i++)
  {
    cin>>code;    
    string word = words[i];
    
    for (int j = 0; j < word.size ();j++)
    {
      int ind = code[j] - 'a';
      map[ind] = word[j];      
      done[word[j] - 'a'] = 1;
      
    }
    
  }
  map['q' - 'a'] = 'z';
  done['z' - 'a'] = 1;
  
  for(int i = 0; i < 26; i++)
  {
    
    char cur = 'a' + i;    
    cout<<"map["<<map[i] - 'a'<<"] = '"<<cur<<"';"<<endl;
    
  }
  
  
}
*/
 
int main ()
{
  char map[26];
  
  map[24] = 'a';
  map[13] = 'b';
  map[5] = 'c';
  map[8] = 'd';
  map[2] = 'e';
  map[22] = 'f';
  map[11] = 'g';
  map[1] = 'h';
  map[10] = 'i';
  map[20] = 'j';
  map[14] = 'k';
  map[12] = 'l';
  map[23] = 'm';
  map[18] = 'n';
  map[4] = 'o';
  map[21] = 'p';
  map[25] = 'q';
  map[15] = 'r';
  map[3] = 's';
  map[17] = 't';
  map[9] = 'u';
  map[6] = 'v';
  map[19] = 'w';
  map[7] = 'x';
  map[0] = 'y';
  map[16] = 'z';
  string str;  
  int T;
  cin>>T;  
  getline (cin, str);  
  for (int i = 0; i < T; i++)
  {
    getline (cin, str);
    cout<<"Case #"<<i+1<<": "<<flush;    
    for (int j = 0; j < str.size (); j++)
    {
      int ind = str[j] - 'a';      
      if (ind >= 0 && ind < 26)
        cout<<map[ind]<<flush;
      else 
        cout<<" "<<flush;      
    }   
    cout<<endl;    
  }
}
