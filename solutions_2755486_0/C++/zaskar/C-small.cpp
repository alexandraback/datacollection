#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;


struct wall {
	struct togrow {
		int w,e,s;
		togrow(int a, int b, int c) {w=a; e=b; s=c;}
	};
	vector<togrow> tg;
	struct height {
		int x, h;
		height(int a,int b){x=a; h=b;}
	};
	vector<height> h;
	void grow() {
		for(int i=0;i<tg.size();i++) { 
			int i0=find(tg[i].w);
			int i1=find(tg[i].e);
			if (h[i1].x!=tg[i].e) { h.insert(h.begin()+i1+1,height(tg[i].e,h[i1].h)); i1++; }
			if (h[i0].x==tg[i].w) { h[i0].h=tg[i].s; }
			else { h.insert(h.begin()+i0+1,height(tg[i].w,tg[i].s)); i0++; }
			int j=i0+1;
			while (j<i1) {  
				if (h[j].h<tg[i].s) { 
					h.erase(h.begin()+j); i1--;
				} else j++;
			}
		}
	}
	int find(int x) {
		int i0=0,i1=h.size()-1;
		while (true) {
			if (i0==i1) return i0;
			if (i0+1==i1) return h[i1].x==x?i1:i0;
			int i=(i0+i1)/2;
			if (h[i].x==x) return i;
			if (h[i].x>x) i1=i;
			else i0=i;
		}
	}
	int attack(int w, int e, int s) {
		int i0=find(w);
		int i1=find(e-1);
		int ret=0;
		for(int i=i0;i<=i1;i++) {  
			if (h[i].h<s) {
				ret=1;
			}
		}
		if (ret) tg.push_back(togrow(w,e,s));
		return ret;
	}
	wall() { 
		h.push_back(height(INT_MIN,0));
		h.push_back(height(INT_MAX,0));
	}
};

struct trib {
	int d,n,w,e,s,dd,dp,ds;
	int attack(wall &wl) {
		int r=wl.attack(w,e,s);
		e+=dp; w+=dp; n--; d+=dd; s+=ds;
		return r;
	}
};

int main(int argc, char *argv[]) {
	ifstream fin("C-small-attempt1.in");
	ofstream fout("C-small-attempt1.out");
	int T;
	fin>>T;
	for(int I=0;I<T;I++) {
		int n;
		fin>>n;
		trib t[1000];
		wall w;
		for(int i=0;i<n;i++) { 
			fin>>t[i].d>>t[i].n>>t[i].w>>t[i].e>>t[i].s>>t[i].dd>>t[i].dp>>t[i].ds;
		}
		int r=0;
		while (true) {
			int na=-1;
			for(int i=0;i<n;i++) { 
				if (t[i].n && (na==-1||t[i].d<na)) na=t[i].d;
			}
			if (na==-1) break;
			for(int i=0;i<n;i++) { 
				if (t[i].n && (na==t[i].d)) r+=t[i].attack(w);
			}
			w.grow();
		}
		fout<<"Case #"<<I+1<<": "<<r<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}

