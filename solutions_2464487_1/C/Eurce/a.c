long long r,x,y,t,e,l,h,m;

main()
{
	scanf("%*d");
	while(~scanf("%lld%lld",&r,&t))
	{
		for(l=r,h=1ll<<60;l<h;)
		{
			m=(l+h)/2+1;
			if(r&1)
			{
				if(!(m&1)) m++;
			}
			else if(m&1) m++;
			if(t*(1.0/(1+m+r))>=1+(m-r)/2) l=m;
			else h=m-2;
		}
		y=1+(l-r)/2;
		printf("Case #%lld: %lld\n",++x,y);
	}
}
