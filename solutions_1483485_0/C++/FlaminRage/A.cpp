#include<iostream>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<utility>
#include<iomanip>
#include<queue>
#define eps 1e-9
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define pi acos(-1.0)
#define SET(a) memset(a,-1,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define inf 1000000000
using namespace std;

map<char,char>conv;

void func()
    {
    conv['a']='y';
    conv['b']='h';
    conv['c']='e';
    conv['d']='s';
    conv['e']='o';
    conv['f']='c';
    conv['g']='v';
    conv['h']='x';
    conv['i']='d';
    conv['j']='u';
    conv['k']='i';
    conv['l']='g';
    conv['m']='l';
    conv['n']='b';
    conv['o']='k';
    conv['p']='r';
    conv['q']='z';
    conv['r']='t';
    conv['s']='n';
    conv['t']='w';
    conv['u']='j';
    conv['v']='p';
    conv['w']='f';
    conv['x']='m';
    conv['y']='a';
    conv['z']='q';
    return;
    }

int main()
{
freopen("Ain.txt","r",stdin);
freopen("Aout.txt","w",stdout);
int t,kk=1;
func();
string s;
scanf("%d",&t);
getchar();
while(t--)
    {
    getline(cin,s);
    int sl=s.length();
    for(int i=0;i<sl;i++)
        {
        if(s[i]>='a' && s[i]<='z')
            {
            s[i]=conv[s[i]];
            }
        }
    cout<<"Case #"<<kk++<<": "<<s<<endl;
    }
return 0;
}
