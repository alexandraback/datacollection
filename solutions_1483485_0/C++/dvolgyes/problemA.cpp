#include <iostream>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <map>

#define foreach(variable,list) for(int variable=0;variable<list.size();variable++)

using namespace std;

template <typename T>
vector<string> fileread(T& stream)
{
vector<string> result;
string line;
while ( stream.good() )
{
   getline(stream,line);
   boost::algorithm::trim(line);
   result.push_back(line);
}
return result;
}

int toInt(std::string& a) {return boost::lexical_cast<int>(a);}
double toFloat(std::string& a) {return boost::lexical_cast<double>(a);}
double toDouble(std::string& a) {return boost::lexical_cast<double>(a);}

char mapping(char x)
{
return x+1;
}

std::map<char,char> learn(string input,string output)
{
map<char,char> result;
for(int i=0;i<input.size();i++) 
   {
   char a=input[i];
   char b=output[i];
   result.insert(pair<char,char>(a,b));
   }
return result;
}

std::string trans(std::string& input,map<char,char>& mapping)
{
string result=input;
for(int i=0;i<input.size();i++)
    result[i]=mapping[input.c_str()[i]];
return result;
}

int main()
{
auto f=fileread(cin);
int ptr=0;
int end=toInt(f[ptr++]);
string example="qzejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
string result ="zqour language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
map<char,char> mapping=learn(example,result);

for(int problem=0;problem<end;problem++)
{
string line=f[ptr++];
string transed=trans(line,mapping);
cout<<"Case #"<<(problem+1)<<": "<<transed<<endl;
}

return 0;
}

