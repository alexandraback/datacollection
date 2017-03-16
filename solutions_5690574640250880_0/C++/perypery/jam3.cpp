#include<iostream>
#include<fstream>
using namespace std;
int T,M,R,C,remain,i;
//ifstream fin("in");
//ofstream fout("out");
istream &ist=cin;
ostream &ost=cout;
void printt(char** t){
	ost<<"Case #"<<i<<":"<<endl;
	for(int k=0;k<R;k++){
		for(int j=0;j<C;j++)
			ost<<t[k][j];
		ost<<endl;
	}
}
int main()
{
	ist>>T;
	for(i=1;i<=T;i++)
	{
		ist>>R>>C>>M;
		char** t;
		t=new char*[R];
		for(int j=0;j<R;j++){
			t[j]=new char[C];
			for(int jj=0;jj<C;jj++)
				t[j][jj]='*';
		}
		remain=C*R-M;
		if(remain==1){
			t[0][0]='c';
			printt(t);
			continue;
		}
		if(R==1){
			t[0][0]='c';
			for(int j=1;j<remain;j++)
				t[0][j]='.';	
			printt(t);
			continue;
		}
		if(C==1){
			t[0][0]='c';
			for(int j=1;j<remain;j++)
				t[j][0]='.';
			printt(t);
			continue;
		}
		if(C==2){
			if(remain%2||remain==2){
				ost<<"Case #"<<i<<":"<<endl;
				ost<<"Impossible"<<endl;
				continue;
			}
			else{
				for(int j=0;j<remain/2;j++){
					t[j][0]='.';
					t[j][1]='.';
				}
				t[0][0]='c';
				printt(t);
				continue;
			}
		}
		if(R==2){
			if(remain%2||remain==2){
				ost<<"Case #"<<i<<":"<<endl;
				ost<<"Impossible"<<endl;
				continue;
			}
			else{
				for(int j=0;j<remain/2;j++){
					t[0][j]='.';
					t[1][j]='.';
				}
				t[0][0]='c';
				printt(t);
				continue;
			}
		}
		
		if(remain==2||remain==3||remain==5||remain==7){
			ost<<"Case #"<<i<<":"<<endl;
			ost<<"Impossible"<<endl;
			continue;
		}
		if(remain==4){
			for(int k=0;k<2;k++)
				for(int kk=0;kk<2;kk++)
					t[k][kk]='.';
			t[0][0]='c';
			printt(t);
			continue;
		}
		if(remain==6){
			for(int k=0;k<2;k++)
				for(int kk=0;kk<3;kk++)
					t[k][kk]='.';
			t[0][0]='c';
			printt(t);
			continue;
		}
		if(remain==8){
			for(int k=0;k<3;k++)
				for(int kk=0;kk<3;kk++)
					t[kk][k]='.';
			t[2][2]='*';
			t[0][0]='c';
			printt(t);
			continue;
		}
		if(remain==9){
			for(int k=0;k<3;k++)
				for(int kk=0;kk<3;kk++)
					t[kk][k]='.';
			t[0][0]='c';
			printt(t);
			continue;
		}
		if(remain<=2*(R+C-2)){
			if(remain%2){//ÆæÊý
				for(int k=0;k<3;k++)
					for(int kk=0;kk<3;kk++)
						t[k][kk]='.';
				int rem=remain-9;
				if((rem/2)<=(C-3))
					for(int k=0;k<rem/2;k++)
						for(int kk=0;kk<2;kk++)
							t[kk][k+3]='.';
				else{
					for(int k=0;k<C-3;k++)
						for(int kk=0;kk<2;kk++)
							t[kk][k+3]='.';
					for(int k=0;k<(rem/2-C+3);k++)
						for(int kk=0;kk<2;kk++)
							t[k+3][kk]='.';
				}
			}
			else{//Å¼Êý
				if(remain<=2*C)
					for(int k=0;k<remain/2;k++){
						t[0][k]='.';
						t[1][k]='.';
					}
				else{
					for(int k=0;k<C;k++)
						for(int kk=0;kk<2;kk++)
							t[kk][k]='.';
					for(int k=0;k<(remain/2-C);k++)
						for(int kk=0;kk<2;kk++)
							t[k+2][kk]='.';
				}

			}
			t[0][0]='c';
			printt(t);
			continue;
		}
		else{
			for(int k=0;k<C;k++)
				for(int kk=0;kk<2;kk++)
					t[kk][k]='.';
			for(int k=2;k<R;k++)
				for(int kk=0;kk<2;kk++)
					t[k][kk]='.';
			int rem=remain-2*(R+C-2);
			for(int ki=2;ki<R;ki++){
				for(int kj=2;kj<C;kj++){
					if(rem==0)
						break;
					t[ki][kj]='.';
					rem--;
				}
				if(rem==0)
						break;
			}
			t[0][0]='c';
			printt(t);
			continue;
		}
	}
	return 0;
}