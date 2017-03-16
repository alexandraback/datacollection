#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>

using namespace std;

string operator* (string lhs, const string & rhs) {
     string RET="+e";
     
     if (rhs[1] == '1') RET[1]=lhs[1];
     else if (lhs[1] == '1') RET[1]=rhs[1];
     else if (rhs[1] == lhs[1]) RET="-1";
     else {
          RET[1]=(int)'i' + (int)'j' + (int)'k' - (int)rhs[1] - (int)lhs[1];
          if ((int)lhs[1]%3 == ((int)rhs[1]+1)%3) RET[0]='-';
          else RET[0]='+';
          }
     
     if (lhs[0] != rhs[0]) RET[0]=(int)'+' + (int)'-' - (int)RET[0];
     
     return RET;
     }

int main(void) {
     int num_test;
     cin>>num_test;
          
     for (int test=1; test<=num_test; test++) {
          long long L,X;
          string S;
          cin>>L>>X>>S;
          
          bool doable=true;
          
          string start="+1";
          for (int i=0; i<S.size(); i++) {
               string prod="+1";
               prod[1]=S[i];
               start=start*prod;
               }
          
          string accumulate="+1";
          for (int i=0; i<X%4; i++) accumulate=accumulate*start;
          
          if (accumulate != "-1") doable=false;

          string S_temp=S;
          for (int i=1; i<X && i<8; i++) S+=S_temp;
                    
          start="+1";
          
          vector <string> to_find;
          to_find.push_back("+i");
          to_find.push_back("+k");
          int index=0;

          for (int i=0; i<S.size() && index<2; i++) {
               string prod="+1";
               prod[1]=S[i];
               start=start*prod;
               
               if (start==to_find[index]) index++;
               }
          
          if (index != 2) doable=false;
          
          string RES="NO";
          if (doable) RES="YES";
          
          cout<<"Case #"<<test<<": "<<RES<<"\n";
          }
     return 0;
     }
