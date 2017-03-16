#include<iostream>
#include<math.h>
#include<set>

using namespace std;

int lengthnum(int i){
	int temp=i, count=0;
	while (temp!=0){
		temp = temp/10;
		count ++;
	}
	return count;
}
int count_pair(int a, int b){
	int res = 0;
	int num = lengthnum(a);
	for (int i=a; i<b; i++){
		int temp = i, min = i, count=0;
		for (int j=0; j<num; j++){
			int lastdig = temp % 10;
			temp = lastdig*pow(10,num-1) + temp/10;
			if (temp>=a and temp<min and temp>pow(10,num-1)) min = temp;	

		}
		if (min < i) continue;
		set<int> elem; 
		elem.insert(min);
		temp = min;
		for (int j=0; j<num-1; j++){
			int lastdig = temp % 10;
			temp = lastdig*pow(10,num-1) + temp/10;
			if (temp>=a and temp<=b) elem.insert(temp);
		}
		count = elem.size();
		res += count*(count-1)/2;
		// if (count>1) cout << min << " " << count << endl;
	}
	return res;
}

int main(){
	int n = 0,a,b;
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> a >> b;
		cout << "Case #" << i+1 << ": " << count_pair(a,b) << endl;
	}
}