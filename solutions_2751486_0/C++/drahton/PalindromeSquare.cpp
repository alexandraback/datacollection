#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<sstream>
#include<fstream>
#include<map>   
#include<deque>
using namespace std;


int main(){
	ifstream cin;
	cin.open("A-small-attempt0.in");
	ofstream cout;
//	dic.open("garbled_email_dictionary.txt");
	cout.open("out.txt");
	


	
	int T;
	cin>>T;
	for(int k=0;k<T;k++){
		string s;
		int n;
		cin>>s;
		cin>>n;
		int fcount=0;
		for(int i=0;i<s.length();i++){
			for(int j=i;j<s.length();j++){
				bool cont=false;
				int cnt=0;
				for(int k=i;k<=j;k++){
					if( s[k]!='a' && s[k]!='e' && s[k]!='i' && s[k]!='o' && s[k]!='u'){
						cnt++;
						if(cnt>=n) cont=true;
					}
					else cnt=0;


				}
				fcount += cont;
				

			}


		}
		





		cout<<"Case #"<<k+1<<": "<<fcount<<endl;





	}





	return 0;

}


