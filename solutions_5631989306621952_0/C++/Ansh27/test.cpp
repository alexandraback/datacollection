#include <iostream>
#include <math.h>
#include <stack>
#include <fstream>
using namespace std;
#include <string.h>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>

int main()
{
   ifstream file("in.in");
   ofstream out("out.out");
   string word;
    int t=1;
   while(getline(file,word,'\n'))
   {


    string ans="";
    ans+=word[0];
    for(int i=1;i<word.length();i++)
    {
        if(word[i]>=ans[0])
        {

            ans=word[i]+ans;
        }
        else{ans=ans+word[i];}
    }
    out<<"Case #"<<t<<": "<<ans<<endl;
    t++;

   }

}
