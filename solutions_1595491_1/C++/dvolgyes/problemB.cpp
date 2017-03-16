#include <iostream>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <map>
#include <algorithm>

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


int main()
{
int end;
cin>>end;
for(int problem=0;problem<end;problem++)
{
int N,S,p;
cin>>N>>S>>p;
vector<int> t_i;
int p_s=0;
int p_ns=0;
for(int i=0;i<N;i++)
{
int t;  cin>>t; t_i.push_back(t); 
//non-surprising
if (t<p) continue;
if (t+2>=3*p) p_ns++; // can be non-surprising and surprising too
    else if (t+4>=3*p) p_s++; // can be non-surprising and surprising too
}
int result=p_ns+min(p_s,S);
cout<<"Case #"<<(problem+1)<<": "<<result<<endl;
}

return 0;
}

