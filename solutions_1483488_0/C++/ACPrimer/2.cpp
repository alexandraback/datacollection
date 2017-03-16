#include <stdio.h>
int a[10],cnt;
void cycle(int x)
{
	cnt=0;
	if(x<10) return;
	if(x<100)
	{
		a[cnt++]=(x%10)*10+x/10;
	}
	else
	{
		a[cnt++]=(x%100)*10+x/100;
		a[cnt++]=(x%10)*100+x/10;
	}
}
int main()
{
	FILE *fout=fopen("b.txt","w+");
	int i,j,x,y,ncase=0;
	int T,ans;
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		scanf("%d%d",&x,&y);
		fprintf(fout,"Case #%d: ",++ncase);
		for(i=x;i<=y;i++)
		{
			cycle(i);
			for(j=0;j<cnt;j++) if(a[j]!=i && a[j]>=x && a[j]<=y)
				ans++;
		}
		fprintf(fout,"%d\n",ans/2);
	}
	return 0;
}
/*
50
173 951
107 992
711 952
189 950
10 10
177 979
102 948
161 997
103 974
106 980
185 999
73 90
179 960
114 911
181 969
161 990
10 99
131 952
184 978
129 922
188 964
115 915
139 931
62 96
126 991
149 918
184 916
1 5
148 967
151 918
125 935
148 910
139 917
100 999
366 366
559 718
103 953
131 909
146 991
177 926
189 918
110 989
169 948
156 970
100 101
159 984
110 923
114 985
740 740
139 909
*/