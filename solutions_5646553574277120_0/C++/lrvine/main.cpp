#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

#define fori(i,n)   for( int i=0 ; i< n ; i++ )

vector<int> ary;

bool find( int target , int current, int index ){
     if( current == target)
        return true;
     if( current > target)
        return false;
     if( index >= int(ary.size()))
        return false;
//     cout<<" find "<<target<<" "<<current<<" "<<index<<endl;
     return ( find( target, (current + ary[index]), index+1 )||find( target, current, index+1 ) );
}


int main( int argc, char** argv){


ofstream output;
ifstream input;
//cout<< " start "<<endl;
input.open(argv[1]);
output.open("ans.txt");


if(input.fail()){
  cout<<" error opening file"<<endl;
  return -1;
}


int cases;
input >> cases;

int c;
int d;
int v;
int ans;
int buf;
for(int k=0; k<cases ; k++){

input >> c;
input >> d;
input >> v;
ans=0;
ary.clear();
for(int i=0; i<d ; i++){
   input >> buf;
   ary.push_back(buf);
}


for(int i=1; i<=v ; i++){
    
  if( !find(i,0,0) ){
      cout<<"fail to find "<<i<<endl;
      ary.push_back(i);
      ans++;
  }
   
}


output<<"Case #"<<k+1<<": "<<ans<<endl;  
cout<<"Case #"<<k+1<<": "<<ans<<endl;  

}

input.close();
output.close();
return 0;
}

