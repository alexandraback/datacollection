#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<sstream>
#include<set>
#include<math.h>

using namespace std;

bool isFinish;
string line,result;
vector<string> dict; 
map<string, double> weight;
int iT;
map<char,char> m_result; 
set<char> ontoset_result;

bool myfunction (string a, string b){
  return a.size()<b.size(); 
}

bool myfun (string a, string b){
  return weight[a]<weight[b];
}

bool check(string word, string test,const map<char,char> & m, map<char,char> & newmap,set<char>& newontoset){
  newmap= m;
  char c; 
  for (int i=0;i<word.size();i++){
    c=word[i];
    if (newmap.find(c)!=newmap.end()){
      if (newmap[c]!=test[i]) return false;
    }
    else {
      if (newontoset.find(test[i])!=newontoset.end()) return false;
      newmap[c]=test[i];
      newontoset.insert(test[i]);
    }
  }
  return true;
}

void output(map<char, char> m, set<char>ontoset){
  
  result=line;
  for (int i=0;i<line.size();i++){
    if (line[i]==' ') result[i]=' ';
    else result[i]=m[ line[i]];
  }

  cout<<"Case #"<<iT<<": "<<result<<endl;
  cout.flush();

  m_result=m;
  ontoset_result=ontoset;
}

void dfs(const vector<string> & words, int dep , map<char, char> m, set<char> ontoset){
  if ( dep==words.size() ) {
    output(m, ontoset);
    isFinish=true;
    return;
  }

  string word= words[dep];
  
  pair<vector<string>::iterator,vector<string>::iterator> bounds;
  bounds=equal_range (dict.begin(), dict.end(), word ,myfunction); 
  vector<string>::iterator it;
  for (it= bounds.first ; it!=bounds.second;it++){
    string candidate= *it;
    map<char ,char> newmap ;
    set<char> newontoset = ontoset;
    if (check(word, candidate, m, newmap,newontoset)){
      dfs( words, dep+1, newmap, newontoset); 
    }
  }
}

bool unknown(string word, map<char,char>m){
  for (int i=0;i<word.size();i++)
    if ( m.find(word[i])==m.end()) return true;
  return false;
}

int main(){

m_result['a']='y';
m_result['b']='h';
m_result['c']='e';
m_result['d']='s';
m_result['e']='o';
m_result['f']='c';
m_result['g']='v';
m_result['h']='x';
m_result['i']='d';
m_result['j']='u';
m_result['k']='i';
m_result['l']='g';
m_result['m']='l';
m_result['n']='b';
m_result['o']='k';
m_result['p']='r';
m_result['q']='z';
m_result['r']='t';
m_result['s']='n';
m_result['t']='w';
m_result['u']='j';
m_result['v']='p';
m_result['w']='f';
m_result['x']='m';
m_result['y']='a';
m_result['z']='q';

  fstream fi;
  fi.open("corncob_lowercase.txt",fstream::in);
  string word; 
 
  while (fi>>word) dict.push_back(word);
  fi.close();
  
  dict.push_back("google");
  sort(dict.begin(),dict.end(),myfunction);


  freopen("test.in","r",stdin);
  int T;
  cin>>T; 
  getline(cin,line);

   map<char,char> m; 
   set<char> ontoset;

  for (iT=1;iT<=T;iT++){
    getline(cin,line);
    
    stringstream ss; 
    ss<<line; 
    

      vector<string> words;
    string word;
    while( ss>>word){ 
      if (unknown(word, m))
	words.push_back(word);
    }


    map<char,int> freq; 
    for (char i ='a'; i<='z';i++) freq[i]=0;
    for (int i=0;i<words.size();i++) for (int j=0;j<words[i].size();j++) freq[words[i][j]]++;

    for (int i=0;i<words.size();i++){
      string word=words[i];
      if (weight.find(word)==weight.end()) weight[word]=0.;

      for (int j=0;j<word.size();j++)
	weight[word]+= pow(freq[word[j]]+1,3);
    }

    sort(words.begin(),words.end(),myfun);
    reverse(words.begin(),words.end());  
    
    isFinish=false;

    m=m_result;
    ontoset=ontoset_result;
    dfs( words, 0, m,ontoset);

    if (!isFinish) cout<<"Case #"<<iT<<": Error!"<<endl;
    cout.flush();
  }

 return  0 ; 

}
