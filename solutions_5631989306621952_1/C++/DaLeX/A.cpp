#include <iostream>
#include <fstream>
#include <strings.h>
using namespace std;
const int MID=1024;

int main()
{
    long i, b, e, m, t, l;
    char s[MID],sw[2*MID];
   // fstream infile("test.in");
 //   fstream infile("A-small-attempt0.in");
    fstream infile("A-large.in");
  //  ofstream outfile("test.out");
//    ofstream outfile("A-small.out");
    ofstream outfile("A-large.out");
    infile >> t;
    cout<<t<<endl;
    for (m=1; m<=t; ++m){
        infile >> s;
        cout<<s<<endl;
        l=strlen(s);
        b=MID;
        e=MID;
        sw[b]=s[0];
		for(i=1;i<l;i++)
			if(s[i]>=sw[b]){
				b--;
				sw[b]=s[i];
			}
			else{
				e++;
				sw[e]=s[i];
			}
	    outfile << "Case #"<<m<<": ";
   		cout << "Case #"<<m<<": "; 
		for(i=b;i<=e;i++){		
		    outfile << sw[i];
   			cout << sw[i]; 
   	}
	    outfile << endl;
   		cout << endl; 
    }
    infile.close();
    outfile.close();
}
