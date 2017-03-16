#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits.h>

using namespace std;

#define forn(i, n) for (long i = 0; i < (long)(n); i++)
#define forn1(i, n) for (long i = 1; i <= (long)(n); i++)

long *answers;

long reverseNumber( long in )
{
    long digit = 0;
    long out = 0; 
    
    if(in == 0)
    {
        return 0;
    }
    else
    {
        while(in > 0)
        {
            digit = in % 10;
            in = in / 10;
            out = out * 10 + digit;
        }
        return out;
    }
}

bool populated = false;
long max_index = -1;

void populateArray( long max )
{
   max_index = max;
   answers = new long[max_index];

   forn( i, max_index )
   {
      answers[i] = -1;
   }

   answers[0] = 0;

   forn( i, max_index )
   {
      long answer = answers[i];
      if (answers[i+1] == -1 || answers[i+1] > answer)
         answers[i+1] = answer + 1;

      long index_flip = reverseNumber( i );
      if (answers[index_flip] == -1 || answers[index_flip] > answer)
         answers[index_flip] = answer + 1;
   }

   populated = true;
}

void solve( long count )
{
   // First find max
   long *inputs = new long[count];
   long max_in = 0;
   forn( i, count ) {
      cin >> inputs[i];
      if (inputs[i] > max_in)
         max_in = inputs[i];
   }

   // Populate array
   if (!populated)
      populateArray( max_in + 1 );

   // Get answers
   forn( i, count ) {
      cout << "Case #" << i+1 << ": " << answers[inputs[i]] << endl;
   }
}

int main()
{
   freopen("one.in", "r", stdin);
   freopen("one.out", "w", stdout);

   long count;
   cin >> count;
   solve( count );
   return 0;
} 
