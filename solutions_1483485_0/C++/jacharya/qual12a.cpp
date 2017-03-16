#include<iostream>
#include<string>


using namespace std;

int main(){
  long  j, k, i, l,m, A, B;
  long lay, num, C,N, T, S, p, score;
  string name;
  char mapp[26];
  mapp[0]='y';//a
  mapp[1]='h';
  mapp[2]='e';
  mapp[3]='s';
  mapp[4]='o';//e
  mapp[5]='c';
  mapp[6]='v';
  mapp[7]='x';
  mapp[8]='d';
  mapp[9]='u';//j
  mapp[10]='i';
  mapp[11]='g';
  mapp[12]='l';
  mapp[13]='b';
  mapp[14]='k';
  mapp[15]='r';// p
  mapp[16]='z'; //come back here
  mapp[17]='t';//r
  mapp[18]='n';//s
  mapp[19]='w';//t
  mapp[20]='j';//u
  mapp[21]='p';//v
  mapp[22]='f';//w
  mapp[23]='m';//x
  mapp[24]='a';//y
  mapp[25]='q';//z
  cin >> T;
  getline(cin,name);
  name.clear();
  j=0;
  for(i=0;i<T;i++){
    cout<<"Case #"<<i+1<<": ";
    getline (cin, name);
    j=0;
   for (j = 0; j <name.length();j++)
    {
      if (name[j]==' ')
	cout<<" ";
      else
      {
	k = name[j]-'a';
	cout<<mapp[k];
      }
    }
    cout<<"\n";
    name.clear();
  }
  return 0;
}