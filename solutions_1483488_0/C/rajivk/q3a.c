#include<stdio.h>
int n, dN[7], dA[7], dB[7], d;
int main()
{
	int t, T, i, j, id, A, A_copy, B, B_copy, ans, N_copy, n_changed[7];
	scanf("%d", &T);
	for(t=0;t<T;t++)
	{
		d=0;
		ans=0;
		scanf("%d %d", &A, &B);
		A_copy=A;
		B_copy=B;
		while(A_copy)
		{
			dA[d]=A_copy%10;
			dB[d]=B_copy%10;
			d++;
			A_copy=A_copy/10;
			B_copy=B_copy/10;
		}
		for(n=A;n<=B;n++)
		{
			N_copy=n;
			for(id=0;id<d;id++)
			{
				dN[id]=N_copy%10;
				N_copy=N_copy/10;
			}
			for(id=0;id<d-1;id++)
			{
				n_changed[id]=0;
				for(i=id;i>=0;i--)
					n_changed[id]=n_changed[id]*10+dN[i];
				for(i=d-1;i>id;i--)
					n_changed[id]=n_changed[id]*10+dN[i];
				if(n_changed[id]>n && n_changed[id]<=B)
				{
					for(j=0;j<id, n_changed[j]!=n_changed[id];j++);
					ans+=j==id;
				}
			}
		}
		printf("Case #%d: %d\n", t+1, ans);
	}
}
