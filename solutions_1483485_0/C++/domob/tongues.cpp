/* CodeJam solution tongues in C++ by domob.  */

//#define NDEBUG

#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <stdint.h>

/* Map google to plain text.  */
std::map<char, char> invMapping;


/* The mapping, extracted from the example.  */
const char* plain1 = "our language is impossible to understand";
const char* googl1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
const char* plain2 = "there are twenty six factorial possibilities";
const char* googl2 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
const char* plain3 = "so it is okay if you want to just give up";
const char* googl3 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";

/* Missing pair.  */
const char* plain4 = "qz";
const char* googl4 = "zq";


/* Add information from an example to the mapping.  */

void
addMapping (const std::string& plain, const std::string& google)
{
  assert (plain.size () == google.size ());
  for (unsigned i = 0; i < plain.size (); ++i)
    {
      const char p = plain[i];
      const char g = google[i];

      if (p == ' ')
        {
          assert (g == ' ');
          continue;
        }

      assert (p >= 'a' && p <= 'z');
      assert (g >= 'a' && g <= 'z');

      if (invMapping[g] == '?')
        invMapping[g] = p;
      else
        assert (invMapping[g] == p);
    }
}


/* Solve a single case.  */

void
solve_case ()
{
  std::string in;
  std::getline (std::cin, in);

  for (const char c : in)
    {
      if (c == ' ')
        std::cout << ' ';
      else
        {
          assert (c >= 'a' && c <= 'z');
          std::cout << invMapping[c];
        }
    }
}


/* Main routine, handling the different cases.  */

int
main ()
{
  int n;

  /* Construct the mapping.  */
  for (char i = 'a'; i <= 'z'; ++i)
    invMapping[i] = '?';
  addMapping (plain1, googl1);
  addMapping (plain2, googl2);
  addMapping (plain3, googl3);
  addMapping (plain4, googl4);

  /* Print it out.  */
  /*
  for (char i = 'a'; i <= 'z'; ++i)
    std::cout << i;
  std::cout << std::endl;
  for (char i = 'a'; i <= 'z'; ++i)
    std::cout << invMapping[i];
  std::cout << std::endl;
  */

  /* Handle the cases.  */
  scanf ("%d\n", &n);
  for (int i = 1; i <= n; ++i)
    {
      printf ("Case #%d: ", i);
      solve_case ();
      printf ("\n");
    }

  return EXIT_SUCCESS;
}
