__author__ = 'Peter'

with open("B-small-attempt7.out","w") as outF:
    with open("B-small-attempt7.in","r") as inF:
        nt= int(inF.readline())
        for it in xrange(nt):
            k,l,s= map(int, inF.readline().split())
            keyboard=dict()
            keyString=inF.readline()
            for i in xrange(k):
                if not keyString[i] in keyboard:
                    keyboard[keyString[i]]=1.0
                else:
                    keyboard[keyString[i]]+=1.0
            word= inF.readline()
            bMax=0
            for i in xrange(s):
                if i+l<=s:
                    take=True
                    for j in xrange(l):
                        if word[(i+j)%l]!=word[j]:
                            take=False
                    if take:
                        bMax+=1
            pw=1.0
            for i in xrange(l):
                letter= word[i]
                if not letter in keyboard:
                    pw=-1
                    break
                pw*=keyboard[letter]/float(k)
            if pw==-1:
                erg=0
            else:
                erg=bMax-pw*(s-l+1)
            outF.write("Case #%d: %.10f\n"%(it+1,erg))