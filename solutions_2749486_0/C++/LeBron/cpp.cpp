/*

*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <memory.h>
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define  INF 100000000
#define eps 1e-6
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long ts;
long x,y,tests;
vector<char> v;
void mr()
{v.push_back('W');v.push_back('E');--x;}
void ml()
{v.push_back('E');v.push_back('W');++x;}
void mu()
{
 v.push_back('S');v.push_back('N');--y;
}
void md()
{
 v.push_back('N');v.push_back('S');++y;
}

int main(){
//freopen("funny.in","r",stdin);
//freopen("funny.out","w",stdout);
freopen("C:/input.txt","r",stdin);
freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);

cin>>tests;

for (;tests;--tests)
{
    cin>>x>>y;
    v.clear();
    while (x>0){mr();}
    while (y>0){mu();}
    while (x<0){ml();}
    while (y<0){md();}
    ++ts;
    cout<<"Case #"<<ts<<": ";
    for (int i=0;i<v.size();i++)
    cout<<v[i];
    cout<<endl;
}
cin.get();cin.get();
return 0;}




