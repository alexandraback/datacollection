#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool mySort(const unsigned int& a, const unsigned int& b)
{
  if ((a & 0xFFFF) == (b & 0xFFFF)){
	return (a >> 16) > (b >> 16);
  }
  return (a & 0xFFFF) > (b & 0xFFFF);
}

int main(){
	unsigned int T, N;
	unsigned int scores, res;
	unsigned int a,b,ab;
	int f;
	cin >> T;
	vector<unsigned int> ARR;
	
	for(int ti=1; ti<=T; ti++){
		scores = 0;
		res = 0;
		ARR.clear();
		
		cin >> N;
		
		for(int j=0; j<N; j++){
			cin >> a >> b;
			ab = (a<<16) + b;
			ARR.push_back(ab);
			
		}
		
		std::sort(ARR.begin(), ARR.end(), mySort);
		
		/*for(int j=0; j<ARR.size(); j++){
			cout << (ARR[j]>>16) << " " << (ARR[j]&0xFFFF) << endl;
		}*/
		
		while (!ARR.empty()){
			res++;
			//cout << "SCORES - " << scores << " " << (ARR.back()&0xFFFF) << endl;
			if((ARR.back()&0xFFFF) <= scores){
				ARR.pop_back();
				scores+=2;
			}else{
				f = 1;
				for(int i=ARR.size()-1; i>=0; i--){
					if ((ARR[i] >> 16) <= scores){
						scores++;
						ARR[i] |= 0xFFFF0000;
						f = 0;
						break;
					}
				}
				if (f){
					res = 0xFFFFFFFF;
					break;
				}
			}
		}
		if (res==0xFFFFFFFF){
			cout << "Case #" << ti << ": " << "Too Bad" << endl;
		}else{
			cout << "Case #" << ti << ": " << res << endl;
		}
		
	}
	
	return 0;
}

