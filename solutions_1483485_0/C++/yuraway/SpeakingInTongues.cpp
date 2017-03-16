#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//const char replacements [] = "abcdefghijklmnopqrstuvwxyz";
const char replacements [] =   "yhesocvxduiglbkrztnwjpfmaq";

std::string run ( const std::string &line )
{
   const size_t n = line.length ();

   std::string result;

   for ( size_t i=0; i<n; i++ )
   {
      if ( 'a' <= line[i] && line[i] <= 'z' )
         result += replacements [ line[i] - 'a' ];
      else
         result += line[i];
   }

   return result;
}

int main ( int argc, char *argv[] )
{
   if ( argc < 2 )
   {
      std::cerr << "usage: " << argv[0] << " <in-file>" << std::endl;
      return 1;
   }

   std::ifstream is ( argv[1] );

   size_t n = 0;
   is >> n;

   char line [256] = { 0 };
   is.getline ( line, 255 );

   for ( size_t i=0; i<n; i++ )
   {
      is.getline ( line, 255 );

      std::cout << "Case #" << i+1 << ": " << run ( line ) << std::endl;
   }
}

