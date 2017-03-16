#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int NUM_PATH;

void find_path(vector<vector< int > > & m, int start, int end){
  //cout << "entradno" << endl;
  /*   for(int j=0;j<m.size();j++){
    for(int k=0;k<m.size();k++)
      cout << m[j][k];
    cout << endl;
  }
  */
  if(start==end){
    NUM_PATH++;
  }
  else{
    for(int i=0;i<m.size();i++){
      // cout << start << "exploarando " << i << " " << m[start][i]<< endl;
      if(m[start][i]!=0){
	//cout << "dsentro" << endl;
	find_path(m,i,end);
      }
    }
  }
}

int main(int argc, char ** argv){

  int T;
  ifstream fi;
  fi.open(argv[1]);
  fi >> T;
  for(int i=0;i<T;i++){
    int M;
    fi >> M;
    vector<vector< int > > m(M,vector<int>(M));   
    
    /* m.resize(M);
    for(int k=0;k<M;k++){
      m[k].resize(M);
    */
       for(int k=0;k<M;k++){
    //   m[k].clear();
    //  m[k].resize(M);
      for(int l=0;l<M;l++)
	m[k][l] = 0;
      // }
          }
    

    for(int j=0;j<M;j++){
      int max_line;
      fi >> max_line;
      int val;
      for(int k=0;k<max_line;k++){
	fi >> val;
	m[j][val-1]=1;
      }
    }


    /*for(int j=0;j<M;j++){
      for(int k=0;k<M;k++)
	cout << m[j][k];
      cout << endl;
      }
    */
    
    vector<int> source;
    source.clear();
    //    for(int j=0;j<M;j++)
    //source.push_back(j);
    
    for(int j=0;j<M;j++){
      int count =0;
      for(int k=0;k<M;k++)
	if(m[j][k]!=0)
	  count++;
      if(count>=2)
	source.push_back(j);
	}
    /*      cout << "souirce size " << source.size() << endl;
    for(int j=0;j<source.size();j++)
     cout << source[j] << endl;
    */


    vector<int> target;
    target.clear();

    //    for(int j=0;j<M;j++)
    // target.push_back( j);
    for(int j=0;j<M;j++){
      int count =0;
      for(int k=0;k<M;k++)
        if(m[k][j]!=0)
          count++;
      if(count>=2)
        target.push_back(j);
    }
    
    /*cout << "t size " << target.size() << endl;
    for(int j=0;j<target.size();j++)
      cout << target[j] << endl;
    
    */
    //cout << "si" << endl;

    //-----------------------------------
string result="No";
 bool salir=false;
    for(int j=0;j<source.size() && !salir;j++)
      for(int k=0;k<target.size() && !salir;k++){
	if(source[j]!=target[k]){
	  NUM_PATH = 0 ;	  
	  find_path(m,source[j],target[k]);
	  
	  if(NUM_PATH>=2){
	    result = "Yes";
	    salir = true;
	  }
	 
	}

      }

    
    
    
    cout << "Case #" << i+1 << ": " << result << endl;
	

    
  }
}
