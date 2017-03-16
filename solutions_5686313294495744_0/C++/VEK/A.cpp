#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <set>

int min(int a, int b) {return (a<b)?a:b;}
int max(int a, int b) {return (a>b)?a:b;}

using namespace std;

typedef long long unsigned llu;

unsigned testNum;

template <typename T>
string NumberToString ( T Number )
  {
     ostringstream ss;
     ss << Number;
     return ss.str();
  }

set<string> used_first, used_second;
vector<pair<string, string> > words;
vector<bool> is_fake;
unsigned max_fake = 0;

void try_all_fakes (unsigned pos)
{
  if (pos >= is_fake.size ())
    {
      unsigned fake = 0;
      used_first.clear ();
      used_second.clear ();
      for (unsigned j = 0; j < words.size (); ++j)
        {
          if (!is_fake[j])
            {
              used_first.insert (words[j].first);
              used_second.insert (words[j].second);
            }
        }
      for (unsigned j = 0; j < words.size (); ++j)
        {

          /*cout << words[j].first << " | " << words[j].second << "|" << endl;
            if (used_first.find (words[j].first) == used_first.end ())
            cout << '!' << endl;
            if (used_second.find (words[j].second) == used_second.end ())
            cout << "!!" << endl;
          */
          if (is_fake[j] && used_first.find (words[j].first) != used_first.end ()
              && used_second.find (words[j].second) != used_second.end ())
            ++fake;
        }
      if (fake > max_fake)
        max_fake = fake;
      return;
    }
  is_fake[pos] = true;
  try_all_fakes (pos+1);
  is_fake[pos] = false;
  try_all_fakes (pos+1);
}


int main(int argc, char **argv)
{
  ifstream ifile("C-small-attempt1.in");
  FILE *ofile = fopen("out.txt", "w");
  ifile >> testNum;

  for (unsigned i = 0; i < testNum; ++i) {
    max_fake = 0;
    used_first.clear ();
    used_second.clear ();
    words.clear ();
    is_fake.clear ();
    unsigned word_len;
    string first, second;
    unsigned fake = 0;
    ifile >> word_len;
    getline (ifile, first);
    for (unsigned j = 0; j < word_len; ++j)
      {
        getline (ifile, first, ' ');
        getline (ifile, second);
        words.push_back (make_pair (first, second));
        is_fake.push_back (false);
      }
    sort (words.begin (), words.end ());
    try_all_fakes (0);
    printf ("Case #%d: %d\n", i+1, max_fake);
    fprintf (ofile, "Case #%d: %d\n", i+1, max_fake);
  }
  ifile.close();
  fclose(ofile);
  return 0;
}
