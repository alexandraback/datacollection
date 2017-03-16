#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>
#define REP(i,s,e) for(int i=s;i<e;++i)
using namespace std;
ifstream fin("in.txt");
ofstream fout("out.txt");
bool greaterNumber(const pair<int,double> &v1,const pair<int,double> &v2)
{
    return v1.second > v2.second;
}
bool lessNumber(const pair<int,double> &v1,const pair<int,double> &v2)
{
    return v1.second < v2.second;
}
int main()
{
    int T;
    fin >> T;
    vector<pair<int,double> > numbers;
    int p2;
    int res1,res2;
    int n;
    double temp;
    REP(caseNumber,1,T+1)
    {
        numbers.clear();
        fin >> n;
        cout << n << endl;
        REP(i,0,n)
        {
            fin >> temp;
            numbers.push_back(make_pair(0,temp));
        }
        REP(i,0,n)
        {
            fin >> temp;
            numbers.push_back(make_pair(1,temp));
        }
        sort(numbers.begin(),numbers.end(),lessNumber);
        res1=0;
        p2=0;
        for(vector<pair<int,double> >::iterator it = numbers.begin();it != numbers.end();++it)
        {
            if((*it).first ==0)
            {
                if(p2>0)
                {
                    p2--;
                    res1++;
                }
            }
            else p2++;
        }
        sort(numbers.begin(),numbers.end(),greaterNumber);
        res2 = 0;
        p2=0;
        for(vector<pair<int,double> >::iterator it = numbers.begin();it != numbers.end();++it)
        {
            if((*it).first ==0)
            {
                if(p2>0)
                {
                    p2--;
                }
                else
                {
                    res2++;
                }
            }
            else p2++;
        }
        fout << "Case #" << caseNumber << ": "<<res1<<' '<<res2 <<'\n';
    }
    return 0;
}
