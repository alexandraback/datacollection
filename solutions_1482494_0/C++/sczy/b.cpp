#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
using namespace std;

vector<pair<int,int> > level;
int best ,N; 

bool first (int i, int j){
  return level[i].first<level[j].first;
}


void dfs( int cur, int star, set<int> & done,  set<int> & half, set<int> & left){

   set<int>::iterator it;
   /*
   cout<<"cur "<<cur<<" star "<<star<<endl;
   cout<<"done :";
  for ( it=done.begin();it!=done.end();it++) cout<<" "<<*it<<" ";
  cout<<endl;
   cout<<"half :";
  for ( it=half.begin();it!=half.end();it++) cout<<" "<<*it<<" ";
  cout<<endl;
   cout<<"left :";
  for ( it=left.begin();it!=left.end();it++) cout<<" "<<*it<<" ";
  cout<<endl;
  cout.flush();
   */
  if ( best!=-1 && cur + half.size() + left.size() > best) return; 
  

  set<int> tag; 
  bool isupdated= false;

  do{
    isupdated=false;
    for (it=left.begin();it!=left.end();it++){
      int a= *it;
      if ( level[a].second<=star){
	tag.insert(a);
	star+=2;
	cur++;
	isupdated=true;
	//	cout<<" left l2 "<<a<<endl;
      }
    }

    for (it=tag.begin();it!=tag.end();it++){
      int a=*it;
      left.erase(a);
      done.insert(a);
    }
    tag.clear();

    for (it=half.begin();it!=half.end();it++){
      int a= *it;
      if ( level[a].second<=star){
	tag.insert(a);
	star++;
	cur++;
	isupdated=true;
	//	cout<<" half l2 "<<a<<endl;
      }
    }

    for (it=tag.begin();it!=tag.end();it++){
      int a=*it;
      half.erase(a);
      done.insert(a);
    }
    tag.clear();

  }while( isupdated);


  
  if ( half.empty() && left.empty()) {
    if ( best== -1  || cur< best) best= cur;
    return; 
  }


  for (it= left.begin() ; it!=left.end();it++){
    int a= *it;

    if ( level[a].first>star) continue;
    set<int> newdone, newhalf, newleft;
    newdone= done; 
    newhalf=half;
    newleft=left;
    newhalf.insert(a);
    newleft.erase(a);
    
    //    cout<< "left l1 "<<a<<endl;
    dfs( cur+1, star+1, newdone,newhalf,newleft);
  }


  
}

int main(){

  freopen("in.dat","r",stdin);
  int T; 
  cin>>T; 

  for (int iT=1;iT<=T;iT++){
    cout<<"Case #"<<iT<<": ";
 
    cin>>N;
  
    level.clear();
    for (int i=0;i<N;i++){
      int a, b;
      cin>>a>>b;
      level.push_back(make_pair(a,b));
    }

    /*    //    vector<int> idxfirst,idxsecond; 
    //    for (int i=0;i< N;i++) {
    //      idxfirst.push_back(i);
      idxsecond.push_back(i);
    }

    //    sort(idxfirst.begin(), idxfirst.end(),first);

    //    for ( int i=0;i<idxfirst.size();i++) cout<< idxfirst[i]<<endl;
    */
    
    set<int> done, half, left; 
    for (int i=0;i<N;i++) left.insert(i);
    
    best =-1;
    dfs( 0,0, done,half, left);
    
    if (best==-1) cout<<"Too Bad"<<endl;
    else  cout<<best<<endl;
    
  }

  return 0 ;
}
