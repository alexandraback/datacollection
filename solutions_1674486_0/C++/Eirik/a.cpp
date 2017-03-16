#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <queue>
using namespace std;

int main (){
	ofstream out;
	out.open("out");	

	int T, N, M, tmp;
  bool dia;
	cin >> T;
	
	for(int i=0; i<T; ++i){
//    cout << "Case #" << i << endl;
    vector< vector<int> > nabo;
    cin >> N;
    for(int j=0; j<N; ++j){
      cin >> M;
      vector<int> liste(M);
      nabo.push_back(liste);
      for(int k=0; k<M; ++k){
        cin >> nabo[j][k];
      }
    }
    
    
    dia = false;
    for(int j=0; j<N; ++j){
      tmp = j;
//      cout << "Start" << tmp << endl;
      bool besokt[1000] = {0};
      queue<int> ko;
      for(int k=0; k<nabo[tmp].size(); ++k){
        ko.push(nabo[tmp][k]-1);
      }

      while(!ko.empty()){
//        cout << endl << "besokt";
//        for(int k=0; k<N; ++k)
//          cout << besokt[k] << " ";
//        cout << endl << ko.front() << endl;
        

        tmp = ko.front();
        ko.pop();
        if(besokt[tmp]){
          dia = true;
          break;
        }  
        besokt[tmp] = true;
        for(int k=0; k<nabo[tmp].size(); ++k){
          ko.push(nabo[tmp][k]-1);
        }
      }
      if(dia) break;
    }

		out << "Case #" << i+1 << ": " << (dia ? "Yes" : "No") << endl;
//    cout << endl;
	} 
	
	out.close();
}

 
