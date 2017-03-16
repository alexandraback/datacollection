#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>

using namespace std;

int flag[3][10][10];
int ok[10][10][10];
int a[3];
int k;
int s[1000][3];

void swap(int* a,int* b){
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}

int main(){
	ifstream in("C-small-attempt0.in");
	ofstream out("C-small-attempt0.out");
	int Test,cnt;
	in>>Test;
	for (cnt=1;cnt<=Test;cnt++){
		in>>a[0]>>a[1]>>a[2]>>k;
		for (int i=1;i<=a[0];i++)
			for (int j=1;j<=a[1];j++)
				for (int l=1;l<=a[2];l++){
					ok[i][j][l]=1;
					flag[0][i][j]=0;
					flag[1][i][l]=0;
					flag[2][j][l]=0;
				}
		out<<"Case #"<<cnt<<": ";
		int ans=0;
		while (1){
			int min=10000;
			int ii,jj,ll;
			for (int i=1;i<=a[0];i++){
				for (int j=1;j<=a[1];j++){
					for (int l=1;l<=a[2];l++){
						if (ok[i][j][l]){
							int x[3];
							x[0]=flag[0][i][j];
							x[1]=flag[1][i][l];
							x[2]=flag[2][j][l];
							for (int b=0;b<3;b++){
								for (int c=b+1;c<3;c++){
									if (x[b]<x[c])
										swap(x[b],x[c]);
								}
							}
							int tmp=0;
							for (int b=0;b<3;b++){
								tmp=tmp*10+x[b];
								//cout<<"B"<<x[b];
							}
							//cout<<endl;
							if (tmp<min){
								min=tmp;
								ii=i;
								jj=j;
								ll=l;
							}
						}
					}
				}
			}
			if (min<k*100){
				//cout<<"Y"<<min<<endl;
				s[ans][0]=ii;
				s[ans][1]=jj;
				s[ans][2]=ll;
				ans++;
				ok[ii][jj][ll]=0;
				flag[0][ii][jj]++;
				flag[1][ii][ll]++;
				flag[2][jj][ll]++;
			}else{
				break;
			}
		}
		out<<ans<<endl;
		for (int i=0;i<ans;i++){
			out<<s[i][0]<<" "<<s[i][1]<<" "<<s[i][2]<<endl;
		}
	}
}
