__author__ = 'Victor'

filename = "A-small-attempt1 (1)"
fi = open(filename+'.in', 'r')
fo = open(filename+'.out', 'w')

t = int(next(fi))
turns = 0
for i in range(t):
    (R, C, W) = [int(x) for x in next(fi).strip().split(' ')]

    if W == 1:
        turns = R*C
    elif W == C:
        turns = R + C - 1
    else:
        turns = (C // W) * R
        turns += W
        if C % W == 0:
            turns -=1


    fo.write('Case #%d: ' %(i+1))
    fo.write('%d\n' % turns)

fi.close()
fo.close()