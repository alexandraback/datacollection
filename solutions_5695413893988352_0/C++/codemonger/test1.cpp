#include <iostream>
#include <stdio.h>
#include <cstring>
#include <sstream>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;
#define sc(x) scanf("%d",&(x))
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)
#define fork(n) for(int k=0;k<n;k++)
#define forii(n) for(int ii=0;ii<n;ii++)
#define forjj(n) for(int jj=0;jj<n;jj++)
#define forkk(n) for(int kk=0;kk<n;kk++)




int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w",stdout);
	
	int t;
	sc(t);
	for(int z=1;z<=t;z++){
		printf("Case #%d: ",z);
		string s1,s2;
		cin>>s1>>s2;
		//cout<<s1<<s2<<endl;
		int l1=s1.length();
		//cout<<l1<<endl;
		int a[3];
		int b[3];
		fori(3){
			a[i]=0;
			b[i]=0;
		}
		int x[3],y[3];
		int diff=1000000;
		if(l1==1){			
			fori(10){
				forii(10){					
					if(s1[0]=='?'){x[0]=i;}else x[0]=s1[0]-'0';
					if(s2[0]=='?'){y[0]=ii;}else y[0]=s2[0]-'0';
					int t3=abs(x[0]-y[0]);
					if(t3<diff){
						diff=t3;
						fori(l1){
							a[i]=x[i];
						}
						fori(l1){
							b[i]=y[i];
						}
					}
				}
			}
			fori(l1){
				cout<<a[i];
			}
			cout<<" ";
			fori(l1){
				cout<<b[i];
			}
			cout<<endl;

		}
		else if(l1==2){
			fori(10){
				forj(10){
					forii(10){
						forjj(10){
							if(s1[0]=='?'){x[0]=i;}else x[0]=s1[0]-'0';
							if(s1[1]=='?'){x[1]=j;}else x[1]=s1[1]-'0';
							if(s2[0]=='?'){y[0]=ii;}else y[0]=s2[0]-'0';
							if(s2[1]=='?'){y[1]=jj;}else y[1]=s2[1]-'0';
							int t1=x[0]*10+x[1];
							int t2=y[0]*10+y[1];
							int t3=abs(t1-t2);
							if(t3<diff){
								diff=t3;
								fori(l1){
									a[i]=x[i];
								}
								fori(l1){
									b[i]=y[i];
								}
							}

						}
					}
				}
			}
			fori(l1){
				cout<<a[i];
			}
			cout<<" ";
			fori(l1){
				cout<<b[i];
			}
			cout<<endl;
			
		}
		else if(l1==3){
			//cout<<"here"<<endl;
			fori(10){
				forj(10){
					fork(10){
						forii(10){
							forjj(10){
								forkk(10){
									if(s1[0]=='?'){x[0]=i;}else x[0]=s1[0]-'0';
									if(s1[1]=='?'){x[1]=j;}else x[1]=s1[1]-'0';
									if(s1[2]=='?'){x[2]=k;}else x[2]=s1[2]-'0';
									if(s2[0]=='?'){y[0]=ii;}else y[0]=s2[0]-'0';
									if(s2[1]=='?'){y[1]=jj;}else y[1]=s2[1]-'0';
									if(s2[2]=='?'){y[2]=kk;}else y[2]=s2[2]-'0';
									int t1=x[0]*100+x[1]*10+x[2];
									int t2=y[0]*100+y[1]*10+y[2];
									int t3=abs(t1-t2);
									if(t3<diff){
										diff=t3;
										fori(l1){
											a[i]=x[i];
										}
										fori(l1){
											b[i]=y[i];
										}
									}
								}

							}
						}
					}
				}
			}
			fori(l1){
				cout<<a[i];
			}
			cout<<" ";
			fori(l1){
				cout<<b[i];
			}
			cout<<endl;

		}

		
		



	}

		
	

}