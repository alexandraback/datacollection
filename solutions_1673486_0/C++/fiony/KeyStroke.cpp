#define SMALL_CASE
//#define LARGE_CASE

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define rep(i,n) for(unsigned int i=0;i<n;i++)
#define rep2(i,m,n) for(int i=m;i<n;i++)
double GetKeyStroke(vector<double>& pos,int A, int B)
{
    double result = -1;
    //case:giveup
    double key_giveup = B+2;
    result = key_giveup;

    //case:continue
    double allright = 1;
    for( int i=0;i<pos.size();i++ )
        allright *= pos[i];
    double key_cont = allright*(B-A+1) + (1-allright)*(2*B-A+2);
    if(result > key_cont)
        result = key_cont;

    //case: delete
    vector<double> key_del(A-1);
    double before_right = 1;
    for( int i=0;i<pos.size();i++ )
    {        
        //double key_val = before_right * (A-i+B-i+1) + (1-before_right)*(A-i+B-i+1+B+1)
        double key_val = before_right * (A+B-2*i+1) + (1-before_right)*(A+2*B-2*i+2);
        if( result > key_val )
            result = key_val;
        before_right *= pos[i];
    }
    return result;    
}

int main(int argc, char* argv[])
{
#ifdef SMALL_CASE
    const char* input_file = "A-small-attempt0.in";
    const char* output_file = "A-small.out";
#endif
#ifdef LARGE_CASE
    const char* input_file = "B-large-practice.in";
    const char* output_file = "B-large.out";
#endif
    //ifstream ifs(input_file,ios_base::in);
    //ofstream ofs(output_file,ios_base::out);
    freopen(input_file,"r",stdin);
    freopen(output_file,"w",stdout);
    int num;
    cin >> num;
    vector<double> myPos;
    rep(i,num)
    {
        myPos.clear();
        int A, B;
        cin >> A >> B;
        rep(j,A)
        {
            double val;
            cin >> val;
            myPos.push_back(val);
        }        
        cout << "Case #" << i+1 << ": ";
        //cout.unsetf(ios::floatfield);
        //cout.precision(6);
        cout <<  std::fixed << std::setprecision(6) << GetKeyStroke(myPos,A,B) << endl;
    }
}
