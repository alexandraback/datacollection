#include <iostream>
#include <cmath>
using namespace std;
#define NUM 100001
__int64 st[NUM];
int num=0;
bool test(__int64 x){
	int i,len,p[8];
	for(len=0;x;len++){
		p[len] = x%10;
		x/=10;
	}
	for(i=0;i<len/2;i++)
		if(p[i] != p[len-1-i])return false;
	return true;
}
void check(int a[],int n)
{
	__int64 t=0,p=1;
	for(int i=0;i<n;i++){
		t += p*a[i];
		p*=10;
	}
	__int64 x=sqrt(t*1.0);
	if(x*x == t && test(x))st[num++]=t;
}
void find(){
	int i1,a[14];
	for(i1=1;i1<10;i1++){
		a[0]=i1;
		check(a,1);
	}
	for( i1=1;i1<10;i1++){
		a[0]=a[1]=i1;
		check(a,2);
	}
	for(i1=1;i1<10;i1++){
		a[0]=a[2]=i1;
		for(int i2=0;i2<10;i2++){
			a[1]=i2;
			check(a,3);
		}
	}
	for( i1=1;i1<10;i1++){
		a[0]=a[3]=i1;
		for(int i2=0;i2<10;i2++){
			a[1]=a[2]=i2;
			check(a,4);
		}
	}
	for(i1=1;i1<10;i1++){
		a[0]=a[4]=i1;
		for(int i2=0;i2<10;i2++){
			a[1]=a[3]=i2;
			for(int i3=0;i3<10;i3++){
				a[2]=i3;
				check(a,5);
			}
		}
	}
	for(i1=1;i1<10;i1++){
		a[0]=a[5]=i1;
		for(int i2=0;i2<10;i2++){
			a[1]=a[4]=i2;
			for(int i3=0;i3<10;i3++){
				a[2]=a[3]=i3;
				check(a,6);
			}
		}
	}
	for(i1=1;i1<10;i1++){
		a[0]=a[6]=i1;
		for(int i2=0;i2<10;i2++){
			a[1]=a[5]=i2;
			for(int i3=0;i3<10;i3++){
				a[2]=a[4]=i3;
				for(int i4=0;i4<10;i4++){
					a[3]=i4;
					check(a,7);
				}
			}
		}
	}
	for(i1=1;i1<10;i1++){
		a[0]=a[7]=i1;
		for(int i2=0;i2<10;i2++){
			a[1]=a[6]=i2;
			for(int i3=0;i3<10;i3++){
				a[2]=a[5]=i3;
				for(int i4=0;i4<10;i4++){
					a[3]=a[4]=i4;
					check(a,8);
				}
			}
		}
	}
	for(i1=1;i1<10;i1++){
		a[0]=a[8]=i1;
		for(int i2=0;i2<10;i2++){
			a[1]=a[7]=i2;
			for(int i3=0;i3<10;i3++){
				a[2]=a[6]=i3;
				for(int i4=0;i4<10;i4++){
					a[3]=a[5]=i4;
					for(int i5=0;i5<10;i5++){
						a[4]=i5;
						check(a,9);
					}
				}
			}
		}
	}
	for(i1=1;i1<10;i1++){
		a[0]=a[9]=i1;
		for(int i2=0;i2<10;i2++){
			a[1]=a[8]=i2;
			for(int i3=0;i3<10;i3++){
				a[2]=a[7]=i3;
				for(int i4=0;i4<10;i4++){
					a[3]=a[6]=i4;
					for(int i5=0;i5<10;i5++){
						a[4]=a[5]=i5;
						check(a,10);
					}
				}
			}
		}
	}
	for(i1=1;i1<10;i1++){
		a[0]=a[10]=i1;
		for(int i2=0;i2<10;i2++){
			a[1]=a[9]=i2;
			for(int i3=0;i3<10;i3++){
				a[2]=a[8]=i3;
				for(int i4=0;i4<10;i4++){
					a[3]=a[7]=i4;
					for(int i5=0;i5<10;i5++){
						a[4]=a[6]=i5;
						for(int i6=0;i6<10;i6++){
							a[5]=i6;
							check(a,11);
						}
					}
				}
			}
		}
	}
	for(i1=1;i1<10;i1++){
		a[0]=a[11]=i1;
		for(int i2=0;i2<10;i2++){
			a[1]=a[10]=i2;
			for(int i3=0;i3<10;i3++){
				a[2]=a[9]=i3;
				for(int i4=0;i4<10;i4++){
					a[3]=a[8]=i4;
					for(int i5=0;i5<10;i5++){
						a[4]=a[7]=i5;
						for(int i6=0;i6<10;i6++){
							a[5]=a[6]=i6;
							check(a,12);
						}
					}
				}
			}
		}
	}
	for(i1=1;i1<10;i1++){
		a[0]=a[12]=i1;
		for(int i2=0;i2<10;i2++){
			a[1]=a[11]=i2;
			for(int i3=0;i3<10;i3++){
				a[2]=a[10]=i3;
				for(int i4=0;i4<10;i4++){
					a[3]=a[9]=i4;
					for(int i5=0;i5<10;i5++){
						a[4]=a[8]=i5;
						for(int i6=0;i6<10;i6++){
							a[5]=a[7]=i6;
							for(int i7=0;i7<10;i7++){
								a[6]=i7;
								check(a,13);
							}
						}
					}
				}
			}
		}
	}
}
int search(__int64 x){
	for(int i=0;i<num;i++)
		if(st[i]>x)return i;
	return num;
}
int main(){
	//freopen("A-small-practice.in","r",stdin);
	//freopen("A-small-practice.out","w",stdout);
	int t,nt;
	__int64 m,n;
	find();
	//printf("%d %I64d\n",num,st[num-1]);
	//for(int i =0;i<num;i++)printf("%I64d\n",st[i]);printf("\n");
	scanf("%d",&t);
	for(nt = 1;nt <= t;nt ++)
	{
		scanf("%I64d%I64d",&m,&n);
		printf("Case #%d: %d\n",nt,search(n)-search(m-1));
	}
	return 0;
}