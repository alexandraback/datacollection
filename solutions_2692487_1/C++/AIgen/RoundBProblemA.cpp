#include<iostream>
#include<algorithm>
using namespace std;

#include<fstream>
#define cin fin
#define cout fout
ifstream fin ("A-large.in");
ofstream fout ("out.txt");

int main (){
  int t;
  int n;
  int my_moat;
  int arr[ 1000];

  cin>>t;
  for (int i=1;i<=t;++i){

    cin>>my_moat;
    cin>>n;
    for (int j=0;j<n;++j){
      cin>>arr[j];
    }
    sort (arr, arr + n);
    int cur = 0;
    while ((cur < n) && (arr[cur] < my_moat)){
      my_moat+=arr[cur++];
    }

    int moves =  n-cur;
    int add_moves = 0;
    while (cur < n){
      if (arr[cur] < my_moat){
	my_moat+=arr[cur++];
      }
      else {
	my_moat = (2*my_moat) - 1;
	if (my_moat == 1)break;
	add_moves++;
      }
      if ((add_moves + (n-cur)) < moves)moves = (add_moves + (n-cur));
      else;
    }
    cout<<"Case #"<<i<<": "<<moves<<"\n";
  }
  return 0;
}
