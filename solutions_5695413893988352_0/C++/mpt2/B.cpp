#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <sstream>
#include <stack>
#include <queue>
#include <map>
#include <climits>
#include <cstdio>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
using namespace std;
#define db(a) (cout << (#a) << " = " << (a) << endl)
typedef long long ll;

int main()
{
  ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
  	
  int T;
  cin>>T;
  for(int tt=0;tt<T;tt++)
  {
  	string Cin,Jin;
  	cin>>Cin>>Jin;

		string C = Cin;
		string J = Jin;


  	int state = 0; //0=equal, 1=Cbigger
  	bool swapped = false;
  	ll changed = -1;
  	ll erg1 = 0;
  	ll erg2 = 0;
  	ll Cv1 = 0;
  	ll Cv2 = 0;
  	ll Jv1 = 0;
  	ll Jv2 = 0;
  	for(size_t i=0;i<C.size();i++)
  	{
	  	if(C[i] == J[i] && J[i] == '?')
	  	{
	  		if(state == 0) C[i] = J[i] = '0';	
	  		else if(state == 1) 
	  		{
	  			C[i] = '0';
	  			J[i] = '9';
	  		}
  			else
  			{
  				C[i] = '9';
  				J[i] = '0';
  			}
  	}
  	else if(C[i] == '?')
  	{
  		if(state == 0)
  		{
  			C[i] = J[i];
  		}
  		else if(state == 1)
  		{
  			C[i] = '0';
  		}
  		else C[i] = '9';
  	}
  	else if(J[i] == '?')
  	{
  		if(state == 0)
  		{
  			J[i] = C[i];
  		}
  		else if(state == 1)
  		{
  			J[i] = '0';
  		}
  		else J[i] = '9';
  	}
  	else if(state == 0)
  	{
  		if(C[i] > J[i]) state = 1;
  		else if(C[i] < J[i]) state = 2;
if(C[i]!=J[i])changed = i;  		
  	}
  	erg1 = erg1*10 + (C[i]-J[i]);
  	Cv1 = Cv1*10 + C[i]-'0';
  	Jv1 = Jv1*10 + J[i]-'0';
	}  	
	
	string C2,J2;
	if(state == 0) erg2=INT_MAX;
	else if(state == 2)
	{
		C2 = Jin; J2 = Cin;
		swapped = true;
	}
	else { C2= Cin; J2=Jin;}
				if(state != 0)
				{//try J > C
				state = 0;
				changed--;
				while(changed>=0)
				{
				if(C2[changed]=='?' && J2[changed] != '0') 
				{
					if(J2[changed] == '?'){J2[changed]='1'; C2[changed]='0';}
					else C2[changed] = J2[changed]-1;
					break;
				}
     else	if(J2[changed]=='?' && C2[changed] != '9')
     {
     	J2[changed] = C2[changed]+1;
     	break;
     }
				changed--;
				}

				
				
				
				for(size_t i=0;i<C2.size();i++)
  	{
  	//db(changed);
  					if(changed == -1) {erg2=INT_MAX;break;}
	  	if(C2[i] == J2[i] && J2[i] == '?')
	  	{
	  		if(state == 0) C2[i] = J2[i] = '0';	
	  		else if(state == 1) 
	  		{
	  			C2[i] = '0';
	  			J2[i] = '9';
	  		}
  			else
  			{
  				C2[i] = '9';
  				J2[i] = '0';
  			}
  	}
  	else if(C2[i] == '?')
  	{
  		if(state == 0)
  		{
  			C2[i] = J[i];
  		}
  		else if(state == 1)
  		{
  			C2[i] = '0';
  		}
  		else C2[i] = '9';
  	}
  	else if(J2[i] == '?')
  	{
  		if(state == 0)
  		{
  			J2[i] = C2[i];
  		}
  		else if(state == 1)
  		{
  			J2[i] = '0';
  		}
  		else J2[i] = '9';
  	}
  	else if(state == 0)
  	{
  		if(C2[i] > J2[i]) state = 1;
  		else if(C2[i] < J2[i]) state = 2;
  	}
  	erg2 = erg2*10 + (C2[i]-J2[i]);
  	Cv2 = Cv2*10 + C2[i] - '0';
  	Jv2 = Jv2*10 + J2[i] - '0';
	}  	
		
				}
		
		if(swapped) {swap(C2,J2);swap(Cv2,Jv2);}
	//db(erg1);db(erg2);	
		if(abs(erg1) < abs(erg2) || changed==-1 || (abs(erg1) == abs(erg2) && (Cv1<Cv2 || (Cv1==Cv2 && Jv1<=Jv2)))) cout << "Case #" << tt+1 << ": " << C << " " << J << "\n";
		else cout << "Case #" << tt+1 << ": " << C2 << " " << J2 << "\n";		
  }
  return 0;
}

