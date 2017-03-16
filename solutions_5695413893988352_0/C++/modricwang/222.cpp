#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <string>
using namespace std;

string s1,s2,a1,a2;
int T,ans1,ans2,det,now0,now1;
stringstream ss;

string tos(int i) {
	ss.clear();
	ss<<i;
	string s;
	ss>>s;
	return s;
}

bool match(string a, string b) {
	//if (a.length()!=b.length()) return false;
	while (a.length()<b.length()) a="0"+a;
	bool flag=true;
	for (int i=0; i<a.length(); i++) {
		if (a[i]!='?')
			if (b[i]!='?')
				if (a[i]!=b[i])
					flag=false;
	}
	return flag;
}

int main() {
	freopen("B.in","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>T;
	for (int ii=1; ii<=T; ii++) {
		int det=99999;
		cin>>s1>>s2;
		int len1=s1.length(),len2=s2.length();
		while (s1.length()<3) s1="0"+s1;
		while (s2.length()<3) s2="0"+s2;
		for (int n11=0; n11<=9; n11++) {
			if (s1[0]-'0'==n11 || s1[0]=='?')
				for (int n12=0; n12<=9; n12++) {
					if (s1[1]-'0'==n12 || s1[1]=='?')
						for (int n13=0; n13<=9; n13++) {
							if (s1[2]-'0'==n13 || s1[2]=='?')
								for (int n2=0; n2<=999; n2++) {
									int n1=100*n11+10*n12+n13;
									//cout<<n1<<endl;
									if (match(tos(n1),s1)&&match(tos(n2),s2)) {
										if ((abs(n1-n2)<det)||((abs(n1-n2)==det)&&n2<ans2)) {
											det=abs(n1-n2);
											ans1=n1;
											ans2=n2;
											//cout<<"Case #"<<ii<<": "<<ans1<<" "<<ans2<<endl;
										}
									}
								}
						}
				}
		}
		string a1=tos(ans1);
		while (a1.length()<len1) a1="0"+a1;
		string a2=tos(ans2);
		while (a2.length()<len2) a2="0"+a2;
		cout<<"Case #"<<ii<<": "<<a1<<" "<<a2<<endl;
	}
}
