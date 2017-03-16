bool onlyonecase=false;
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "math.h"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list> 
#include <set>
#include <map>
#include <unordered_set> 
#include <unordered_map> 
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <functional>
#include <cstdlib>
#include <string.h>
#include <sstream>

// Useful constants
#define INF                         (t)1e19
#define EPS                         1e-9
// Useful hardware instructions
#define bitcount                    __builtin_popcount
#define gcd                         __gcd
// Useful container manipulation / traversal macros
#define forall(i,a,b)               for (auto i=a;i!=b;i=(a<b)?i+1:i-1 )
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define IMPOSSIBLE "IMPOSSIBLE"

using namespace std;
istream * pin;

//typedef uintmax_t t;
typedef intmax_t t;

t konstansmod=(1e9)+7;

template<typename T>
vector<T> read(int num=-1,int szorzo=1,istream & in=*pin)
{
    vector<T> container;
    if (num==-1)
        in>>num;
    num*=szorzo;
    for (int i=0;i<num;i++)
    {
        T q;
        in>>q;
        container.push_back(q);
    }
    return container;
}


struct printer
{
ostream *o;
printer(ostream &a=cout):o(&a)
{

}

void pr()
{
*o<<"\n";
}

template<typename T>
void pr(T t)
{
*o<<fixed<<std::setprecision(9) << t<<"\n";
}

template<typename T>
void pr(vector<T> t)
{
    for(T w:t)
pr(w);
pr();
}

template<typename T, typename... Args>
void pr(T value, Args... args)
{
//cout<<value;
    pr(value);
pr(args...);
}

};
#define p(args...)  do { printer().pr(args); } while (false)
#ifdef DEBUG
#define dl(...) do {show(std::cerr, "Line", __LINE__);show(std::cerr, #__VA_ARGS__, __VA_ARGS__);} while (false)
#define d(...) do { show(std::cerr, #__VA_ARGS__, __VA_ARGS__); } while (false)
#else
#define dl(...) {}
#define d(...) {}
#endif

template<typename H1>
void show(std::ostream& out, const char* label, H1&& value) {
  //out << label << "=" << std::forward<H1>(value) << '\n';
// printer(out).pr(label+"=").pr(value);
out << label << "=" ;
printer(out).pr(value);
}

template<typename H1, typename ...T>
void show(std::ostream& out, const char* label, H1&& value, T&&... rest) {
  const char* pcomma = strchr(label, ',');
out.write(label, pcomma - label) << "=";
printer(out).pr(value);

 show(out,pcomma+1,std::forward<T>(rest)...);
}

void print(bool b)
{
    cout<<(b?"Yes":"No")<<"\n";
}

vector<double> gauss(vector< vector<double> > A) {
    int n = A.size();

    for (int i=0; i<n; i++) {
        // Search for maximum in this column
        double maxEl = abs(A[i][i]);
        int maxRow = i;
        for (int k=i+1; k<n; k++) {
            if (abs(A[k][i]) > maxEl) {
                maxEl = abs(A[k][i]);
                maxRow = k;
            }
        }

        // Swap maximum row with current row (column by column)
        for (int k=i; k<n+1;k++) {
            double tmp = A[maxRow][k];
            A[maxRow][k] = A[i][k];
            A[i][k] = tmp;
        }

        // Make all rows below this one 0 in current column
        for (int k=i+1; k<n; k++) {
            double c = -A[k][i]/A[i][i];
            for (int j=i; j<n+1; j++) {
                if (i==j) {
                    A[k][j] = 0;
                } else {
                    A[k][j] += c * A[i][j];
                }
            }
        }
    }

    // Solve equation Ax=b for an upper triangular matrix A
    vector<double> x(n);
    for (int i=n-1; i>=0; i--) {
        x[i] = A[i][n]/A[i][i];
        for (int k=i-1;k>=0; k--) {
            A[k][n] -= A[k][i] * x[i];
        }
    }
    return x;
}

void solve();
int main(int argc, char** argv) {
    srand((unsigned) time(NULL));
    ifstream * argfile=NULL;
    string filename="";
    if (argc>=2 && filename.length()==0)
        filename=argv[1];
    if (filename.length()>0)
    {
        argfile=new ifstream(filename);
        if (!argfile->is_open()) {
            cerr<<"file cant be opened,exiting. Filename:"<<filename<<"\n";
            cerr << "Error: " << strerror(errno)<<"\n";
            return 1;
        }
    }
    if (argfile) std::cin.rdbuf(argfile->rdbuf());
    istream & myfile=argfile?*argfile:cin;
    pin=&myfile;
    int num;
    if (onlyonecase)
    {
    solve(); return 0;
    }

    myfile>>num;
    for (int i = 0; i < num; i++) {
        cout<<"Case #"<<(i+1)<<": ";
        solve();
    }
    return 0;
}

void solve()
{
string s;
cin>>s;
map<char,t> h;
forall(i,0,s.length())
{
    h[s[i] ]++;
}
vector<t> nums;
while (h['Z']!=0)
{
    nums.push_back(0);
    h['Z']--;
    h['E']--;
    h['R']--;
    h['O']--;
}

while (h['X']!=0)
{
    nums.push_back(6);
    h['S']--;
    h['I']--;
    h['X']--;
}

while (h['U']!=0)
{
    nums.push_back(4);
    h['F']--;
    h['O']--;
    h['U']--;
    h['R']--;
}

while (h['F']!=0)
{
    nums.push_back(5);
    h['F']--;
    h['I']--;
    h['V']--;
    h['E']--;
}


while (h['W']!=0)
{
    nums.push_back(2);
    h['T']--;
    h['W']--;
    h['O']--;

}

while (h['V']!=0)
{
    nums.push_back(7);
    h['S']--;
    h['E']--;
    h['V']--;
    h['E']--;
    h['N']--;
}

while (h['G']!=0)
{
    nums.push_back(8);
    h['E']--;
    h['I']--;
    h['G']--;
    h['H']--;
    h['T']--;
}

while (h['R']!=0)
{
    nums.push_back(3);
    h['T']--;
    h['H']--;
    h['R']--;
    h['E']--;
    h['E']--;
}

while (h['I']!=0)
{
    nums.push_back(9);
    h['N']--;
    h['I']--;
    h['N']--;
    h['E']--;
}

while (h['N']!=0)
{
    nums.push_back(1);
    h['O']--;
    h['N']--;
    h['E']--;
}


sort(nums.begin(),nums.end());

for (auto i:nums)
{
    cout<<i;
}
cout<<"\n";



}


