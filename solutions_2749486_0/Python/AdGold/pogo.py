out = open('B-out.txt', 'w')
for i,T in list(enumerate(open('B-small-attempt1.in')))[1:]:
    x,y = map(int,T.split())
    if y < 0: Y = 'NS'*abs(y)
    else: Y = 'SN'*y
    if x < 0: X = 'EW'*abs(x)
    else: X = 'WE'*x
    out.write('Case #%d: %s\n'%(i,X+Y))
