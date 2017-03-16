#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

#define fori(i,n)   for( long long i=0 ; i< n ; i++ )

int  main( int argc, char** argv){


ofstream output;
ifstream input;
cout<< " start "<<endl;
input.open(argv[1]);
output.open("ans.txt");

if(input.fail()){
  cout<<" error opening file"<<endl;
  return -1;
}

int cases;
input >> cases;

int R;
int C;
int W;


int ans;
for( int k=0; k<cases ; k++){
input >> R;
input >> C;
input >> W;
    ans = (R*C-1)/W + W;


output<<"Case #"<<k+1<<": "<<ans<<endl;  
cout<<"Case #"<<k+1<<": "<<ans<<endl;  

}

input.close();
output.close();
return 0;
}

