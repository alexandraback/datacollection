#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

#include "rational.h"

using namespace std;

int main()
{
     cout.precision(8);
     
     int test_cases;
     cin >> test_cases;
     for(int z=1; z<=test_cases; z++)
     {
          int K, L, S;
          cin >> K >> L >> S;

          string keyboard, target;
          cin >> keyboard >> target;

          /*Algorithm:
            - Every time you find a word, you move to the next position where a word might be.
            - If you find a word there, you start over.
            - Otherwise, continue to next position word might be, but now you know about the
              letter following the string.  What do you know?
            - Maybe I'm overthinking this.
          */
          unordered_map<char,int> probabilities;
          for(int i=0; i<keyboard.length(); i++)
               if(probabilities.count(keyboard[i]))
                    probabilities[keyboard[i]]++;
               else
                    probabilities[keyboard[i]]=1;

          #if 0
          for(auto i=probabilities.begin(); i!=probabilities.end(); ++i)
               cout << (*i).first << ':' << (*i).second << endl;
          #endif
          
          int overlap_pos = target.length();
          for(int i=1; i<target.length(); i++)
          {
               int j;
               for(j=0; i+j<target.length(); j++)
                    if(target[j]!=target[i+j])
                         break;
               if(i+j==target.length())
               {
                    overlap_pos=i;
                    break;
               }
          }
          
          Rational word_probability(1,1);
          for(int i=0; i<target.length(); i++)
               if(probabilities.count(target[i]))
                    word_probability*=Rational(probabilities[target[i]],keyboard.length());
               else
                    word_probability = Rational(0);

          int possible_locs = S - target.length() + 1;
          if(possible_locs < 1)
               word_probability = Rational(0);

          int bananas_to_bring = 0;
          if(word_probability!=Rational(0))
               bananas_to_bring = ceil(((float)(possible_locs))/overlap_pos);

          Rational expected_bananas_consumed = word_probability*Rational(possible_locs);

          #if 0
          cout << possible_locs << endl;
          cout << expected_bananas_consumed << endl;
          cout << bananas_to_bring << endl;
          #endif
          
          cout << "Case #" << z << ": " << bananas_to_bring-((double)(expected_bananas_consumed.Numerator()))/expected_bananas_consumed.Denominator() << endl;
     }

     return 0;
}
