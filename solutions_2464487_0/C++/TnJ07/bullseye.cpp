#include "common.h"
#include "math.h"

int main(int argc, char** argv){  
  string infile;
  string outfile;
  ifstream ptr;
  ofstream optr;
  get_file_names(outfile,infile,argc,argv);
  int N;
  if(N = file_read(ptr,infile.c_str())){
    string test;
    optr.open(outfile.c_str());
    for(int i = 0; i < N; i++){
      unsigned long a,S;
      ptr>>a>>S;
      unsigned long success = 0;
      unsigned long n;
      n = sqrt((S-2*a)/2);
      while(success == 0 && n >= 1){
	unsigned long temp_S = 2*n - 1 + 2*a;    
	unsigned long massage_S = S/n;
	if(temp_S <= massage_S)
	  success = 1;
	else
	  n--;
      }
      int temp_n = n+1;
      unsigned long massage_S = S + 1;
      if(massage_S > 2*a*temp_n){
	massage_S = massage_S - 2*a*temp_n;
	unsigned long temp_S = 2*temp_n*temp_n;
	cout<<"\nTushar"<<temp_S<<" "<<massage_S;
	if(temp_S <= massage_S)
	  n = temp_n;
      }
      stringstream str;
      str<<n;
      cout<<"\n"<<a<<" "<<S<<" "<<str.str();
      file_write(optr,i+1,str.str());
    }
  }
  return 0;
}
