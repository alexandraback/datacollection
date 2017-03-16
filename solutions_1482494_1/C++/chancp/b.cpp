
//Problem B. 

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <cmath>

using namespace std;

int n;
int res;
int s1[1000];
int s2[1000];
int r1[1000];
int r2[1000];
int ri1,ri2;
int complete1[1000];
int complete2[1000];
int ok;

struct myclass1 {
  bool operator() (int i,int j) { 
	  if (s1[i]==s1[j]) return s2[i]>s2[j];
	  return (s1[i]<s1[j]);
  }
} myobject1;
struct myclass2 {
  bool operator() (int i,int j) { 
	  if (s2[i]==s2[j]) return s1[i]>s1[j];
	  return (s2[i]<s2[j]);
  }
} myobject2;

void compute(){
	int i,j,k,m;
	ok=0;
	
	for (i=0;i<n;i++){
		r1[i]=i; r2[i]=i; complete1[i]=0; complete2[i]=0;
	}
	ri1=0; ri2=0;
	sort(r1,r1+n,myobject1);
	sort(r2,r2+n,myobject2);

	res=0;
	k=0;
	while (1){
		if (ri2>=n) {
			ok=1;
			break;
		}
		j=r2[ri2];
		if (s2[j]<=k){
			if (complete1[j]) k+=1;
			else k+=2;
			complete1[j]=1;
			complete2[j]=1;
			res++;
			ri2++;
			//cout<<"2:"<<j<<","<<k<<endl;
			continue;
		}
		if (ri1<n){
			/*
			j=r1[ri1];
			if (s1[j]<=k && complete2[j]==0 && complete1[j]==0){
				complete1[j]=1;
				res++;
				ri1++;
				k++;
				//cout<<"1:"<<j<<","<<k<<endl;
				continue;
			}else{
				ri1++;
				continue;
			}
			*/
			j=-1;
			for (m=0;m<n;m++){
				if (complete1[m]==0 && s1[m]<=k){
					if (j==-1) j=m;
					else if (s2[m]>s2[j]) j=m;
				}
			}
			if (j>=0){
				complete1[j]=1;
				res++;
				ri1++;
				k++;
				//cout<<"1:"<<j<<","<<k<<endl;
				continue;
			}
		}
		break;
	}
}

int main(){
	int t;
	int i,j,k;

	cin>>t;
	for (i=0;i<t;i++){
		cin>>n;
		for (j=0;j<n;j++) cin>>s1[j]>>s2[j];
	
		compute();
		cout<<"Case #"<<(i+1)<<": ";
		if (!ok) cout<<"Too Bad";
		else cout<<res;
		//cout<<"\t"<<n<<"\t"<<(res-n);
		cout<<endl;
		//for (j=0;j<n;j++) cout<<rpi[j]<<endl;
		//for (j=0;j<n;j++) printf("%f %f %f %.10f\n",wp[j],owp[j],oowp[j],rpi[j]);
	}
}
