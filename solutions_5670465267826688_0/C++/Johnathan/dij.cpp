#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>

using namespace std;

const	int table[4][4] = {
		{1,2,3,4},{2,-1,4,-3},{3,-4,-1,2},{4,3,-2,-1}
	};
int tran(const char c){
	if (c == 'i')
		return 2;
	else if (c == 'j')
		return 3;
	else if (c == 'k')
		return 4;
}

//1,i == 2,j == 3, k == 4, -i == 2, -j == -3, -k == -4
int cop(const int &i, const int &j){
	int ans = table[abs(i)-1][abs(j)-1];
	if (i * j < 0)
		return (-1) * ans;
	else 
		return ans;
}

int power(const int & base, const int & deg){
	if (deg % 4 == 0)
		return cop(cop(cop(base,base),base),base);
	else if (deg % 4 == 1)
		return base;
	else if (deg % 4 == 2)
		return cop(base,base);
	else if (deg % 4 == 3)
		return cop(cop(base,base),base);
}

int main(){
	freopen("input.in","r",stdin);
	freopen("output3.out","w",stdout);
	int t,n,x,l;
	string s;
	cin >> t;
	n = 0;
	while ((n++) < t){
		cin >> l >> x;
		cin >> s;
		//cout << l << " "<<x << endl;
		if (l * x < 3){
			cout << "Case #" << n << ": NO" << endl;
			//cout << "less than 3" << endl;
			continue;
		}
		vector<int> v;
		int sum = 1;
		for (int i = 0; i < s.size(); i++){
			v.push_back(tran(s[i]));
			sum = cop(sum, tran(s[i]));
		}
		//sum will be the sum for one iteration
		if (power(sum,x) != -1){
			cout << "Case #" << n << ": NO" << endl;
			//cout << "doesn;t sum up to -1" << endl;
			continue;
		}
		//start to find from left, i
		int leftSum = 1;
		bool findLeft = 0;
		int leftIndex;
		vector<int> v_to;
		for (int i = 0; i < l; i++){
			leftSum = cop(leftSum, v[i]);
			v_to.push_back(leftSum);
			if (leftSum == 2 && !findLeft){//find i
				findLeft = 1;
				leftIndex = i;
			}
		}//see if we can find itin the first iteration
		int k;//temp var
		if (!findLeft ){//if not
			for (int j = 1; j <= min(3,x-1); j++){
				for (int i = 0; i < l; i++){
					k = cop(power(sum,j),v_to[i]);
					if (k == 2){//find i
						findLeft =1;
						leftIndex = i + j * l;
						break;
					}
				}
				if (findLeft)
					break;
			}
		}
		if (!findLeft){
			cout << "Case #" << n << ": NO" << endl;
			//cout << "cant find left" << endl;
			continue;
		}//cant find left, quit

		//start to find from right, k
		int rightSum = 1;
		bool findRight = 0;
		int rightIndex = -1;
		vector<int> v_from;
		for (int i = l-1; i >= 0; i--){
			rightSum = cop(v[i],rightSum);
			v_from.push_back(rightSum);
			if (rightSum == 4 && !findRight){//find k
				findRight = 1;
				rightIndex = l*x - l +i;
			}
		}//see if we can find it in the first iteration
		
		if (!findRight ){//if not
			for (int j = 1; j <= min(3,x-1); j++){
				for (int i = 0; i < l; i++){
					k = cop(v_from[i],power(sum,j));
					if (k == 4){//find k
						findRight =1;
						rightIndex = l*x - j*l - i ;
						break;
					}
				}
				if (findRight)
					break;
			}
		}
		if (!findRight){
			cout << "Case #" << n << ": NO" << endl;
			//cout << "cant find right" << endl;
			continue;
		}//cant find right, quit
		if (rightIndex <= leftIndex){
			cout << "Case #" << n << ": NO" << endl;
			//cout << "cant find j" << endl;
			continue;
		}
		cout << "Case #" << n << ": YES" << endl; 
	}
	return 0;
}