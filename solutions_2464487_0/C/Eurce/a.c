unsigned long long r,x,y,t,e;

main()
{
	scanf("%*d");
	while(~scanf("%llu%llu",&r,&t))
	{
		y=0;
		e=(r+1)*(r+1)-r*r;
		while(t>=e)
		{
			y++;
			t-=e;
			r++;
			r++;
			e=(r+1)*(r+1)-r*r;
		}
		printf("Case #%llu: %llu\n",++x,y);
	}
}
