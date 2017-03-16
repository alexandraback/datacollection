#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#include <math.h>
using namespace std;
int main()
{
  int T;
  int A, B;
  int i,j;
  int ans;  
  int temp, temp2;
  int quo;
  int length,lengthp;
  vector<int> crazy;
  cin >> T;
  for (i =0;i < T; i ++){
    ans =0;
    cin >> A;
    cin >> B;

    for(j=A;j < B+1;j++){      
      length=0;
      temp =j;
      while( temp> 0){
	temp = temp/10;
	length = length +1;
      }
      for(temp = 1; temp< length; temp++){
	quo = j/(pow(10,length-temp));
	temp2 = j%(int(pow(10,length-temp)));
	temp2= temp2*pow(10,temp)+quo;
	crazy.push_back(temp2);
//	cout<< "hi" << endl;
      }
      for(temp=1; temp < crazy.size();temp++){
	for(temp2=0; temp2 < temp;temp2++){
	  if(crazy[temp] == crazy[temp2]){
	    crazy[temp]=0;
	  }
	}
      }
      for(temp=0; temp < crazy.size();temp++){
	if(crazy[temp] >= A && crazy[temp] <=B && j !=crazy[temp]){	  
	  ans = ans+1;
//	  cout << j <<"          " << temp2 << endl;
	}
      }
    crazy.clear();
    }
    cout << "Case #" << i+1 << ": " << ans/2 <<  endl; 
  }
  return 0;
}