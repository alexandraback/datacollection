#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ofstream out;
bool search = true;

void print( ofstream& o, vector<int>& v )
{
   vector<int>::const_iterator it = v.begin();

   o << *it;
   ++it;
   while ( it != v.end() )
   {
      o << " " << *it;
      ++it;
   }
   o << endl;
}

bool test( int*& nums, vector<int>& a, vector<int>& b, unsigned __int64 aSum, unsigned __int64 bSum, int lowIdx, int maxIdx )
{
   if ( aSum == bSum && aSum != 0 )
   {
      out << endl;
      print( out, a );
      print( out, b );

      return true;
   }
   for ( int i = lowIdx; i < maxIdx; ++i )
   {
      a.push_back( nums[i] );
      if ( test( nums, a, b, aSum + nums[i], bSum, i + 1, maxIdx ) )
      {
         return true;
      }
      a.pop_back();
      b.push_back( nums[i] );
      if ( test( nums, a, b, aSum, bSum + nums[i], i + 1, maxIdx ) )
      {
         return true;
      }
      b.pop_back();
   }
   return false;
}

int main()
{
   int numTests;
   vector<int> a;
   vector<int> b;

   cin >> numTests;

   out.open("output.txt");
   for ( int i = 0; i < numTests; ++i )
   {
      int numCont, sumAll;

      cin >> numCont;

      int* cont = new int[numCont];
      for ( int j = 0; j < numCont; ++j )
      {
         cin >> cont[j];
         sumAll += cont[j];
      }

      a.clear();
      b.clear();

      out << "Case #" << (i + 1) << ":";

      bool fail = false;

      if ( !fail && !test( cont, a, b, 0, 0, 0, numCont ) )
      {
         out << " Impossible" << endl;
      }

      delete [] cont;
   }
   out.close();
}