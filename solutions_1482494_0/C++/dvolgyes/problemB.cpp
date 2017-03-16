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

int toInt(std::string& a) {
    return boost::lexical_cast<int>(a);
}
double toFloat(std::string& a) {
    return boost::lexical_cast<double>(a);
}
double toDouble(std::string& a) {
    return boost::lexical_cast<double>(a);
}

int solve(vector<long>&a,vector<long>&b)
{
int stars=0;
vector<long> finished;
finished.resize(a.size(),0);

bool end=false;
int steps=0;
while(end==false)
{
start:
end=true;
for(int i=0;i<a.size();i++)
    if (finished[i]!=2) {end=false;break;}
if (end) return steps;

//for(int i=0;i<a.size();i++)    cout<<" "<<finished[i];     cout<<endl;

bool change=false;
for(int i=0;i<a.size();i++)
{
    if (finished[i]==0 && b[i]<=stars && a[i]<=stars   ) {finished[i]=2;stars+=2;steps++;change=true;}
    if (finished[i]==1 && b[i]<=stars && a[i]<=stars) {finished[i]=2;stars++;steps++;change=true;}
}
if (change) continue;
for(int i=0;i<a.size();i++)
    if (finished[i]==0 && a[i]<=stars) {finished[i]=1;stars++;steps++;goto start;}
return -1;
}

}

int main()
{
    int end;
    cin>>end;
    for(int problem=0; problem<end; problem++)
    {   
        int levels;
        cin>>levels;
        std::vector<long> a,b;
        for(int l=0;l<levels;l++)
        {
        int t;
        cin>>t; a.push_back(t);
        cin>>t; b.push_back(t);        
        }
//        cout<<levels<<endl;
//        continue;
        int count=solve(a,b);
        if (count<0) 
            cout<<"Case #"<<(problem+1)<<": Too Bad"<<endl;
        else
            cout<<"Case #"<<(problem+1)<<": "<<count<<endl;
    }
    return 0;
}

