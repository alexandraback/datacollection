#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <set>
#include <string>
#include <map>

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)

typedef long long int LLI; 
typedef pair<int, int> PII; 

int main()
{
  int T;
  cin >> T;
  REP(t, T){
    int oX, oY; 
    int X,Y;
    string result; 
    
    cin >> oX >> oY; 
    X=abs(oX);
    Y=abs(oY); 
    
    //cout << oX << "," << oY << " : " << X << "," << Y << " : " << endl;
 
    while(X>0){
      result += "WE"; 
      X--; 
    }
    
    while(Y>0){
      result += "SN"; 
      Y--;
    }
    
    //translate
    REP(i, result.size()){
      if(oX < 0){
        if(result[i] == 'E') result[i]='W';
        else if(result[i] == 'W') result[i]='E';
      }
      if(oY < 0){
        if(result[i] == 'N') result[i]='S';
        else if(result[i] == 'S') result[i]='N';
      }
    }
  
    cout << "Case #"<<t+1<<": " << result << endl;
  }
	return 0;
}
