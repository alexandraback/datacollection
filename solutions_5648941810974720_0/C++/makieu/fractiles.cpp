#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;


int main(){
	int nb;
	cin >>nb;
	for(int cases=0; cases<nb; cases++){
    cout << "Case #"<<cases+1<<": ";
    string s;
    cin>> s;
    vector<int> occ(1000,0);
    for(int i=0;i<s.size();i++)
      occ[s[i]]++;
    vector<int> number(10,0);
    number[0]=occ['Z'];
    number[2]=occ['W'];
    number[4]=occ['U'];
    number[1]=occ['O']-number[4]-number[2]-number[0];
    number[3]=occ['R']-number[4]-number[0];
    number[5]=occ['F']-number[4];
    number[6]=occ['X'];
    number[7]=occ['V']-number[5];
    number[8]=occ['H']-number[3];
    number[9]=occ['I']-number[8]-number[6]-number[5];
    for(int i=0;i<10;i++)
      for(int j=0;j<number[i];j++)cout<< i;
      cout<<endl;
  }
	return 0;
}
