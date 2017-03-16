#!/usr/bin/env python
import decimal
f = open('B-large.in','r')
lines = f.readlines()
f.close()
tests = int(lines.pop(0).strip())



for test in range(1,tests+1):
    cookie_rate = decimal.Decimal(2.0)
    cookies = 0
    sum_time=decimal.Decimal(0)
    C,F,X = (tuple([decimal.Decimal(x) for x in lines.pop(0).strip().split(" ")]))
    while cookies<X:
        X_time = X/cookie_rate
        X_time_with_farm = C/cookie_rate + X/(cookie_rate+F)
        if (X_time<=X_time_with_farm):
            cookies = X
            sum_time+=X_time
        else:
            sum_time = sum_time+C/cookie_rate
            cookie_rate +=F
    print("Case #%s: %s" % (test,"{:10.7f}".format(sum_time)))