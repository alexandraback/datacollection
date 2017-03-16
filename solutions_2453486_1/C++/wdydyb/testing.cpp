#include<iostream>
#include<vector>
using namespace std;
int main(){
	int T;
	cin>>T;
	int cnt=0;
	while(T--){
		
		cout<<"Case #"<<++cnt<<": ";
		
		vector<string> s(4);
		for(int i=0;i<4;i++){
			cin>>s[i];
		}
		bool dot=false;
		for(int i=0;i<4;i++){
			int ml1=0,ml2=0;
			int bt1=0,bt2=0;
			int t1=0,t2=0;
			for(int j=0;j<4;j++){
				if(s[i][j]=='O'){
					ml1++;
				}else if(s[i][j]=='X'){
					bt1++;
				}else if(s[i][j]=='T'){
					t1++;
				}else if(s[i][j]=='.'){
					dot=true;
				}
				if(s[j][i]=='O'){
					ml2++;
				}else if(s[j][i]=='X'){
					bt2++;
				}if(s[j][i]=='T'){
					t2++;
				}else if(s[j][i]=='.'){
					dot=true;
				}
			}
			if(ml1==4||ml2==4||(ml1==3&&t1==1)||(ml2==3&&t2==1)){
				cout<<"O won"<<endl;
				goto end;
			}else if(bt1==4||bt2==4||(bt1==3&&t1==1)||(bt2==3&&t2==1)){
				//cout<<i<<" "<<bt1<<"    "<<bt2<<" "<<T<<endl;
				cout<<"X won"<<endl;
				goto end;
			}
		}
		int ml=0,bt=0,t=0;
		for(int i=0;i<4;i++){
			if(s[i][i]=='O'){
				ml++;
			}else if(s[i][i]=='X'){
				bt++;
			}else if(s[i][i]=='T'){
				t++;
			}
		}
		if(ml==4||(ml==3&&t==1)){
			cout<<"O won"<<endl;
				goto end;
		}else if(bt==4||(bt==3&&t==1)){
			cout<<"X won"<<endl;
				goto end;
		}
		ml=0,bt=0,t=0;
		for(int i=0;i<4;i++){
			if(s[i][3-i]=='O'){
				ml++;
			}else if(s[i][3-i]=='X'){
				bt++;
			}else if(s[i][3-i]=='T'){
				t++;
			}
		}
		if(ml==4||(ml==3&&t==1)){
			cout<<"O won"<<endl;
				goto end;
		}else if(bt==4||(bt==3&&t==1)){
			cout<<"X won"<<endl;
				goto end;
		}
		if(dot){
			cout<<"Game has not completed"<<endl;
		}else{
			cout<<"Draw"<<endl;
		}
		
		
		
		
		end:;
	}
	return 0;
}