

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>
#include <set>
#include <map>
#include <vector>
#include <list>
//#include <unordered_map>



using namespace std;

typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;

//#define MIN = -1000000000;
template<typename T>
void display(T a[], int size){
	for(int i = 0; i < size; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void display(vector<PII> a){
	for(int i = 0; i < a.size(); i++){
		cout<<"("<<a[i].first<<","<<a[i].second<<")"<<" ";
	}
	cout<<endl;
}

void display(vector<int> a){
	for(int i = 0; i < a.size(); i++){
		cout<<a[i];
		if(i == a.size() - 1) cout<<endl;
		else cout<<" ";
	}
}

template<typename T>
void initialise(T a[], T value, int length){
        for(int i = 0; i < length; i++) a[i] = value;
}

template<typename T>
void initialise(vector<T>& a, T value){
    for(int i = 0; i < a.size(); i++) a[i] = value;
}


bool compare(PII a, PII b){
	if(a.first != b.first) return a.first < b.first;
	else return a.second < b.second;
}

int max(int a[], int n){
	int max = -1000000000;
	for(int i = 0; i < n; i++){
		if(a[i] > max) max = a[i];
	}
	return max;
}

bool find(string a[], string s, int n){
	int left = 0;
	int right = n -1;
	while(left < right){
		int mid = (left+right)/2;
		if(s.compare(a[mid]) == 0) return true;
		else if(s.compare(a[mid]) < 0){
			right = mid;
		}
		else{
			left = mid + 1;
		}
	}
	return false;
}

void factor(int a[], int base, long long num, int n){
	for(int i = n - 1; i >= 0; i--){
		a[i] = num % base;
		num = num/base;
	}
}


int findLength(long long n, int base){
	int i = 0;
	while(n > 0){
		i++;
		n = n/base;
	}
	return i;
}

int gcd(int a, int b){
	while( a % b != 0 && b % a != 0){
		if(b > a){
			b = b % a;
		}
		else if(a > b){
			a = a % b;
		}
	}

	if(a <= b) return a;
	else return b;
}

bool compare(vector<int> a, vector<int> b){
	for(int i = 0; i < a.size() - 1; i++){
		if(a[i] != b[i]) return a[i] < b[i];
	}
	return a[a.size()-1] < b[a.size()-1];
}


int main(){
	int t; cin>>t;
	for(int test = 0; test < t; test++){
		cout<<"Case #"<<test+1<<": ";

		int b;
		long long m; 
		cin>>b>>m;
		long long curr = 1;
		for(int i = 0; i < b-2; i++){
			curr *= 2;
		}
		if(curr < m){
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}
		else{
			cout<<"POSSIBLE"<<endl;
			int rel[b][b];
			for(int i = 0; i < b; i++){
				initialise(rel[i], 0, b);
			}
			rel[0][b-1] = 1;
			for(int i = 0; i < b - 1; i++){
				for(int j = i + 1; j < b -1; j++){
					rel[i][j] = 1;
				}
			}
			m--;

			int a[findLength(m, 2)];
			factor(a, 2, m, findLength(m, 2));
			for(int i = findLength(m, 2) - 1; i >= 0; i--){
				if(a[i] == 1) rel[findLength(m, 2) - i][b-1] = 1;
			}
			
			for(int i = 0; i < b; i++){
				for(int j = 0; j < b; j++){
					cout<<rel[i][j];
					if(j == b -1) cout<<endl;
					
				}
			}

			
		}

	}
	
	
	return 0;

}
