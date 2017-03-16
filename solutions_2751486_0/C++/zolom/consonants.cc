#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

void addcons(vector<int> &consonants, int &consonantcount, int pos, int n){
  consonants[consonantcount%n]=pos;
  consonantcount++;
}

int main(int argc, char**argv){
  int T;
  cin>>T;
  for(int i=1; i<=T; i++){
    cout<<"Case #"<<i<<": ";
    string name;
    int n;
    cin>>name>>n;
    vector<int> consonants(n, -1);
    int consonantcount = 0;
    int lastconsec = -1;
    int nrank=0;
    for(int p=0; p<name.length(); p++){
      if(name[p]!='a'&&name[p]!='e'&&name[p]!='i'&&name[p]!='o'&&name[p]!='u')
	{
	  //addcons(consonants, consonantcount, p, n);
	  consonantcount++;
	  if(consonantcount>=n)
	    lastconsec=p-n+1;
	}
      else
	{
	  consonantcount=0;
	}
      nrank+=lastconsec+1;
      //      printf("lastconsec %d consonantcount %d\n", lastconsec, consonantcount); 
    }
    cout<<nrank<<endl;
  }
}
