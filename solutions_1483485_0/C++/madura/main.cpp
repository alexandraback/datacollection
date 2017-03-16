#define PROBLEM "A"
//#define PROBLEM_ID "large-0"
#define PROBLEM_ID "small-attempt0"
#include<iostream>
#include<map>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<sstream>
#include<list>
#include<set>
#include<algorithm>
#include<sstream>

using namespace std;

typedef stringstream ss;
typedef unsigned char uchar;

int main()
{

    freopen(PROBLEM"-"PROBLEM_ID".in","r",stdin);
    freopen(PROBLEM"-"PROBLEM_ID".out","w",stdout);

    int cases=0,c=0;
    //char line[1000];
    cin>>cases;
    cin.ignore(10,'\n');
    //cin.getline(line,1000);
   char gtoe[256]={'\0'};
    gtoe[97]='y';
gtoe[98]='h';
gtoe[99]='e';
gtoe[100]='s';
gtoe[101]='o';
gtoe[102]='c';
gtoe[103]='v';
gtoe[104]='x';
gtoe[105]='d';
gtoe[106]='u';
gtoe[107]='i';
gtoe[108]='g';
gtoe[109]='l';
gtoe[110]='b';
gtoe[111]='k';
gtoe[112]='r';
gtoe[113]='z';
gtoe[114]='t';
gtoe[115]='n';
gtoe[116]='w';
gtoe[117]='j';
gtoe[118]='p';
gtoe[119]='f';
gtoe[120]='m';
gtoe[121]='a';
gtoe[122]='q';
    while (c++<cases){
        int rep;
        char goo[120];
        char eng[120];
        cin.getline(goo, 120);
        //cin.getline(eng, 120);
        for (int i=0;i<strlen(goo)+1;i++) {
            if (goo[i]!=' '){
                //gtoe[(unsigned int)goo[i]] = eng[i];
                eng[i]=gtoe[goo[i]];
            }
            else{
                eng[i]=' ';
            }
        }
        cout<<"Case #"<<c<<": ";
        cout<<eng;
        cout<<endl;
    }
/*    for (int i=97;i<123;i++) {
        
        cout<<"gtoe["<<i<<"]='"<<gtoe[i]<<"';";
        cout<<endl;
    }*/
    return 0;
}