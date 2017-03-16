#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

int min(int a, int b) {return (a<b)?a:b;}
int max(int a, int b) {return (a>b)?a:b;}

using namespace std;

typedef long long unsigned llu;

unsigned testNum;

string digits[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN",
                   "EIGHT", "NINE"};
string def_chars[] = {"Z", "", "W", "", "U", "", "X", "", "G", ""};

template <typename T>
string NumberToString ( T Number )
  {
     ostringstream ss;
     ss << Number;
     return ss.str();
  }

bool has_chars (string str, string chars)
{
  unsigned curr_char = 0;
  for (unsigned j = 0; j < str.length (); ++j)
    {
      if (str[j] == chars[curr_char])
        {
          ++curr_char;
          if (curr_char >= chars.length ())
            return true;
        }
    }
  return false;
}

string remove_chars (string str, string chars)
{
  unsigned curr_char = 0;
  for (int j = 0; j < str.length (); ++j)
    {
      if (str[j] == chars[curr_char])
        {
          str.erase(j, 1);
          --j;

          ++curr_char;
          if (curr_char >= chars.length ())
            return str;
        }
    }
  return str;
}

int main(int argc, char **argv)
{
  ifstream ifile("A-small-attempt1.in");
  FILE *ofile = fopen("out.txt", "w");
  ifile >> testNum;
  string s;
  getline (ifile, s);
  for (unsigned i = 0; i < 10; ++i)
      sort (digits[i].begin (), digits[i].end ());
  for (unsigned i = 0; i < testNum; ++i) {
    printf ("Case #%d: ", i+1);
    fprintf (ofile, "Case #%d: ", i+1);
    getline (ifile, s);
    sort (s.begin (), s.end ());
    string ans = "";

    unsigned curr_num = 0;
    while (curr_num < 10)
      {
        bool found = false;
        for (unsigned j = 0; j < def_chars[curr_num].length (); ++j)
          {
            string c_s = "";
            c_s += def_chars[curr_num][j];
            if (has_chars (s, c_s))
              {
                ans += NumberToString (curr_num);
                s = remove_chars (s, digits[curr_num]);
                found = true;
                break;
              }
          }
        if (!found)
          ++curr_num;
      }
    curr_num = 0;
    while (curr_num < 10)
      {
        if (has_chars (s, digits[curr_num]))
          {
            ans += NumberToString (curr_num);
            s = remove_chars (s, digits[curr_num]);
          }
        else
          ++curr_num;
      }
    sort (ans.begin (), ans.end ());
    printf ("%s\n", ans.c_str ());
    fprintf (ofile, "%s\n", ans.c_str ());
    if (s.length () > 0)
      cout << "remaining: " << s << endl;
  }
  ifile.close();
  fclose(ofile);
  return 0;
}
