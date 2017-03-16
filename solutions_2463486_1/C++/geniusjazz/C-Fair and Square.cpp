#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <algorithm>
#include "bigint.h"
#include <vector>

using namespace std;
const int LEN = 25;
vector<bigint> answer;
int middle; 
string half;

void addPalin(string half)
{
     string truehalf = half.substr(half.find_first_not_of("0"));
    string invhalf = string ( truehalf.rbegin(), truehalf.rend() );
       for (int i = 0 ; i <= middle ; i++)
       {
           bigint a(truehalf + (char)(48+i) + invhalf);
           answer.push_back(a*a);    
       //    cout << a << endl;
       }
       bigint a(truehalf + invhalf);
       answer.push_back(a*a);    
       //           cout << a << endl;
       return;
}

void half_palin(int goal, char num, int depth)
{
       if (depth == goal)
       {
          string temp = half;
          for (int j = half.length() ; j < LEN ; j++)
              half += "0";
          addPalin(half);          
          half = temp;
          return;
       }
       for (int i = half.length() ; i < LEN ; i++)
       {
           string temp = half;
           for (int j = half.length() ; j < i ; j++)
               half += "0";
           half += num;               
           half_palin(goal, num, depth+1);          
           half = temp;
       }
       
}


int main()
{
//   ifstream fin("C-small-attempt0.in");
//   ofstream fout("C-small-attempt0.out");
    ifstream fin("C-large-1.in");
    ofstream fout("C-large-1.out");    
  
        
    answer.push_back(bigint("1"));
    answer.push_back(bigint("4"));
    answer.push_back(bigint("9"));        
    
    
    // two 2 + (middle -- one 1, null)
    middle = 1;
    half_palin(1,'2', 0);
  
  cout << "Done!" << endl;
    // two 1 + (middle -- one 2 , one 1, null)
    middle = 2; half = "";
    half_palin(1,'1', 0);    
  cout << "Done!" << endl;    
    // four 1 + (middle -- one 2 , one 1, null)
    middle = 2; half = "";
    half_palin(2,'1', 0);    
  cout << "Done!" << endl;    
    // six 1 + (middle -- one 1, null)
    middle = 1; half = "";
    half_palin(3,'1', 0);    
  cout << "Done!" << endl; 
    // eight 1 + (middle -- one 1, null) 
    middle = 1; half = "";
    half_palin(4,'1', 0);    
  cout << "Done!" << endl;  
  
  cout << answer.size() << endl;
    sort(answer.begin(), answer.end());
  cout << "Done!" << endl;
      
    int T; fin >> T;
    string N, M;
    
    for (int t = 1 ; t <= T; t++)
    {  
       
		fin >> N >> M;
		bigint bN(N);
		bigint bM(M);
		
		int ans = 0;
		for (int i = 0 ; i < answer.size(); i++)
		{
		    if (answer[i] >= bN && answer[i] <= bM)
		       ans++;
            else if (answer[i] > bM)
               break;
         }
		fout << "Case #" << t << ": ";
        fout << ans << endl;
    }
}


