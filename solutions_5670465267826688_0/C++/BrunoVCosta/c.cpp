#include<iostream>
#include<string>
#include <fstream>
using namespace std;
//1 i j k
//1 2 3 4
int i=2,j=3,k=4;
int mul(int a,int b){
	int s = a*b>0?1:-1;
	a=a>0?a:-a;
	b=b>0?b:-b;
	if(a==1 && b==1)
		return 1*s;
	if(a==1 && b==i)
		return i*s;
	if(a==1 && b==j)
		return j*s;
	if(a==1 && b==k)
		return k*s;
	
	if(a==i && b==1)
		return i*s;
	if(a==i && b==i)
		return -1*s;
	if(a==i && b==j)
		return k*s;
	if(a==i && b==k)
		return -j*s;
	
	if(a==j && b==1)
		return j*s;
	if(a==j && b==i)
		return -k*s;
	if(a==j && b==j)
		return -1*s;
	if(a==j && b==k)
		return i*s;
	
	if(a==k && b==1)
		return k*s;
	if(a==k && b==i)
		return j*s;
	if(a==k && b==j)
		return -i*s;
	if(a==k && b==k)
		return -1*s;
	
}
int main(){
	ofstream myfile;
	myfile.open ("saida.txt");
	ifstream input("C-small-attemp0.in");
	int t,l,x;
	string s;
	input>>t;
	for(int caso =0;caso<t;caso++){
		int wanted = i;
		int resta=2;
		int result=1;
		input>>l>>x;
		input>>s;
		for(int pos =0;pos<l*x;pos++){
			//cout<<"result: "<<result<<"ch: "<<s[pos%l]<<endl;
			result=mul(result,s[pos%l]-'g');
			if (result==i && wanted == i){
				wanted = k;
				resta=1;
			}
			if(result==k && wanted == k){
				resta=0;
			}
			
		}
		myfile<<"Case #"<<caso+1<<": "<<( (resta==0 && result == -1) ? "YES" : "NO")<<endl;
		
	}
  	myfile.close();
	return 0;
}
