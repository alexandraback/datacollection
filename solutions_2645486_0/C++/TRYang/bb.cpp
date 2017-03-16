#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;
typedef long long LL;

struct	Node{
	int	val,w;
	Node(int _val = 0, int _w = 0):val(_val),w(_w){}
	friend bool operator<( const Node &a , const Node &b ){
		return a.val!=b.val?a.val>b.val:a.w<b.w;
	}
};

vector<Node> data;
#define N 10010
LL		in[N],out[N],E,R;
set<int> ss;

int		main(){
	int	cas,tt,n;
	for( cin>>cas,tt = 1; tt<=cas; tt++){
		cout<<"Case #"<<tt<<": ";
		cin>>E>>R>>n;
		int	val,w=0;
		ss.clear(); 
		ss.insert(0); ss.insert(n+1);
		in[0] = 0 , out[0] = E;
		in[n+1] = 0, out[n+1] = 0;
		data.clear();
		while ( n -- ) {
			cin>>val;
			data.push_back( Node(val,++w) );
		}
		sort( data.begin() , data.end() );
		LL	ans = 0;
		for( vector<Node>::iterator iter = data.begin(); iter != data.end(); iter++ ){
			val = iter->val, w = iter->w;
			set<int>::iterator it = ss.lower_bound(w);
			int h = *it; 
			it--;
			int g = *it;
			in[w] = min( E , out[g]+(w-g)*R );
			out[w]= min( in[w] , max(0ll,in[h]-(h-w)*R) );
			ans += (in[w]-out[w])*val;
			ss.insert(w);
		}
		cout<<ans<<endl;
	}
}
