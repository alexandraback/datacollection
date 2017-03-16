#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

#define OUTPUT_PREFIX "Case #"
#define INPUT_NAME "B-small-attempt0.in"
#define OUTPUT_NAME "output.dat"

using namespace std;

int main() {

	ifstream input;
	ofstream output;

	int testcase;

	input.open(INPUT_NAME);
	output.open(OUTPUT_NAME);

	input >> testcase;

	for(int test=0;test<testcase;test++) {
		int alphabetArr[26]={0,};
		int key,len,strin;
		input >> key >> len >> strin;

		bool flagAble=true;

		char *keyboard, *target;
		keyboard = new char(key+1);
		target = new char(len+1);
		input >> keyboard;
		input >> target;

		int overlap=0;

		for(int i=1;i<len;i++) {
			NEXT:
			if(target[i]==target[0]) {
				for(int j=1;j+i<len;j++) {
					if(target[i+j]!=target[j]) {
						i++;
						goto NEXT;
					}
				}
				overlap=i;
				break;
			}
		}

		double answer;

		for(int i=0;i<key;i++) {
			alphabetArr[(*(keyboard+i)-'A')]++;
		}

		for(int i=0;i<len;i++) {
			if(alphabetArr[target[i]-'A']==0) {
				answer=0;
				flagAble=false;
				break;
			}
		}

		if(flagAble) {
			int takeBanana;
			if(overlap!=0)
				takeBanana = (strin-len)/overlap +1;
			else
				takeBanana = strin/len;

			double prob=1;
			for(int i=0;i<len;i++) {
				prob*=(double)alphabetArr[target[i]-'A']/(double)key;
			}
			if(prob<0.000001)
				prob=0;

			answer = takeBanana*(1-prob);
		}

		output << OUTPUT_PREFIX << test+1 << ": " << answer << endl;
	}

	return 0;
}