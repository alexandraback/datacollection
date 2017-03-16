#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


int main(){
  long  j, k, i, l,m, n, t, M, N, len, index;
  long lay, num, C, PD, penalty, PG, T, S, p, score;     ;
  long temp0, temp1, order,  current, flag, toplay, flag2val,flag1val, totalstars=0, starsold, ind1, ind2;
  long vec[1000][2], stars[1000];
  long level, flag1, flag2;
  //  vector <string>  dictionary, dict;
  cin >> T;
  for(t = 0; t<T; t++) {
    totalstars=0;
    starsold=-1;
    ind1=-1;
    ind2=-1;
    cin >> N;
    //    cout<<"N is "<<N<<endl;
    for (i=0;i<N;i++){
      cin>>vec[i][0]>>vec[i][1];
      //     cout<<vec[i][0]<<" and "<<vec[i][1]<<endl;
      stars[i]=0;
    }
    level=0;
    while(starsold<totalstars){
      starsold=totalstars;
      ind1=-1;
      flag1val=-1;
      for (i=0;i<N;i++){
	if (totalstars>=vec[i][1]&&stars[i]==0){
	  totalstars=totalstars+2;
	  stars[i]=2;
	  level++;
	  //	  cout<<"i am at 1 and level and star "<< i <<"is "<<level<<stars[i]<<endl;
	}
	else if (totalstars>=vec[i][1]&&stars[i]==1){
	  totalstars++;
	  stars[i]=2;
	    level++;
	    //	    cout<<"i am at 2 and level and star "<< i <<"is "<<level<<stars[i]<<endl;
	}
	else if(totalstars>=vec[i][0]&&stars[i]==0){
	  if (ind1<vec[i][1]){
	      ind1=vec[i][1];
	      flag1val=i;
	    }
	}
      }
      if (totalstars==starsold&&flag1val>=0){
	stars[flag1val]=1;
	totalstars++;
	level++;
	//	cout<<"i am at 3 and level and star "<< flag1val <<"is "<<level<<stars[flag1val]<<endl;
      }
      //      cout<<"haha totalstars is "<<totalstars<<endl;
    };
    cout << "Case #" << t+1 << ": ";    
    if (totalstars==2*N)
      cout<<level<<endl;
    else
      cout<<"Too Bad"<<endl;
  }
  return 0;
}

