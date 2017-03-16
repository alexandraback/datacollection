#include <bits/stdc++.h>

using namespace std;

bool f0(vector<int> &a, int v){
	vector<bool> p(v+1);
	vector<bool> p1(v+1);
	//sort(a.begin(), a.end());
	p[a[0]] = true;
	for(int i=1;i<a.size();i++){
		for(int j=1;j+a[i]<p.size();j++){
			if(p[j]) p1[j+a[i]] = true;
		}
		for(int j=1;j<p.size();j++){
			if(p1[j]) p[j] = true;
		}
		for(int j=1;j<p.size();j++){
			p1[j] = false;
		}
		p[a[i]] = true;
	}
	bool ret = true;
	for(int j=1;j<p.size();j++){
		if(!p[j]) ret = false;
	}
	return ret;
}

bool pre(vector<int> &a, int v){
	for(int i=0;i<a.size();i++){
		if(a[i] == v) return true;
	}
	return false;
}

bool f1(vector<int> &a, int v){
	//sort(a.begin(), a.end());
	for(int i=3;i<v+1;i++){
		if(!pre(a, i)){
			//vector<int> b = a;
			a.push_back(i);
			if(f0(a, v)){
				//cout<<"vfgdf  "<<i<<endl;
				return true;
			}
			a.resize(a.size()-1);
		}
	}
	return false;
}

bool f2(vector<int> a, int v){
	//sort(a.begin(), a.end());
	for(int i=3;i<v+1;i++){
		if(!pre(a, i)){
			a.push_back(i);
			if(f1(a, v)){
				//cout<<"vfgdf  "<<i<<endl;
				return true;
			}
			a.resize(a.size()-1);
		}
	}
	return false;
}

int main(){
	int t;
	cin>>t;
	for(int g=1;g<=t;g++){
		int c, d, v;
		cin>>c>>d>>v;
		vector<int> a(d);
		bool is1 = false;
		bool is2 = false;
		bool ise = false;
		for(int i=0;i<d;i++){
			cin>>a[i];
			if(a[i] == 1) is1 = true;
			else if(a[i] == 2) is2 = true;
			else ise = true;
		}
		if(!ise){
			//cout<<"Inside"<<endl;
			int q=0;
			int w = v;
			while(w > 0){
				w = w/2;
				q++;
			}
			cout<<"Case #"<<g<<": "<<q-d<<endl;
			continue;
		}
		int ans = 0;
		if(!is1){
			//cout<<"Is1"<<endl;
			a.push_back(1);
			ans++;
		}
		if(!is2 && v > 1){
			//cout<<"Is2"<<endl;
			a.push_back(2);
			ans++;
		}
		if(f0(a, v)) ;
		else if(f1(a, v)) ans = ans + 1;
		else if(f2(a, v)) ans = ans + 2;
		else ans = ans + 3;
		cout<<"Case #"<<g<<": "<<ans<<endl;
	}
}
