#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	freopen("input1small.in", "r", stdin);
	freopen("outpu1small.in", "w", stdout);
	string s, s2,s3;
	int n, i, j, t;
	cin>>t;
	j=1;
	getchar();
	while(t--){
		cin>>s;
		s2.clear();
		s2.push_back(s[0]);
		for(i=1;i<s.length();i++){
			if(s[i]>=s2[0]){
				s3.clear();
				s3.push_back(s[i]);
				s3=s3+s2;
				s2=s3;
			}
			else {
				s2.push_back(s[i]);
			}
		}
		cout<<"Case #"<<j<<": "<<s2<<endl;
		j++;
	}



	return 0;
}