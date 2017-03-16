#include <fstream>
#include <map>
#include <vector>
#include <utility>
#include <queue>


using namespace std;

typedef pair<string, string> ss;
typedef map<ss, int> rn;
typedef vector<string> vs;
typedef map<string, vs> graph;

//Solution: minimum edge cover of bipartite graph

int main(int argc, char* argv[]){
  ifstream in(argv[1]);
  ofstream out("tecnho.out");
  int T, L;
  string fst, snd;
  in >> T;
  //initialize
  for(int C=1; C<=T; C++){
    in >> L;
    rn resid;
    graph gr;
    gr["0"]=vs();
    gr["1"]=vs();
    for(int i=0; i<L; i++){
      in >> fst >> snd;
      if(gr.find("0"+fst) == gr.end()){
        gr["0"+fst] = vs();
        resid[ ss("0", "0"+fst) ] = 1;
        gr["0"].push_back("0"+fst);
        gr["0"+fst].push_back("0");
      }
      if(gr.find("1"+snd) == gr.end()){
        gr["1"+snd] = vs();
        resid[ss("1"+snd, "1")] = 1;
        gr["1"].push_back("1"+snd);
        gr["1"+snd].push_back("1");
      }
      gr["1"+snd].push_back("0"+fst);
      gr["0"+fst].push_back("1"+snd);
      resid[ ss("0"+fst, "1"+snd) ] = 1;
    }

    //Ford-Fulkerson
    while(true){
      //BFS
      queue<string> Q;
      map<string, bool> visited;
      map<string, string> prev;
      Q.push("0");
      visited["0"]=true;
      while(!Q.empty()){
        string cur = Q.front();
        Q.pop();
        if(resid.find(ss(cur, "1")) != resid.end()){
          prev["1"]=cur;
          visited["1"]=true;
          break;
        } else{
          for(vs::iterator it = gr[cur].begin(); it != gr[cur].end(); ++it){
            if(resid.find(ss(cur,*it)) != resid.end() && visited.find(*it) == visited.end()){
              visited[*it]=true;
              prev[*it] = cur;
              Q.push(*it);
            }
          }
        }
      }

      //update
      if(visited.find("1") != visited.end()){
        string cur = "1";
        while(cur != "0"){
          string prv = prev[cur];
          if(resid.find(ss(cur,prv)) != resid.end() ){
            resid[ss(prv,cur)] = 1;
            resid.erase(resid.find(ss(cur,prv)));
          } else{
            resid[ss(cur,prv)] = 1;
            resid.erase(resid.find(ss(prv,cur)));
          }
          cur = prv;
        }
      } else{
        break;
      }
    }

    int count = 0;

    for(graph::iterator it = gr.begin(); it != gr.end(); ++it){
      if(resid.find(ss("1", it->first)) != resid.end()){ // if there is backflow to end
        count++;
      }
      if(resid.find(ss(it->first, "1")) != resid.end() || resid.find(ss("0", it->first)) != resid.end()){ //unmatched
        count++;
      }
    }

    out << "Case #" << C << ": " << L - count << endl;
  }
}
