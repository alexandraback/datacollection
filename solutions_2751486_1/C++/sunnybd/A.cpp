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
    
	in>>name>>n;

    // find consecutive consonants
    vector <int> start;
    int run=0;
    for (int i=0;i<name.size();i++){
        if (name[i]=='a' || name[i]=='e' || name[i]=='o' || name[i]=='u' || name[i]=='i'){
			run=0;
		}
		else{
			run=run+1;
			if (run>=n)
				start.push_back(i-n+1);
		}    
    }  
    
    
    // calculate possibilities
    long long int ans=0;
	long int idx=0;
	int done=0;
    int min_st;
    if (start.size()>=1)
	   min_st=start[idx];
    else done=1;
    
    for (int i=0;i<name.size();i++){
        if (done==1)
           break;
        while (min_st<i){
              if (idx>=start.size()-1)
                 break;
              idx+=1;
              min_st=start[idx];                        
        }
        
        int end = min_st+n-1;
        int npe;
        if (end<name.size() && end-i+1>=n)
           npe=name.size()-end;
        else npe=0;
        //cout<<npe<<endl;
        ans+=npe;                       
    }
	
	out<<"Case #"<<t<<": ";
    //for (int i=0;i<start.size();i++)
	  //  cout<<start[i]<<" ";
    //cout<<endl; 
	out<<ans<<endl;  
    //getch ();      
}   
getch ();       
}
