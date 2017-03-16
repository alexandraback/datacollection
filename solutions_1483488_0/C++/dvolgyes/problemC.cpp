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

inline int createPairs(const int A,const int B,const int N,vector<pair<int,int> > npair)
{
    npair.resize(0);
    string strN=boost::lexical_cast<string>(N);
    int M;
    for(int i=1; i<strN.size(); i++)
    {
        string strM=strN.substr(i,strN.size()-i)+strN.substr(0,i);
        if (strM[0]=='0') continue;
        M=boost::lexical_cast<int>(strM);
        if (M<N || M>B || M<A|| M==N) continue;
        bool match=false;
        for(int k=0; k<npair.size(); k++)
        {
            if (npair[k]==pair<int,int>(N,M)) {
                match=true;
                break;
            }
        }
        if (match==false)
            npair.push_back(pair<int,int>(N,M));
    }
    return npair.size();
}

int main()
{
    int end;
    cin>>end;
    for(int problem=0; problem<end; problem++)
    {
        int A,B;
        cin>>A>>B;
        int count=0;
        vector<pair<int,int> > npair;
        for(int i=A; i<B; i++)
            count+=createPairs(A,B,i,npair);
        cout<<"Case #"<<(problem+1)<<": "<<count<<endl;
    }

    return 0;
}

