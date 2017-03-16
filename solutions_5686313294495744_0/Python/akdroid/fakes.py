t = int(raw_input(''))

for case in range(t):
    
    d = {}
    n = int(raw_input(''))
    fakes = 0
    pairs = {}
    for i in range(n):
        w1,w2 = raw_input('').split(' ')
        pairs[w1+"_"+w2]= 0
        if w1 not in d:
            d[w1] = [1,0]
        else:
            d[w1][0] += 1
        if w2 not in d:
            d[w2] = [0,1]
        else:
            d[w2][1] += 1
    for key in d.keys():
        for key2 in d.keys():
            if True:
                if d[key][0] > 1  and d[key2][1] > 1 and key+"_"+key2 in pairs:
                    #res = min(d[key][0], d[key2][1]) 
                    fakes += 1


    print 'Case #%d:'%(case+1), fakes
    
