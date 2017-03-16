import itertools as it
def getcombis(l):
    jp = str(l[0]) + str(l[1]) + 'x'
    js = str(l[0]) + 'x' + str(l[2]) 
    ps = 'x' + str(l[1]) + str(l[2])
    return [jp, js, ps]

f = open("Csmall.in",'r')
t = int(f.readline().strip())
for case in range(t):
    l = f.readline().strip().split()
    j = int(l[0])
    p = int(l[1])
    s = int(l[2])
    k = int(l[3])
    output = []
    currentj = 1
    currentp = 1
    currents = 1
    js = range(1,j+1)
    ps = range(1,p+1)
    ss = range(1,s+1)
    s = [js,ps,ss]
    possibles = it.product(*s)
    combicount = {} # syntax: etc 1x1 -> j1 and s1
    inserted = True
    while inserted:
        inserted = False
        for each in possibles:
            # get the combis first
            combis = getcombis(each)
            canput = True
            for combi in combis:
                if combi in combicount.keys() and combicount[combi] + 1 > k:
                    canput = False
                    break
            if canput:
                # put
                for combi in combis:
                    if combi not in combicount.keys():
                        combicount[combi] = 1
                    else:
                        
                        combicount[combi] += 1
                # combicount added
                out = ''
                for item in each:
                    out += str(item)
                    out += ' '
                out.strip()
                output.append(out)
                inserted = True

    print "Case #" + str(case+1) + ": " + str(len(output))
    for each in output:
        print each

f.close()
