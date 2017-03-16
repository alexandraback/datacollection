import sys
inp = open("B-large.in","r")
out = open("bl.out","w")

def readline(f):
    return f.readline().strip()

n = int(readline(inp))

for case in range(n):
    s = readline(inp).split(" ")
    co = s[0]
    jo = s[1]
    c = co
    j = jo
    leng = len(c)

    def calc_min(s):
        x = 0
        for i in range(len(s)):
            if s[i] != "?":
                x += exp(len(s),i,int(s[i]))
        return x

    def exp(l,i,x):
        return 10**(l-i-1) * x
    
    def calc_max(s):
        x = 0
        for i in range(len(s)):
            if s[i] != "?":
                x += exp(len(s),i,int(s[i]))
            else:
                x += exp(len(s),i,9)
        return x
    
    def index(num,i):
        return int(str(num)[i])
    
    def nexte(s,num):
        x = 0
        ranger = range(len(s))
        ranger.reverse()
        for i in ranger:
            if s[i] == "?":
                s = s[0:i] + "9" + s[i+1:]
                return (s,num + exp(len(s),i,9))
        return False

    def nexts(s,num,o,os):
        x = 0
        ranger = range(len(s))
        ranger.reverse()
        for i in ranger:
            if s[i] == "?":
                other = calc_min(o[i])-1
                s = s[0:i] + str(other) + s[i+1:]
                return (s,num + exp(len(s),i,other))
        return False
    
    def nextm(s,num,o,os,ori,likeb):
        index = -1
        ranger = range(len(s))
        ranger.reverse()
        for i in ranger:
            if s[i] == "?" and not likeb:
                other = calc_min(o[i])
                s = s[0:i] + str(other) + s[i+1:]
                return (s,num + exp(len(s),i,other))
            elif s[i] == "?" and likeb:
                other = calc_min(o[i])
                s = s[0:i] + str(other) + s[i+1:]
                index = i
                break
        if index == -1:
            return False
        for i in ranger:
            if i <= index:
                break
            elif ori[i] == "?":
                #print "HERE"
                s = s[0:i] + "?" + s[i+1:]
        return (s,calc_min(s))

    def nextb(s,num,o,os,ori):
        index = -1
        ranger = range(len(s))
        ranger.reverse()
        for i in ranger:
            if s[i] == "?":
                other = calc_min(o[i])+1
                s = s[0:i] + str(other) + s[i+1:]
                index = i
                break
        if index == -1:
            return False
        for i in ranger:
            if i <= index:
                break
            elif ori[i] == "?":
                #print "HERE"
                s = s[0:i] + "?" + s[i+1:]

        return (s,calc_min(s))

    def equal(a,b):
        ans = ""
        for i in range(len(a)):
            if a[i] != "?" and b[i] != "?":
                return False
            elif a[i] == "?" and b[i] == "?":
                ans = ans + "0"
            elif a[i] == "?":
                ans = ans + b[i]
            else:
                ans = ans + a[i]
        return ans
    
    cmin = calc_min(c)
    jmin = calc_min(j)

    store = (sys.maxint,c,j)
    thing = True
    if equal(c,j) != False:
        cans = equal(c,j)
        jans = equal(c,j)
        thing = False
    
    while thing:
        #print c,j,cmin,jmin
        if cmin == jmin:
            cans = c
            jans = j
            break
        elif cmin > jmin:
            dif = cmin - jmin
            ran = nexte(j,jmin)
            if ran == False:
                if dif < store[0]:
                    cans = c
                    jans = j
                    break
                else:
                    cans = store[1]
                    jans = store[2]
                    break
            new_j = ran[0]
            new_jmin = ran[1]
            if new_jmin - cmin > 0:
                ran2 = nextm(j,jmin,c,cmin,jo,False)
                new_j2 = ran2[0]
                new_jmin2 = ran2[1]
                if cmin - new_jmin2 < 0:
                    ran2 = nexts(j,jmin,c,cmin)
                    new_j2 = ran2[0]
                    new_jmin2 = ran2[1]
                    if cmin - new_jmin2 < store[0]:
                        store = (cmin-new_jmin2,c,new_j2)
                    ran3 = nextm(j,jmin,c,cmin,jo,True)
                else:
                    if cmin - new_jmin2 < store[0]:
                        store = (cmin-new_jmin2,c,new_j2)
                    ran3 = nextb(j,jmin,c,cmin,jo)
                j = ran3[0]
                jmin = ran3[1]
            else:
                j = new_j
                jmin = new_jmin
        elif cmin < jmin:
            dif = jmin - cmin
            ran = nexte(c,cmin)
            if ran == False:
                if dif < store[0]:
                    cans = c
                    jans = j
                    break
                else:
                    cans = store[1]
                    jans = store[2]
                    break
            new_c = ran[0]
            new_cmin = ran[1]
            if new_cmin - jmin > 0:
                ran2 = nextm(c,cmin,j,jmin,co,False)
                new_c2 = ran2[0]
                new_cmin2 = ran2[1]
                if jmin - new_cmin2 < 0:
                    ran2 = nexts(c,cmin,j,jmin)
                    new_c2 = ran2[0]
                    new_cmin2 = ran2[1]
                    if jmin - new_cmin2 < store[0]:
                        store = (jmin-new_cmin2,new_c2,j)
                    ran3 = nextm(c,cmin,j,jmin,co,True)
                else:
                    if jmin - new_cmin2 < store[0]:
                        store = (jmin-new_cmin2,new_c2,j)
                    ran3 = nextb(c,cmin,j,jmin,co)

                c = ran3[0]
                cmin = ran3[1]
            else:
                c = new_c
                cmin = new_cmin

    cans = cans.replace("?","0")
    jans = jans.replace("?","0")
                
    out.write("Case #%d: %s %s\n" % (case+1,cans,jans))

inp.close()
out.close()
