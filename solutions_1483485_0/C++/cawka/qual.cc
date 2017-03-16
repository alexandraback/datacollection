/* -*- Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil -*- */

#include <iostream>
#include <sstream>
#include <map>
using namespace std;


map<char,char> Mapping;
map<char,char> ReverseMapping;

inline char
GetMap (char coded);


inline void
SetMap (char coded, char real)
{
  map<char,char>::iterator realMap = ReverseMapping.find (real);
  if (realMap != ReverseMapping.end ())
    {
      cerr << "Mapping for " << real << " already exists" << endl;
      exit (1);
    }

  if (GetMap (coded) != '?')
  {
    cerr << "Duplicate mapping of " << coded << endl;
    exit (1);
  }
  
  Mapping [coded] = real;
  ReverseMapping [real] = coded;
}

inline char
GetMap (char coded)
{
  map<char,char>::iterator i = Mapping.find (coded);
  if (i != Mapping.end ())
    return i->second;
  else
    return '?';
}

void
PrintMissing ()
{
  cout << "Real characters that hasn't mapped yet: \n";
  for (int i=0; i<26; i++)
    {
      map<char,char>::iterator realMap = ReverseMapping.find ((char) ('a' + i));
      if (realMap == ReverseMapping.end ())
        cout << " - " << (char) ('a' + i) << endl;
      
      // cout << "SetMap ('" << (char)(i+'a') << "', '');\n";
    }
}

int main ()
{
  // for (int i=0; i<26; i++)
  //   cout << "SetMap ('" << (char)(i+'a') << "', '');\n";

  string line;
  getline (cin, line);
  istringstream is (line);
  int N;
  is >> N;
  
  SetMap ('a', 'y');
  SetMap ('b', 'h');
  SetMap ('c', 'e');
  SetMap ('d', 's');
  SetMap ('e', 'o');
  SetMap ('f', 'c');
  SetMap ('g', 'v');
  SetMap ('h', 'x');
  SetMap ('i', 'd');
  SetMap ('j', 'u');
  SetMap ('k', 'i');
  SetMap ('l', 'g');
  SetMap ('m', 'l');
  SetMap ('n', 'b');
  SetMap ('o', 'k');
  SetMap ('p', 'r');
  SetMap ('q', 'z');
  SetMap ('r', 't');
  SetMap ('s', 'n');
  SetMap ('t', 'w');
  SetMap ('u', 'j');
  SetMap ('v', 'p');
  SetMap ('w', 'f');
  SetMap ('x', 'm');
  SetMap ('y', 'a');
  SetMap ('z', 'q');  
  
  for (int i = 0; i < N; i++)
    {
      cout << "Case #" << (i+1) << ": ";
      string line;
      getline (cin, line);
      for (string::iterator ch = line.begin (); ch != line.end (); ch++)
        {
          if (*ch == ' ')
            cout << ' ';
          else
            cout << GetMap (*ch) << flush;
        }
      cout << endl;
    }

  // PrintMissing ();
  
  return 0;
}

