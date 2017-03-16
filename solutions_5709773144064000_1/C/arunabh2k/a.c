#include <stdio.h>

int main()
{
    typedef long double long_double_t;

	int nc, notc;
	scanf("%d", &notc);
	
	for(nc=1;nc<=notc;nc++)
	{
        long_double_t c, f, x;
        scanf("%Lf %Lf %Lf", &c, &f, &x);
        //printf("%Lf %Lf %Lf", c, f, x);
        long_double_t min = x/2;
        long_double_t base = 0;
        int i = 0;
        while(1)
        {
            base += c/(2+(i*f));
            long_double_t cmp = x/(2+((1+i)*f));
            long_double_t tmin = base + cmp;
            if(tmin > min)
            {
                break;
            }
            min = tmin;
            i++;
        }
        printf("Case #%d: %.7Lf\n", nc, min);
	}
    return 0;
}

