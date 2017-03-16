#include <iostream>
#include <vector>
using namespace std;

int evaluate(int a,int b){
	if(a<0)return -evaluate(-a,b);
	else if (b<0) return -evaluate(a,-b);
	
	if(a==1) return b;
	else if(b==1) return a;
	else if(a==2 && b ==2) return -1;
	else if(a==2 && b ==3) return 4;
	else if(a==2 && b ==4) return -3;
	else if(a==3 && b ==2) return -4;
	else if(a==3 && b ==3) return -1;
	else if(a==3 && b ==4) return 2;
	else if(a==4 && b ==2) return 3;
	else if(a==4 && b ==3) return -2;
	else if(a==4 && b ==4) return -1;
}
int main(){
	int cases,level;
	vector<int> a;
	cin>>cases;
	for(int i =0;i<cases;i++){
		int n,rep;
		cin>>n>>rep;
		a.resize(n*rep);
		char temp;
		for(int j =0;j< n;j++){
			cin>>temp;
			if(temp =='i') a[j]=2;
			else if(temp =='j') a[j]=3;
			else if(temp =='k') a[j]=4;
		}
		for(int k =n;k<n*rep;k++){
			a[k] = a[k%n];
		}
		//cout<<a.size()<<endl;
		bool sati=false,satj=false,satk=false;
        while(a.size()>1 && sati ==false){
			if(a[0] != 2){
				int result = evaluate(a[0],a[1]);
				a.erase(a.begin(),a.begin()+2);
				a.insert(a.begin(),result);
			}
			else{
				a.erase(a.begin());
				sati = true;
			}
		}
		//cout<<a.size()<<" *** "<<sati<<" Finishing i\n";
		while(a.size()>1 && satk ==false && sati == true){
			int end=a.size()-1;
			if(a[end] != 4){
				int result = evaluate(a[end-1],a[end]);
				a.pop_back();
				a.pop_back();
				a.push_back(result);
			}
			else{
				a.pop_back();
				satk = true;
			}
		}
		//cout<<a.size()<<" *** "<<satk<<" Finishing k\n";
		while(satj == false && satk ==true && sati == true){
			if(a.size() > 1){
				int result = evaluate(a[0],a[1]);
				a.erase(a.begin(),a.begin()+2);
				a.insert(a.begin(),result);
			}
			else if(a[0]==3){
				satj = true;
				break;
			}
			else{
				break;
			}
		}	
		//cout<<a.size()<<" *** "<<satj<<" Finishing j\n";
		if(sati==true && satj==true && satk==true){
			cout<<"Case #"<<i+1<<": YES"<<endl;	
		}else{
			cout<<"Case #"<<i+1<<": No"<<endl;				
		}
	}
	return 0;
}
