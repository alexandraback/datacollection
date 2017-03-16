#! /usr/bin/env python
import sys, re
import operator as op
import math

""" START TEMPLATE JCHAOISAAC """

# some reading functions
lolfile = open(sys.argv[1]) # open file
getline = lambda: lolfile.readline().strip()
gettoken = lambda: re.split("\s+", getline())
getint = lambda: int(getline())
getfloats = lambda: map(float, gettoken())
getints = lambda: map(int, gettoken())


""" END TEMPLATE JCHAOISAAC """

# global data

def quad(a, b, c):
    d = b * b - 4 * a * c
    if d < 0: return None
    sd = math.sqrt(d)
    x = (-b + sd) / (2.0 * a)
    #if abs(-b - sd) < 0.0000001 and b > 0: return 0
    return x

# global data

[T] = getints()
for cases in xrange(1, T + 1): # loop over cases
    ans = 0
    # main

    print "Case #%d:" % (cases)


    (D, N, A) = gettoken()
    D, N, A = float(D), int(N), int(A)

    car = []
    v = []
    pt, px = None, None
    for n in xrange(N):
        (t, x) = getfloats()
        car.append((t, x))
        if pt != None:
            v.append((x - px) / float(t - pt))
        pt, px = t, x
    v.append(0.0)

    ass = getfloats()
    for a in ass:
        myv = 0.0
        myx = 0.0
        # SUBCASE
        lc = len(car)
        tt = 0
        for i in xrange(lc):
            #print '   enter ', tt, myx, myv
            carv = v[i]
            (cart, carx) = car[i]

            qa = 0.5 * a
            qb = myv - carv
            qc = myx - carx

            tsol = quad(qa, qb, qc)
            #print '    ', tsol
            ha = False
            if (i + 1 < lc) and tsol > car[i + 1][0]:
                tsol = car[i + 1][0]
                ha = True
                #print "lol nice  ", car[i+1]

            myxp = myx + (myv + qa * tsol) * tsol
            #print tsol, myxp

            if myxp >= D:
                tsol2 = quad(qa, myv, myx - D)
                #print "    ", qa, myv, myx - D
                #print "hey...", tsol2
                if tsol2 != None:
                    tt += tsol2
                    break
            
            #print '        a   ', myxp, carx + tsol* carv, i + 1, lc
            if (i + 1 < lc) and abs(myxp - (carx + tsol * carv)) < 0.0000001:
                if car[i + 1][1] > D:
                    tt += tsol + (D - myxp) / carv
                    break
                tt, myx = car[i + 1]
                myv = v[i]
                #print '  oh maybe why i brokes'
            else:
                myx = myxp
                myv += a * tsol
                tt += tsol
                #print myx, myv, tt, tsol

        print "%f" % (tt) # answer output
        #break
        

    # main
