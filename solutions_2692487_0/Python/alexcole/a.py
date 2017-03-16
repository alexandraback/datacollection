
fin = open('/Users/alex/Desktop/codejam2/a/A-small-attempt1.in', 'r')
fout = open('/Users/alex/Desktop/codejam2/a/A-small-attempt1-1.out', 'w')

def nummoves2(motesize, othermotes):
    if len(othermotes)==0:
        return 0
    if motesize==1:
        return len(othermotes)
    if othermotes[0] < motesize:
        return nummoves(othermotes[0]+motesize, othermotes[1:])
    return 1 + min(nummoves2(2*motesize-1, othermotes), nummoves2(motesize, othermotes[:-1]))



def nummoves(motesize, othermotes):
    if len(othermotes)==0:
        return 0
    if motesize==1:
        return len(othermotes)
    if othermotes[0] < motesize:
        return nummoves(othermotes[0]+motesize, othermotes[1:])
    return 1 + nummoves(2*motesize-1, othermotes)

def actualnummoves(motesize, othermotes):
    options = []
    options.append(nummoves(motesize, othermotes))
    for i in range(1, len(othermotes)+1):
        options.append(nummoves(motesize, othermotes[:-i])+i)
    return min(options)

numcases = int(fin.readline().strip())

for case in range(numcases):
    (motesize, nummotes)= fin.readline().strip().split()
    [motesize, nummotes] = [int(motesize), int(nummotes)]
    othermotes = [int(i) for i in fin.readline().strip().split()]
    othermotes.sort()
    answer = "Case #"+str(case+1)+": "+str(nummoves2(motesize, othermotes)) + "\n"
    fout.write(answer)
    print answer, motesize, othermotes

fin.close()
fout.close()
