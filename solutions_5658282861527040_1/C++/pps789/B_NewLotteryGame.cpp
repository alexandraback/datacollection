#include<iostream>
#include<algorithm>
#include<bitset>
using namespace std;

typedef unsigned long long ull;

bitset<32> A, B, K;

ull back(int index, bool aFree, bool bFree, bool kFree){
	if(index == 0){
		if(kFree){
			if(aFree){
				if(bFree){
					return 4;
				}
				else{
					if(B.test(index)) return 2;
					else return 0;
				}
			}
			else{
				if(A.test(index)){
					if(bFree){
						return 2;
					}
					else{
						if(B.test(index)) return 1;
						else return 0;
					}
				}
				else return 0;
			}
		}
		else{
			if(K.test(index)){
				if(aFree){
					if(bFree){
						return 3;
					}
					else{
						if(B.test(index)){
							return 2;
						}
						else return 0;
					}
				}
				else{
					if(A.test(index)){
						if(bFree) return 2;
						else{
							if(B.test(index)) return 1;
							else return 0;
						}
					}
					else return 0;
				}
			}
			else return 0;
		}
	}



	if(aFree){
		if(bFree){
			if(kFree){
				return (1ULL << ((index+1) * 2));
			}
			else{
				bool now = K.test(index);
				if(now) return 3*back(index-1, true, true, true)+back(index-1, true, true, false);
				else return 3*back(index-1, true, true, false);
			}
		}
		else{
			bool nowB = B.test(index);
			if(nowB){
				if(kFree){
					return 2*back(index-1, true, true, true) + 2*back(index-1, true, false, true);
				}
				else{
					bool nowK = K.test(index);
					if(nowK){
						return 2*back(index-1, true, true, true) + back(index-1, true, false, true) + back(index-1, true, false, false);
					}
					else{
						return 2*back(index-1, true, true, false) + back(index-1, true, false, false);
					}
				}
			}
			else{
				if(kFree || K.test(index))
					return 2*back(index-1, true, false, true);
				else return 2*back(index-1, true, false, false);
			}
		}
	}
	else{
		bool nowA = A.test(index);
		if(nowA){
			if(bFree){
				if(kFree){
					return 2*back(index-1, false, true, true) + 2*back(index-1, true, true, true);
				}
				else{
					bool nowK = K.test(index);
					if(nowK){
						return 2*back(index-1, true, true, true) + back(index-1, false, true, true) + back(index-1, false, true, false);
					}
					else{
						return 2*back(index-1, true, true, false) + back(index-1, false, true, false);
					}
				}
			}
			else{
				bool nowB = B.test(index);
				if(nowB){
					// nowA=1, nowB=1, both not free
					if(kFree){
						return back(index-1, true, true, true) + back(index-1, true, false, true) + back(index-1, false, true, true) + back(index-1, false, false, true);
					}
					else{
						bool nowK = K.test(index);
						if(nowK){
							return back(index-1, true, true, true) + back(index-1, false, true, true) + back(index-1, true, false, true) + back(index-1, false, false, false);
						}
						else{
							return back(index-1, true, true, false) + back(index-1, false, true, false) + back(index-1, true, false, false);
						}
					}
				}
				else{
					// nowA=1, nowB=0
					if(kFree)
						return back(index-1, true, false, true) + back(index-1, false, false, true);
					else{
						bool nowK = K.test(index);
						if(nowK){
							return back(index-1, true, false, true) + back(index-1, false, false, true);
						}
						else{
							return back(index-1, true, false, false) + back(index-1, false, false, false);
						}
					}
				}
			}
		}
		else{
			// nowA = 0, notFree
			if(bFree){
				if(kFree){
					return 2*back(index-1, false, true, true);
				}
				else{
					bool nowK = K.test(index);
					if(nowK){
						return 2*back(index-1, false, true, true);
					}
					else return 2*back(index-1, false, true, false);
				}
			}
			else{
				bool nowB = B.test(index);
				if(nowB){
					if(kFree){
						return back(index-1, false, true, true) + back(index-1, false, false, true);
					}
					else{
						bool nowK = K.test(index);
						if(nowK){
							return back(index-1, false, true, true) + back(index-1, false, false, true);
						}
						else{
							return back(index-1, false, true, false) + back(index-1, false, false, false);
						}
					}
				}
				else{
					if(kFree)
						return back(index-1, false, false, true);
					else return back(index-1, false, false, K.test(index));
				}
			}
		}
	}
}

ull a,b,k;

int getSize(ull val){
	int ret=0;
	while(val){
		ret ++;
		val >>= 1;
	}
	return --ret;
}

int main(){

	freopen("B-large.in", "r", stdin);
	freopen("myOut.txt", "w", stdout);

	int T;
	cin >> T;
	for(int tc=1; tc<=T; tc++){
		cout << "Case #"<<tc<<": ";

		cin >> a >> b >> k;

		int m = max(getSize(a), max(getSize(b), getSize(k)));

		A = bitset<32>(a);
		B = bitset<32>(b);
		K = bitset<32>(k);

		ull ans = 0;

		cout << back(m+1, false, false, false) << endl;
	}
}