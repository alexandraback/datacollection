#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <set>
#include <string>
#include <sstream>
#include "BigInteger.hh"
#include "BigIntegerUtils.hh"


//Depends on bigint library from https://mattmccutchen.net/bigint/

using namespace std;

int main(){

ifstream inf;
ofstream fout;

inf.open("c.in");
fout.open("out.txt");
if(!inf.good()){
   cout<<"bad input"<<endl;
   return 0;
   }

int T;
inf>>T;

vector<BigInteger> v;

   //cases 1's and 0's
   //case 20002
   //case 20102
   //generate list of palindromes of square palindromes
string max = "1000000";//000000000";

//generate palindromes with 1's and 0's
v.push_back(1);
v.push_back(4);
v.push_back(9);
int numDigits = 29;
   int x = 1<<numDigits;

   for(int i=1;i<x;i++){ // for each 0,1
      //create string
      string str = "";
      for(int j=1;j<=i;j<<=1){
         if(j&i)
            str.push_back('1');
         else
            str.push_back('0');
      }
      //CAN ONLY HAVE 4 1's on a SIDE!!
      if(count(str.begin(),str.end(),'1')>4){
         int pos = str.find("1");
         i+=(1<<pos)-1;
         continue;
         }

      string str3 = str;
      reverse(str.begin(),str.end());
      string str1 = str+'0'+str3;
      string str2 = str+'1'+str3;
      string str6 = str+'2'+str3;
      str+=str3;

      BigInteger a = stringToBigInteger(str);
      BigInteger square = a*a;
      string str4 = bigIntegerToString(square);
      string str5 = str4;
      reverse(str5.begin(),str5.end());
      if(str5.compare(str4)==0)
         v.push_back(square);

      a = stringToBigInteger(str1);
      square = a*a;
      str4 = bigIntegerToString(square);
      str5 = str4;
      reverse(str5.begin(),str5.end());
      if(str5.compare(str4)==0)
         v.push_back(square);

      a = stringToBigInteger(str2);
      square = a*a;
      str4 = bigIntegerToString(square);
      str5 = str4;
      reverse(str5.begin(),str5.end());
      if(str5.compare(str4)==0)
         v.push_back(square);

      a = stringToBigInteger(str6);
      square = a*a;
      str4 = bigIntegerToString(square);
      str5 = str4;
      reverse(str5.begin(),str5.end());
      if(str5.compare(str4)==0)
         v.push_back(square);

      

      //cout<<str<<endl;
   }
  // cout<<"done"<<endl;


   for(int i=2;i<=numDigits*2+1;i++){
      string str = "2";
      for(int j=0;j<i-2;j++)
         str.push_back('0');
      str.push_back('2');

      BigInteger a = stringToBigInteger(str);
      BigInteger square = a*a;
      string str4 = bigIntegerToString(square);
      string str5 = str4;
      reverse(str5.begin(),str5.end());
      if(str5.compare(str4)==0)
         v.push_back(square);


      if(i%2==1){
         string str1 = "2";
         for(int j=0;j<(i+1)/2-2;j++)
            str1.push_back('0');
         str1.push_back('1');
         for(int j=0;j<(i+1)/2-2;j++)
            str1.push_back('0');
         str1.push_back('2');

         a = stringToBigInteger(str1);
         square = a*a;
         str4 = bigIntegerToString(square);
         str5 = str4;
         reverse(str5.begin(),str5.end());
         if(str5.compare(str4)==0)
            v.push_back(square);

      }


   }
   sort(v.begin(),v.end());
//   cout<<v.size()<<endl;
//   cout<<"biggest: \n"<<v[v.size()-1]<<endl;
//   cout<<bigIntegerToString(v[v.size()-1]).size()<<endl;
   //for(int i=0;i<v.size();i++)
     // cout<<v[i]<<endl;


for(int t=0;t<T;t++){

   BigInteger A,B;
   string astr,bstr;
   inf>>astr>>bstr;

   A = stringToBigInteger(astr);
   B = stringToBigInteger(bstr);

   vector<BigInteger>::iterator it;
   it = lower_bound(v.begin(),v.end(),A);
   int c1 = it-v.begin();

   it = lower_bound(v.begin(),v.end(),B);
   int c2 = it-v.begin();
   int ans = c2-c1;
   if(*it==B)
      ans++;

   fout<<"Case #"<<t+1<<": "<<ans<<endl;
   }

fout.close();
return 0;
}







