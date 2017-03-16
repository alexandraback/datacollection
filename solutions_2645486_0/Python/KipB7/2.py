import math

filename = r'c:\g\a\B-test.txt'
filename = r'c:\g\a\B-small-attempt0.in'
#filename = 'B-large.in'
foutname = r'c:\g\a\B-out.txt'

FILE = open(filename)
FOUT = open(foutname,"w")
T = int(FILE.readline())

def gain(Emax,R,N,V,E0,ENplus1,nest=0):
    dbg=0
    if dbg: print "nest=%d, Emax=%d, N=%d, E0=%d, EN+1=%d"%(nest,Emax,N,E0,ENplus1),"V=",V
    if E<=0 or N<=0: return 0 #no energy or no activities
    #optimize biggest:
    maxV = max(V)
    ix = V.index(maxV)

    if dbg: print "maxV=%d, ix=%d"%(maxV,ix)
    #how much energy could we possibly have for this activity ix?
    Aix = min(Emax, E0 + ix*R) #if we used no energy previously
    #how much energy can we spend on just this activity ix?
    #if after we're done, we leave Lix energy, then it can fully
    #recover desired energy for the N+1 activity
    Lix = max(0, ENplus1 - (N-ix)*R)
    #how much will we use
    Uix = Aix - Lix
    ix_gain = Uix * maxV
    if dbg: print "Aix=%d, Lix=%d, Uix=%d, ix_gain=%d"%(Aix,Lix,Uix,ix_gain)
    
    if ix>0: g_prev,lisp = gain(Emax,R,ix,V[:ix],E0,Uix,nest+1)
    else: g_prev,lisp = 0,[]
    
    if ix<N-1: g_next,lisn = gain(Emax,R,N-ix-1,V[ix+1:],Lix+R,ENplus1,nest+1)
    else: g_next,lisn = 0,[]
    
    g = ix_gain + g_prev + g_next
    lis = lisp + [Uix] + lisn
    if dbg: print ' ==>',g,lis
    return g,lis

for i in range(1,T+1):
    rawline = FILE.readline()
    E,R,N = map(int,rawline.split(' ',3))
    V = map(int,FILE.readline().split(' '))
    
    if i>0:
        #print "Case #" + str(i)+": begin E,R,N=",(E,R,N),"V=",V
        g,lis=gain(E,R,N,V,E,0)
        msg = 'Case #' + str(i) + ': ' + str(g)
        print msg
        #if i%10==1: print msg
        FOUT.write(msg + "\n")
FOUT.close()
