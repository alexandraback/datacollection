#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
std::ifstream input;
std::ofstream output;
 

char change[256];
void Work() {
  string line;
  getline(input,line); 
  // cout<< line <<endl;
  for (int i = 0; i< line.size(); ++i) {
    line[i] = change[(int)line[i]];
  }
  output<<line<<endl;
}

void PreProcess(char *a,char *b) {
   char *p = a,*pd = b;
  while (*p != 0) {
    change[int(*p)] = *pd;
    ++p;++pd;
  }
}

int main() {
  int t = 0,tcase;
  string inputfile("input.txt");
  string outputfile("output.txt");
  input.open(inputfile.c_str());
  output.open(outputfile.c_str());
  input>>t;
  tcase = 0;
  memset(change, 0 , sizeof(change));
  char a1[] ="ejp mysljylc kd kxveddknmc re jsicpdrysi";
  char a2[] ="rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
  char a3[] = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
  char b1[] ="our language is impossible to understand";
  char b2[] = "there are twenty six factorial possibilities";
  char b3[] = "so it is okay if you want to just give up";
  char ex1[] = "qz";
  char ex2[] = "zq";
  PreProcess(a1,b1);
  PreProcess(a2,b2);
  PreProcess(a3,b3);
  PreProcess(ex1,ex2);
  /*int sum = 0;
  
  for (int i = 0; i< 255;++i) {
    if ( change[i] != 0) {
      char c = change[i];
      cout<<(char)i<<"-->"<<c<<" "<<endl;
      ++sum;
    }
  }
  cout<<sum<<" In total"<<endl;*/
  string line;
  getline(input,line);
  while( t--) {
    ++tcase;
    output<<"Case #"<<tcase<<": ";
    Work();
    }
  input.close();
  output.close();
  return 0;
}
