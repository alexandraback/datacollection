#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

string s;
vector<int> sor;
vector<char> bit;

string str;

long long cnt(int n)
{
    long long r=n;
    return (r*(r-1))/2+r;
}

void megold(istream& in, ostream &out)
{
    int n;
    sor.clear();

    /*in>>c;
    while(c!=' ') {
        l++;
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') {
            hossz++;
        }
        else {
            if(hossz>0) {
                sor.push_back(hossz);
                hossz=0;
            }
        }
        in>>c;
        //cout<<c;
    }
    l--;*/
    in>>str;
    bit.resize(str.length());
    in>>n;
    int lastc=0;
    for(int i=str.size()-1;i>=0; i--)
    {
        char c=str[i];
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') {
            bit[i]=0;
            lastc=0;
        } else {
            if(lastc>=n-1) {
                bit[i]=1;
            }
            else {
                bit[i]=0;
            }
            lastc++;
        }
    }
    bit.resize(bit.size()-n+1);

    sor.clear();
    int hossz=0;
    for(int i=0;i<bit.size(); i++) {
        if(bit[i]==0) {
            hossz++;
        }
        else {
            if(hossz>0) {
                sor.push_back(hossz);
                hossz=0;
            }
        }
    }
    if(hossz>0) sor.push_back(hossz);

    long long ret=cnt(str.size()-n+1);
    /*cout<<"bit"<<endl;
    for(int i=0;i<bit.size(); i++) {
        cout<<(int)bit[i];
    }
    cout<<endl;*/
    for(int i=0;i<sor.size(); i++) {
        //cout<<sor[i]<<' ';
        ret-=cnt(sor[i]);
    }
    //cout<<endl;

    cout<<"r="<<ret<<endl;
    out<<ret;
}


int main()
{
    ifstream in("A-small-attempt0.in");
    ofstream out("cons.out");
    int n;
    in>>n;


    //out<<setprecision(9);
    for(int i=1; i<=n; i++)
    {
        out<<"Case #"<<i<<": ";
        megold(in, out);
        out<<endl;
    }
    in.close();
    out.close();
    return 0;
}
