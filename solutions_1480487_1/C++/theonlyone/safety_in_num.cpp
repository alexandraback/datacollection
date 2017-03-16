#include<iostream>
#include<fstream>
#include<string>
#include <vector>

#define SORT(x) sort((x).begin() , (x).end())

using namespace std;


void sort(int *array,int *pos,int n)
{
	int i,j,k;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
		{
			if(array[i]>array[j])
			{
				k=array[i];
				array[i]=array[j];
				array[j]=k;
				k=pos[i];
				pos[i]=pos[j];
				pos[j]=k;
			}
		}
}

void sort1(int *array,float *pos,int n)
{
	int i,j,k;
	float temp;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
		{
			if(array[i]>array[j])
			{
				k=array[i];
				array[i]=array[j];
				array[j]=k;
				temp=pos[i];
				pos[i]=pos[j];
				pos[j]=temp;
			}
		}
}

void fileIO()
{
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
}
main()
{
	fileIO();
	
	int t,n,i,j,k,l;
	int score[200],sum,spent,temp,pre_score,pos[200];
	double min, ans[200];
	cin >>t;
	
	for(l=1;l<=t;l++)
	{
		cin >> n;
		sum=0;
		for(i=0;i<n;i++)
		{
			cin >> score[i];
			sum+=score[i];
			pos[i]=i;
		}
		//cout << "sum" << sum;
		sort(score,pos,n);
		cout  << "Case #" << l << ": ";
		//for(j=0;j<n;j++) cout<< score[j] << " "; 
		for(j=0;j<n;j++)
		{
			spent=0;
			for(k=0;k<j;k++)
				spent+=score[j]-score[k];
			if(spent>=sum)
				ans[pos[j]]= 0.00000;
			else
			{
				temp=j+1;
				pre_score=score[j];
				while(pre_score==score[temp])
				{
					if(temp==n) break;
					temp++;
				}
				while(spent<sum)
				{
					if((spent+temp)>=sum) break;
					spent+=temp;
					pre_score++;
					while(pre_score==score[temp])
					{
						if(temp==n) break;
						temp++;
					}
				}
				//if(l==8)
					//cout << pre_score << " " << temp <<" " << sum <<" "  << spent << "" ;
				min=pre_score-score[j]+(sum-spent)/(double)temp;
				ans[pos[j]]= min/(double)sum*100;
			}
		}
		//sort1(pos,ans,n);
		double summ=0.0;
		for(j=0;j<n;j++) {
				printf("%.6f ",ans[j]);//cout<< ans[j] << " "; 
				summ = summ + ans[j];
		}
		//cout <<" "<<summ<< "\n";
		cout << "\n";
	}

}
