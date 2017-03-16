#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <math.h>
#include <algorithm>


using namespace std;


int akrepili[200];
string kb, word;
int k, l, s;

int num_instances()
{
   int n = 0;
   for(int i = 0; i <= s - (signed int) word.size(); i++)
   {
   	bool ok = true;
    for (int j = 0; j < word.size(); j++)
    {
      if (kb[akrepili[i+j]] != word[j]) ok = false;
    }
    if(ok) n++;
   }

//    if (n > 0)
  //  {
//    	printf("Printing good numbers:.\n");
  //  	for(int i = 0; i < s; i++) cout << akrepili[i] << " ";
    //    cout << ".\n\n";
//    }


   return n;
}

int longest_suffix_match(string s)
{
  for(int i = 1; i < s.size(); i++)
  {
  	bool ok = true;
    for(int j = 0; j + i < s.size(); j++)
    {
    	if (s[i+j] != s[j]) ok = false;
    }
    if(ok) return i;
  }

  return s.size();

}

int main()
{
int t;
cin >> t;
for(int T = 0; T < t; T++)
{
	cin >> k >> l >> s;
	cin >> kb >> word;

    int eteva = 0;

    bool aklia = false;

    //asoebi xo ar gvaklia
    for(int i = 0; i < word.size(); i++)
    {
      if (kb.find(word[i]) == string::npos)
      {
      	printf("Case #%d: 0.0\n", T+1);
      	aklia = true;
      	break;
      }
    }

    if (aklia) continue;

    if (word.size() <= s)
    {
      int pref = longest_suffix_match(word);
      eteva = 1 + (s - word.size())/pref;
    }


    for(int i = 0; i < s; i++) akrepili[i] = 0;

    double onne = 1.0;
    double prob = pow(onne/kb.size(), s);

    double bananas = 0;

    while(true) 
    {
       bananas+=prob*num_instances();

       bool morcha = true;
       for(int i = 0; i < s; i++) if (akrepili[i] != kb.size() - 1) morcha = false;

       if (morcha) {
      	printf("Case #%d: %.10f\n", T+1, eteva - bananas);
       	break;
       }

       for(int i = s-1; i>=0; i--)
       {
          if (akrepili[i] == kb.size() -1)
          {
          	akrepili[i] = 0;
          }
          else
          {
          	akrepili[i]++;
          	break;
          }
       }
    }
}

}
