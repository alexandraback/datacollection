__author__ = 'peter'



results=[]
with open("b.in","r") as inF:
    T= int(inF.readline())
    for iT in range(0,T):
        sp= map(float,inF.readline().split())
        cfc= sp[0]
        xcps=sp[1]
        cToGo= sp[2]
        cps=2.0
        t=0.0

        while True:
            tToGo= cToGo/cps
            tToF= cfc/cps
            tToGo2= tToF+cToGo/(cps+xcps)
            if tToGo2<tToGo:
                cps+=xcps
                t+=tToF
            else:
                t+=tToGo
                break
        results.append(t)

for iRes in range(0,len(results)):
    print "Case #%d: %.7f"%(iRes+1,results[iRes])