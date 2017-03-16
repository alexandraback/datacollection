#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <cmath>
# define pb push_back
using namespace std;
//-----------------------------
string s;
long long t, n, n1, cnt, ans;
vector <int> vec;
//----------------------------------
bool check(char c){
	if(c == 'a' || c == 'e' || c == 'i' 
		|| c == 'o' || c == 'u') return true;
	return false;
}
void work(){

	for(int i = 0; i < n; i++){
		if(check(s[i])){
			while(check(s[i])){
				cnt++; i++;
				if(i == n)break;
			}
			vec.pb(cnt); cnt = 0;
		}
		if(i < n && !check(s[i])){
			while(!check(s[i])){
				cnt++; i++;
				if(i == n)break;
			}
			vec.pb(cnt); cnt = 0;
		}i--;
	}
}
//---------------------------------
int main(){
	ifstream cin("A-large.in");
	ofstream cout("A-large.out");
	long long sum, sum1;
	cin>>t;
	for(int ch = 1; ch <= t; ch++){
		cin>>s>>n1;
		n = s.size();
		vec.clear();
		work();
		sum = 0; sum1 = 0;
		for(int i = 0; i < vec.size(); i++){
			sum += vec[i];
			//cout<<vec[i]<<" ";
		}
		//cout<<endl;
		int i = 0, f = 0;
		if(check(s[0])){
			i++;
			sum1 = vec[0];
			sum -=vec[0];
		}
		for(; i < vec.size(); i += 2){
			sum -= vec[i];
			if(vec[i] >= n1){
									//		cout<<i<<" I "<<sum<<" sum "<<sum1<<" sum1 "<<endl;
				ans += (sum1 + 1) * (1 + vec[i] - n1 + sum);
											//cout<<ans<<" ans"<<endl;
				if(vec[i] - n1 > 0){
					ans += ((sum + vec[i] - n1 + sum + 1)*(vec[i] - n1))/2;
							//	cout<<ans<<" ans if "<<endl;
				}
				sum1 = n1 - vec[i] - 1;
			}
			//cout<<i<< " i "<< vec.size()<<"vec.size()  \n";
			if(i < int(vec.size() - 2)){
				sum1 += vec[i] + vec[i+1];
				sum -= vec[i+1];
			}
		}
		cout<<"Case #"<<ch<<": "<<ans<<endl;
		ans = 0;
	}

//	system("pause");
	return 0;
}