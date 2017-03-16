#include <iostream>
#include <fstream>
#include <list>
#include <deque>
#include <algorithm>
using namespace std;

//istream& fin = cin;
//ifstream fin ("B-sample.txt");
ifstream fin ("B-small-attempt1.in");
ofstream fout ("B-small-attempt1.out");
//ifstream fin ("B-large.in");
//ofstream fout ("B-large.out");
//ostream& fout = cout;

class P{
	public:
		int a;
		int b;
		bool del;
		
		P(){
			del=false;
		}
};

bool cmp(const P& p1, const P& p2){
	return p1.a<p2.a || p1.a==p2.a && p1.b<p2.b;
}

bool cmp2(const P* p1, const P* p2){
	return p1->b<p2->b || p1->b==p2->b && p1->a<p2->a;
}

int main(){
	int t,n;
	fin >> t;
	for(int i=1; i<=t; i++){
		fin >> n;
		int rs=0, s=0;
		P tmp;
		list<P> d;
		list<P*> d2;
		deque<int> left;
		for(int j=0; j<n; j++){
			fin >> tmp.a >> tmp.b;
			d.push_back(tmp);
			d2.push_back(&tmp);
		}
		d.sort(cmp);
		d2.sort(cmp2);
		for(int j=0; j<n; j++){
			if(s>=d2.front()->b){
				s+=2;
				rs++;
				d2.front()->del=true;
				d2.pop_front();
			}else if(s>=d.front().a){
        list<P>::iterator it=d.begin();
				for(; it!=d.end(); it++){
					if(it->del){
						d.erase(it);
						it++;
					}
					if(it->a > d.front().a){
						it--;
						break;
					}
				}
				if(it==d.end()){
					it--;
				}
				if(it->b<=s){
					s+=2;
					rs++;
				}else{
					s++;
					rs++;
					left.push_back(it->b);
					sort(left.begin(),left.end());
				}
				//cout << it->a << ' ' << it->b << endl;
				d.erase(it);
			}else{
				rs=-1;
				break;
			}
			while(!left.empty() && left.front()<=s){
				//cout << "left: " << left.front() << endl;
				s++;
				rs++;
				left.pop_front();
			}
			//cout << "s: " << s << endl;
		}
		
		if(rs>0 && left.empty()){
			fout << "Case #" << i << ": " << rs << endl;
		}else{
      fout << "Case #" << i << ": Too Bad" << endl;
		}
	}
	system("pause");
}
