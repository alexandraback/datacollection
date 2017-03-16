#include <vector>
#include <fstream>
#include <list>
#include <map>
#include <set>
#include <iomanip>
#include <deque>
#include <stack>
#include <bitset>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define eps=1e-8
using namespace std;

//correct

int main(){
  //  ofstream fout ("A-small-attempt.out");
    ifstream fin ("A-large.in");
cout<<"!";
int testcases;
fin>>testcases;
FILE* fout=fopen("A-large.out","w");
cout<<"!";

for (int tests=1;tests<=testcases;tests++){
    int a,b;
    fin>>a>>b;
    long double enternow=2+b;
    static long double probcorrect[199999];
    static long double uptothis[199999];
    long double currentprob=1;
    for (int i=0;i<a;i++){
        fin>>probcorrect[i];
        currentprob*=(probcorrect[i]);
        uptothis[i]=currentprob;
    }
    cout<<"!";
    
    long double totalifwrong=2+b-a+b;
    long double totalifright=b-a+1;
    long double expectednow=currentprob*totalifright+(1-currentprob)*totalifwrong;
    //cout<<expectednow<<endl;
    if (expectednow>enternow)expectednow=enternow;
    
    for (int i=a-1;i>=1;i--){
        totalifright+=2;
        totalifwrong+=2;
        if (i==0)totalifwrong=totalifright;
        long double temp=uptothis[i-1]*totalifright+(1-uptothis[i-1])*totalifwrong;
        if (temp<expectednow)expectednow=temp;
      //  cout<<temp<<endl;
    }


//cout<<tests<<endl;
double ans=expectednow;
/* cout<<"Case #"<<tests<<": "<<expectednow<<endl;
fout<<"Case #"<<tests<<": "<<expectednow<<endl; */
printf("Case #%d: %f\n",tests,(float)expectednow);
fprintf(fout,"Case #%d: %f\n",tests,(float)expectednow);
} 


//system("pause");
return 0;
}
