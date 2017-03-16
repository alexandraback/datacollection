int t,n,x,y,b[20013][8],pro,all;


void calc(int i)
{
	if(i==n)
	{
		all++;
		if(b[x][y]) pro++;
		return;
	}
	int j,k,jj,kk;
	for(j=10006,k=6;k>0&&!b[j][k-2];k-=2);

		if(k==0)
		{
			b[j][k]=1;
			calc(i+1);
		}
		else if(!b[j-1][k-1]&&!b[j+1][k-1])
		{
			for(jj=j,kk=k;kk>0&&!b[jj-1][kk-1];jj--,kk--);
			b[jj][kk]=1;
			calc(i+1);
			b[jj][kk]=0;
			for(jj=j,kk=k;kk>0&&!b[jj+1][kk-1];jj++,kk--);
			b[jj][kk]=1;
			calc(i+1);
			b[jj][kk]=0;
		}
		else if(!b[j-1][k-1])
		{
			for(jj=j,kk=k;kk>0&&!b[jj-1][kk-1];jj--,kk--);
			b[jj][kk]=1;
			calc(i+1);
			b[jj][kk]=0;
		}
		else
		{
			for(jj=j,kk=k;kk>0&&!b[jj+1][kk-1];jj++,kk--);
			b[jj][kk]=1;
			calc(i+1);
			b[jj][kk]=0;
		}
}

main()
{
	int i,j,k;
	scanf("%*d");
	double e=1.0;
	while(~scanf("%d%d%d",&n,&x,&y))
	{
		memset(b,0,sizeof(b));
		if(y>7)
		{
			printf("Case #%d: %.7lf\n",++t,0);
			continue;
		}
		pro=all=0;
		x+=10006;
		calc(0);
		printf("Case #%d: %.7lf\n",++t,e*pro/all);
	}
}
