#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <conio.h>

using namespace std;


int n;
string name;
	
int consecutive (int st, int end)
{
	int run=0;
	for (int i=st;i<=end;i++){
		if (name[i]=='a' || name[i]=='e' || name[i]=='o' || name[i]=='u' || name[i]=='i'){
			run=0;
		}
		else{
			run=run+1;
			if (run==n)
				return 1;
		}
	}
		
	return 0;
}


int main ()

{
ofstream out;
out.open ("A_output.txt");
ifstream in;
in.open ("A_input.txt");
    
    
int nt;
in>>nt;
for (int t=1;t<=nt;t++){
    
	int ans=0;
    in>>name>>n;

	for (int i=0;i<name.size();i++){
		for (int j=i;j<name.size();j++){
			if (consecutive(i,j)==1)
				ans+=1;
		}
	}
    
	
	
	
	
	out<<"Case #"<<t<<": ";
    out<<ans<<endl;        
}   
getch ();       
}
