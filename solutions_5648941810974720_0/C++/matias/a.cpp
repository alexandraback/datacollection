#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

int main(){
  int T;
  cin>>T;
  for (int t=1;t<=T;t++){
    string S;
    cin>>S;
    map<char,int> M;
    for (int i=0;i<26;i++){
      M['A'+i]=0;
    }
    for (int s=0;s<S.length();s++){
      M[S[s]] = M[S[s]] + 1;
    }
    vector<int> freq(10,0);
    freq[0]=M['Z'];
    M['Z'] = 0;
    M['E'] = M['E']-freq[0];
    M['R'] = M['R']-freq[0];
    M['O'] = M['O']-freq[0];
    freq[2]=M['W'];
    M['T'] = M['T']-freq[2];
    M['W'] = M['W']-freq[2];
    M['O'] = M['O']-freq[2];
    freq[4]=M['U'];
    M['F'] = M['F']-freq[4];
    M['O'] = M['O']-freq[4];
    M['U'] = M['U']-freq[4];
    M['R'] = M['R']-freq[4];
    freq[6]=M['X'];
    M['S'] = M['S']-freq[6];
    M['I'] = M['I']-freq[6];
    M['X'] = M['X']-freq[6];
    freq[5]=M['F'];
    M['F'] = M['F']-freq[5];
    M['I'] = M['I']-freq[5];
    M['V'] = M['V']-freq[5];
    M['E'] = M['E']-freq[5];
    freq[8]=M['G'];
    M['E'] = M['E']-freq[8];
    M['I'] = M['I']-freq[8];
    M['G'] = M['G']-freq[8];
    M['H'] = M['H']-freq[8];
    M['T'] = M['T']-freq[8];
    freq[3]=M['H'];
    M['T'] = M['T']-freq[3];
    M['H'] = M['H']-freq[3];
    M['R'] = M['R']-freq[3];
    M['E'] = M['E']-freq[3]-freq[3];
    freq[1]=M['O'];
    M['O'] = M['O']-freq[1];
    M['N'] = M['N']-freq[1];
    M['E'] = M['E']-freq[1];
    freq[7]=M['V'];
    freq[9]=M['I'];
    cout<<"Case #"<<t<<": ";
    string res;
    for (int i=0;i<10;i++) {
      for (int j=0;j<freq[i];j++){
	res+='0'+i;
      }
    }
    cout<<res<<endl;
  }
}
