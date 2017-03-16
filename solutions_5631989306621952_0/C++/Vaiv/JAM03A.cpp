#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

int main()
{
	fstream fil;
	fil.open("C:\\Users\\vaibhav\\Desktop\\JAM1Aout.txt");
	int T, s=1;
	cin>>T;
	while(T)
	{
		char arr[1000];
		cin>>arr;
		
		
		int i=1;
		while(arr[i]!='\0')
		{
		   if(arr[i]>=arr[0])
		   {  
		   		int j=i;
		   		while(j>0)
		   		{
		   			char t=arr[j];
		   			arr[j]=arr[j-1];
		   			arr[j-1]=t;
		   			j--;
				}
		   	
		   }
			i++;
		}
		cout<<"Case #"<<s<<": "<<arr<<endl;
		fil<<"Case #"<<s<<": "<<arr<<"\n";	
		s++;
		T--;
	}
	fil.close();
}
