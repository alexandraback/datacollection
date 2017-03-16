#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <bitset>
#include <vector>
#include <utility>
#include <map>
#include <set>

#define INF 1061109567
#define IM 1000
#define PI M_PI

#define FU(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define FD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define CL(a,v) memset((a),(v),sizeof(a))

using namespace std;

char a[IM];
char b[IM];
char s[IM] = "yhesocvxduiglbkrztnwjpfmaq";


int main()
{
//    freopen("in.in","r",stdin);
  //  freopen("out.out","w",stdout);
    int T;
    cin>>T;
    getchar();
    FU(j,1,T+1){
	    gets(a);
	    cout<<"Case #"<<j<<": ";
	    int len = strlen(a);
	
	    FU(i,0,len){
		    if(a[i] != ' ')
		    cout<<s[a[i]-'a'];
		    else
			    cout<<" ";
	    }
	    cout<<endl;
    }
    return 0;
}
