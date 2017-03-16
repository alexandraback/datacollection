#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <cctype>
#include <algorithm>
#include <set>
#include <iomanip>
#include <map>
#include <vector>

void parseLine(int, const std::string& line, std::ifstream& stream);

int main(int argc, char **argv) {
  std::ifstream stream("test.txt");

  if( stream ) {
      char buf[255];
      stream.getline(buf, 255);
      std::stringstream numberStream(buf);
      int testCaseCount = 0;
      numberStream >> testCaseCount;
      int count = 1;
      while( !stream.eof()  && count <= testCaseCount ) {
	  stream.getline(buf, 255);
	  parseLine(count, buf, stream);
	  count++;
      }
  }

  return 0;
}

class node{
public:
  node(){
    visited = false;
  }
  
  void addChild(node* n){
    if(childs.find(n) == childs.end() ){
      childs.insert(n);
    }
  }
  
  void visit(bool& hasDiamond){
    visited = true;
    std::set<node*>::iterator i;
    for( i = childs.begin(); i != childs.end(); i++ ){
      if( !((*i)->isVisited()) ){
	(*i)->visit(hasDiamond);
      }else{
	hasDiamond = true;
      }
    }
  }
  
  void reset(){
    visited = false;
  }
  
  bool isVisited(){
    return visited;
  }
private:
  std::set<node*> childs;
  bool visited;
};

void parseLine(int testCaseNumber, const std::string& line, std::ifstream& stream) {
    std::stringstream lineStream(line);
    int classesCount = 0;
    lineStream >> classesCount;
    std::map<int, std::set<int> > classes;
    std::vector< node* > nodes;
    for( int i = 1; i<= classesCount; i++ ){
	char buffer[1024] = {0};
	stream.getline(buffer, 255);
	std::stringstream classStream(buffer);
	int inheritsNumber = 0;
	classStream >> inheritsNumber;
	classes.insert(std::make_pair(i, std::set<int>()));
	for( int j = 0; j<inheritsNumber; j++ ){
	  int classId = 0;
	  classStream >> classId;
	  classes[i].insert(classId);
	}
	
	nodes.push_back(new node());
    }
    
    std::map<int, std::set<int> >::iterator it;
    for( it = classes.begin(); it != classes.end(); it++ ){
      std::set<int>::iterator inhIter;
      for( inhIter = it->second.begin(); inhIter != it->second.end(); inhIter++ ){
	node* n= nodes[*inhIter-1];
	nodes[it->first-1]->addChild(n);
      }
    }
    
    std::vector<node*>::iterator nodesIterator;
    std::vector<node*> tmp = nodes;
    bool hasDiamond = false;
    for( nodesIterator = nodes.begin(); nodesIterator != nodes.end(); nodesIterator ++ ){
      (*nodesIterator)->visit(hasDiamond);
      std::vector<node*>::iterator tmpIt;
      for( tmpIt = tmp.begin(); tmpIt != tmp.end(); tmpIt++){
	(*tmpIt)->reset();
      }
    }
    
    for( nodesIterator = nodes.begin(); nodesIterator != nodes.end(); nodesIterator ++ ){
      delete *nodesIterator;
    }
    
    if( hasDiamond ){
      std::cout << "Case #" << testCaseNumber <<": Yes"<<std::endl;
    }else{
      std::cout << "Case #" << testCaseNumber <<": No"<<std::endl;
    }
}

