#include <bits/stdc++.h>
using namespace std;
//  the code was run on "http://cpp.sh/"
__int128 str2Base(string s, __int128 base){
	__int128 res=0;
	for (auto &x:s){
		res*=base;
		if (x=='1'){
			res+=1;
		}
	}
	return res;
}

string int2bin(__int128 x){
	string res;
	while(x){
		if (x&1){
			res+='1';
		}else{
			res+='0';
		}
		x>>=1;
	}
	reverse(res.begin(),res.end());
	return res;
}

__int128 isPrime(__int128 x){
	if (x<2) return 0;
	for (__int128 i=2;i<100;i++){
		if (x%i==0) return i;
	}
	return -1;
}

int main() {
    ofstream ofile;
    ofile.open("Output.txt");

    cout<<"Case #1:"<<endl;
    ofile<<"Case #1:"<<endl;
//  begin of code
  //  1. prepare data for current test case
    	__int128 N=32,J=500;
    	    __int128 curNum=1;
    		curNum<<=(N-1);
    		curNum++;
    		for (int i=0;i<J;){
    			string curNumStr = int2bin(curNum);
    			string curRes="";
    			curRes += curNumStr+" ";
    			int base;
    			for (base=2;base<=10;base++){
    				__int128 temp = str2Base(curNumStr,base);
    				long long ip = isPrime(temp);
    				if (ip==-1) break;
    				else{
    				    curRes += to_string(ip)+" ";
    				}
    			}
    			if (base==11) {
    				cout<<curRes<<endl;
    				ofile<<curRes<<endl;
    				i++;
    			}
    			curNum+=2;
    		}
    	ofile.close();
	return 0;
}

