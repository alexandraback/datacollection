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
    for(int n = 0; n < N; n++){
      unsigned int E,R,I;
      unsigned int result = 0;
      vector<unsigned int> v;
      vector< map<unsigned int, unsigned int> >matrix;
      ptr>>E>>R>>I;
      v.resize(I);
      for(int i = 0; i < I; i++)
	ptr>>v[i];
      if(R >= E)
	for(int i = 0; i < I; i++)
	  result += v[i]*E;
      else{
	result = 0;
	matrix.resize(I);
	for(unsigned int g = R; g <= E; g++)
	  matrix[I-1][g] = g*v[I-1];
	for(int i = I - 2; i >= 0; i--)
	  for(unsigned int g = R; g <= E; g++){
	    matrix[i][g] = 0;
	    for(unsigned int used = 0; used <= g; used++){
	      unsigned int forwarded = g - used + R;
	      if(forwarded > E)
		forwarded = E;
	      unsigned temp_gain = v[i]*used + matrix[i+1][forwarded];
	      if(temp_gain > matrix[i][g])
		matrix[i][g] = temp_gain;
	    }
	  }
	result = matrix[0][E];
      }
      stringstream str;      
      str<<result;
      cout<<"\n"<<str.str();
      file_write(optr,n+1,str.str());
    }
  }
  return 0;
}
