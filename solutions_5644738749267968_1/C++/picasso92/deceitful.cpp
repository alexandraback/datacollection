#include<cstdio>
#include<algorithm>

using namespace std;

int TC,N;
pair<float,int> Data[1000],Data2[1000];
pair<float,int> DataCopy[1000],DataCopy2[1000];

int a,b,c,status;
int countWar,countDWar;

int main()
 {
 	scanf("%d",&TC);
 	for(a = 1; a <= TC; a++)
 	{
 		countWar = 0;
 		countDWar = 0;
 		
 		scanf("%d",&N);
 		
 		// For Naomi Blocks
		for(b = 0; b < N; b++)
 		{
 		  scanf("%f",&Data[b].first);
		  Data[b].second = 0;				// Set Belum Dipakai	
 			
 		  // Copy
 		  DataCopy[b].first = Data[b].first;
		  DataCopy[b].second = 0;	
		}
 		
 		// For Ken Blocks
 		for(b = 0; b < N; b++)
 		{
 		  scanf("%f",&Data2[b].first);
		   Data2[b].second = 0;				// Set Belum Dipakai	
 			
 			// Copy
 			DataCopy2[b].first = Data2[b].first;
			DataCopy2[b].second = 0;
		}
 			
		 // Untuk War
		 sort(Data, Data + N);
		 sort(Data2, Data2 + N);
 		 for(b = 0; b < N; b++)
 		 {
 		 	status = 0;
 		 	for(c = 0; c < N; c++)
 		 	{
 		 		if(Data[b].first < Data2[c].first && Data2[c].second == 0)
 		 		{
 		 			status = 1;
 		 			Data2[c].second = 1;
 		 			break;
 		 		}
 		 	}
 		 	if(!status) countWar++;
 		 }
 		 
 		 // Untuk Deceitful War
 		 sort(DataCopy, DataCopy + N);
		 sort(DataCopy2, DataCopy2 + N);
 		 for(b = 0; b < N; b++)
 		 {
 		 	status = 0;
 		 	for(c = 0; c < N; c++)
 		 	{
 		 		if(DataCopy[b].first > DataCopy2[c].first && DataCopy2[c].second == 0)
 		 		{
 		 		//	printf("%f %f\n",DataCopy[b].first,DataCopy2[c].first);
 		 			status = 1;
 		 			DataCopy2[c].second = 1;
 		 			countDWar++;
 		 			break;
 		 		}
 		 	}
 		 }
 		 

 		 // Print Untuk War
 		 printf("Case #%d: %d %d\n",a,countDWar,countWar);
 	}
 	return 0;
 }
