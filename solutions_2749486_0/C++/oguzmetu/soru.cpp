#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;
main(){
	freopen("B-small-attempt0.in","r",stdin);
	freopen("myfile.txt","w",stdout);
	int line;
	char harf[1000000];
	int nice[5]={1,4,9,121,484};
	int puan=0;
	int yer,i,j,k,sayim,uzunluk;
	int gostergec=0,ilk,iki,x=0,y=0;
	int gostergec2=0;
	scanf("%d", &line);
	for(j=0;line>j;j++)
		{
			scanf("%d", &ilk);
			scanf("%d", &iki);
			cout<<"Case #"<<j+1<<": ";

			for(i=1;;i++)
			{
				if(x!=ilk )
				{
							if((x<ilk) && ((x+i)<=ilk))
							{
								cout<<"E";
								x+=i;
							}
							else if((x>ilk)|| ((x+i)>=ilk))	
							{
								cout<<"W";
								x-=i;

							}
				}
				else if(y!=iki)
				{
					 if((y<iki) && ((y+i)<=iki))	
					{
						cout<<"N";
						y+=i;
										
					}			
								else if((y>iki)|| ((y+i)>=iki) )	
					{
						cout<<"S";
						y-=i;
										

					}
				}
				else
					break;
			}
			if((j+1)!=line)
			cout<<endl;
			x=0;
			y=0;
		}
return 0;
}
