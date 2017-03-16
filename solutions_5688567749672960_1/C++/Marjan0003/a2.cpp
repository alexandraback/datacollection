#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<map>
#include <math.h>


using namespace std;
long long int solve_i(int n);

int solution[16];
int reverse (int i){
	//if(i%10==0)
	//	return i;
	stringstream r("");
	while(i!=0){
		int l=i/10;
		int s=i%10;
		r<<s;
		i=l;
	}
	int f;
	r>>f;
	return f;
}

	
long long int toInt(string n){
	stringstream s(n);
	long long int i;
	s>>i;
	return i;
}

long long int solve(string n){
	//cout<<n<<endl;
	long long int nint=toInt(n);
	int l=n.length();
	if(l==1)
		return toInt(n);
	int first=toInt(n.substr(0,l/2));
	int second=toInt(n.substr(l/2));
	//cout<<first<<" "<<second<<endl;
	if(second==0)
		return solve_i(nint-1)+1;
	long long int sol=0;
	sol+=solution[l-1]; 
	//cout<<"solut:"<<solution[l-1]<<endl;
	
	//cout<<"sol so far"<<sol<<endl;
	int s=pow(10,l/2-1);
	if(s==first){
		return sol+second;
	}
	sol+=reverse(first);
	sol+=second;
	
	
	return sol;
}
long long int solve_i(int n){
	stringstream s("");
	s<<n;
	return solve(s.str());
}


int main(){
	ifstream in("in");
	ofstream out("out");
	solution[0] = 1;
	solution[1] = solution[0]+9;
	solution[2] = solution[1] + 9 + 1 + 9;
	solution[3] = solution[2] + 9 + 1 + 99;
	solution[4] = solution[3] + 99 + 1 + 99;
	solution[5] = solution[4] + 99 + 1 + 999;
	solution[6] = solution[5] + 999 + 1 + 999;
	solution[7] = solution[6] + 999 + 1 + 9999;
	solution[8] = solution[7] + 9999 + 1 + 9999;
	solution[9] = solution[8] + 9999 + 1 + 99999;
	solution[10]= solution[9] + 99999 + 1 + 99999;
	solution[11]= solution[10]+ 99999 + 1 + 999999;
	solution[12]= solution[11]+ 999999 + 1 + 999999;
	solution[13]= solution[12]+ 999999 + 1 + 9999999;
	solution[14]= solution[13]+ 9999999 + 1 + 9999999;
	
	int casenum=0;
	in>>casenum;
	string n;
		
	//cout<<solve("27214")<<endl;
	for (int c=0;c<casenum;c++){
		in>>n;
		cout<<"Case #"<<c+1<<": "<<solve(n)<<endl;	
	
		
	}
	
	//cout<<solve("101000");
	//cout<<solve("2002");
	
	return 0;
	
}
