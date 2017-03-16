#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

#define fori(i,n)   for( int i=0 ; i< n ; i++ )

int main( int argc, char** argv){


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

int n;

int *ary;

ary = new int[1000010];

string ss;
ary[0]=0;
ary[1]=1;
int temp;
for( int i= 2; i<=1000000 ; i++){
  
  ss = to_string(i);
  reverse( ss.begin(), ss.end() );
  temp= stoi(ss) ;
//  cout<<i<<" "<<temp<<endl;
  if( (temp > i )|| (temp==i) || ( i%10==0 ) )
    ary[i]=ary[i-1]+1;
  else
    ary[i]=min((ary[i-1]+1),(ary[temp]+1));
}
/*
for( int i= 0; i<=100 ; i++){
  cout<<ary[i]<<" ";
}
cout<<endl;
*/
for(int k=0; k<cases ; k++){
    input >> n;

output<<"Case #"<<k+1<<": "<<ary[n]<<endl;  
cout<<"Case #"<<k+1<<": "<<ary[n]<<endl;  

}

input.close();
output.close();
return 0;
}

