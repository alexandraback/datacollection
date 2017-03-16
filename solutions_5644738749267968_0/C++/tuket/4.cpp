#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

void printvec(list <float> &vec){
	for(list<float>::iterator i= vec.begin(); i!= vec.end(); ++i) cout << *i << " ";
	cout << endl;
}

class Player{
	list<float> woods;
public:
	Player(){}
	
	void addWood(float w){ woods.push_back(w); }
	void sortWoods(){ woods.sort(); }
	
	float retriveMinGreater( float f ){
		
		list<float>::iterator i;
		bool found = false;
		for(i=woods.begin(); i != woods.end(); ++i)
			if( *i > f ){
				found = true;
				break;
			}
		
		if( !found ){
			woods.erase(woods.begin());
			return -1.0f;
		}
		
		float res = *i;
		woods.erase(i);
		return res;
		
	}
	
	float useMin(){
		float res = woods.front();
		woods.erase( woods.begin() );
		return res;
	}
	
	float useMax(){
		
		float res = woods.back();
		woods.pop_back();
		return res;
		
	}
	
	float getMin(){ return woods.front(); }
	float getMax(){ return woods.back(); }
		
};


int main(){
	
	int nn;
	cin>>nn;
	
	for(int kk=0; kk<nn; kk++){
		
		
		Player p1, pp1;
		Player p2, pp2;
		
		int N;
		cin>>N;
		
		for(int i=0; i<N; i++){
			float w;
			cin>>w;
			p1.addWood(w);
			pp1.addWood(w);
		}
		for(int i=0; i<N; i++){
			float w;
			cin>>w;
			p2.addWood(w);
			pp2.addWood(w);
		}
		p1.sortWoods();
		p2.sortWoods();
		pp1.sortWoods();
		pp2.sortWoods();
		int res = 0;
		for(int i=0; i<N; i++){
			
			float min2 = p2.getMin();
			float play = p1.retriveMinGreater(min2);
			
			if( play > 0 ){
				p2.useMin();
				res++;
			}
			
		}
		
		
		int res2 = 0;
		for(int i=0; i<N; i++){
			
			float mm = pp1.useMax();
			float mn = pp2.retriveMinGreater(mm);
			
			if( mn < 0 ) res2++;
			
		}
		
		cout << "Case #" << kk+1 << ": ";
		cout << res << " " << res2 << endl;
		
	}
	
}
