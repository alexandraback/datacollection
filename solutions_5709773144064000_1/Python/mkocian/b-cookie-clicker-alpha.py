# -*- coding: utf-8 -*-


t = int(input())

for i in range(t):
    c, f, x = map(float, input().split())

    time = 0.0
    cookies = 0.0
    production = 2.0
    
    while cookies < x:
        #print(cookies)
        delta = (min(c, x) - cookies) / production
        #print("delta: " + str(delta))
        
        time += delta
        cookies += production*delta

        #print("cc: ", ((x-cookies) / production))
        #print("bc: ", ((x - (cookies - c)) / (production + f)))
        if ((x-cookies) / production) >= ((x - (cookies - c)) / (production + f)):
            cookies -= c
            production += f
        else:
            time += (x-cookies)/production
            cookies = x
            

    print("Case #" + str(i+1) + ":", time)


