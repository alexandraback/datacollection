def dowar(naomi, ken):
    warscore = 0
    for i in range(0, len(naomi)):
        size = naomi[i]
        found=False
        for j in range(0, len(ken)):
            if ken[j]>size:
                found=True
                del ken[j]
                break
        if found==False:
            warscore+=(len(naomi)-i)
            return warscore
    return warscore

def dodeceit(naomi, ken):
    score = 0
    while len(naomi)>0:
        if naomi[0]>ken[0]:
            score+=1
            del naomi[0]
            del ken[0]
        else:
            del naomi[0]
            del ken[len(ken)-1]
    return score

infile = open('dsmall.txt', 'r')
outfile = open('dout.txt', 'w')

raw = infile.readline()
t = int(raw.rstrip())
for z in range(1, t+1):
    print("case", z)
    raw = infile.readline()
    naomi = infile.readline()
    naomi = naomi.split()
    ken = infile.readline()
    ken = ken.split()
    naomi = [float(i) for i in naomi]
    ken = [float(i) for i in ken]
    naomi = sorted(naomi)
    ken = sorted(ken)
    ken1 = [i for i in ken]
    warwin = dowar(naomi, ken)
    deceitwin = dodeceit(naomi, ken1)
    outline = "Case #"+str(z)+": "+str(deceitwin)+" "+str(warwin)+'\n'
    outfile.write(outline)
outfile.close()
