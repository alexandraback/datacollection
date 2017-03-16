#include<iostream>
#include<fstream>
#include<sstream>
#include<cstring>

using namespace std;

int calculate_no_of_friends(string line)
{
   int max_shyness;
   istringstream iss1(line);
   iss1 >> max_shyness;
   char all_audience[max_shyness];
   iss1 >> all_audience;
   int no_of_friends = 0;
   int current_shyness = 0;
   if(max_shyness == 0)
   { return 0; }

   for(int j=0;j<=max_shyness;j++)
   {
      if((j==0) && (all_audience[j] == '0'))
      {
         no_of_friends ++;
         current_shyness ++;
      }
      else
      {
         if(current_shyness < j)
         {
            no_of_friends += (j-current_shyness);
            current_shyness += (j-current_shyness);
         }
      }
      current_shyness += (all_audience[j] - '0');
   }
   return no_of_friends;

}

int main(int argc,char* argv[])
{
   string filename;
   filename = argv[1];
   ifstream inf;
   inf.open(filename.c_str());
   string line;
   int no_of_tests;
   getline(inf,line);
   istringstream iss(line);
   iss >> no_of_tests;
   for(int i=0;i<no_of_tests;i++)
   {
      getline(inf,line);
      int total_friends = calculate_no_of_friends(line);
      cout<<"Case #"<<i+1<<": "<<total_friends<<endl;
   }
   inf.close();
   return 0;   
}
