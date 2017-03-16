int a, n;
int m[10];

int rec(int k, int s)
{ int i, r1, r2;
   
  for(i=k; i<n; ++i)
  {
    //printf("%d %d %d\n", i, m[i], s);
	if(m[i]<s)
    {
      s += m[i];
	} else
    { r1 = 1 + rec(i+1, s);
      //printf("r1 = %d\n", r1);
	  if(s<=1) return r1;
      r2 = 0;
	  while(s<=m[i])
      { s = 2*s-1;
	    ++r2;
      }
      s += m[i];
	  r2 += rec(i+1, s);
	  if(r1<r2)
      {	  
	    return r1;
	  } else
	  {	  
	    return r2;
	  }		
	} 	
  }
  
  return 0;
}

int main()
{
  int t, tt, i, j, k;  
  
  scanf("%d", &tt);
  for(t=1; t<=tt; ++t)
  {
    scanf("%d%d", &a, &n);
	for(i=0; i<n; ++i)
	  scanf("%d", &(m[i]));
	
	for(i=0; i<n-1; ++i)
	  for(j=i+1; j<n; ++j)
	    if(m[i]>m[j])
		{ 
		  k = m[i];
		  m[i] = m[j];
		  m[j] = k;
		}
    //for(i=0; i<n; ++i) printf("%d ",m[i]);
	//printf("\n");
	printf("Case #%d: %d\n", t, rec(0, a));
  }
  
  return 0;
}