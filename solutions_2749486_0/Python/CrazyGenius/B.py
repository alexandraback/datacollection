cas = int(raw_input().strip())

for cc in range(1,cas+1):
    print 'Case #' + str(cc) + ':',
    inp = raw_input().strip().split()
    x = int(inp[0])
    y = int(inp[1])
    posx = 0
    posy = 0
    j = 1
    ans = ''
    if(x != 0):
        if(x > 0):
            while(j*(j+1)/2 <= x):
                ans += 'E'
                j += 1
            posx = j*(j-1)/2
            while(posx < x):
                ans += 'WE'
                j += 2
                posx += 1
        else:
            x *= -1
            while(j*(j+1)/2 <= x):
                ans += 'W'
                j += 1
            posx = j*(j-1)/2
            while(posx < x):
                ans += 'EW'
                j += 2
                posx += 1
    if(y != 0):
        if(y > 0):
            while(posy+j <= y):
                ans += 'N'
                posy += j
                j += 1
            while(posy < y):
                ans += 'SN'
                j += 2
                posy += 1
        else:
            y *= -1
            while(posy+j <= y):
                ans += 'S'
                posy += j
                j += 1
            while(posy < y):
                ans += 'NS'
                j += 2
                posy += 1
    print ans
