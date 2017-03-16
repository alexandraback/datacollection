myFile = open("B-small-attempt4.in", "r")

T = int(myFile.readline())
levels = list()
onestars = list()
twostars = list()

print T

while myFile:
    try:
        levels.append(int(myFile.readline()))
        onestars.append(list())
        twostars.append(list())
        for i in xrange(levels[-1]):
            myLine = myFile.readline()
            li = myLine.split()
            a,b = int(li[0]), int(li[1])
            onestars[-1].append(a)
            twostars[-1].append(b)
    except:
        break
myFile.close()

outputFile = open('kingdom.out','w')

for casenum,(ones,twos) in enumerate(zip(onestars,twostars)):
    ones = [(j,i) for i,j in enumerate(ones)]
    ones.sort(reverse=True)
    twos = [(j,i) for i,j in enumerate(twos)]
    twos.sort(reverse=True)
    stars = 0
    tries = 0
    completed = set()
    completed1 = set()
    fail = False
    while twos and not fail:
        trytwo, level = twos.pop()
        if trytwo <= stars:
            if level in completed1:
                stars += 1
            else:
                stars += 2
            tries += 1
            completed.add(level)
        else:
            twos.append((trytwo,level))
            while ones:
                tryone, level = ones.pop()
                if level in completed:
                    continue
                elif tryone<=stars:
                    stars += 1
                    tries += 1
                    completed1.add(level)
                    break
            else:
                fail = True
    result = 'Too Bad' if fail else str(tries)
    outputFile.write('Case #'+str(casenum+1)+': '+result+'\n')
    outputFile.flush()

outputFile.close()
