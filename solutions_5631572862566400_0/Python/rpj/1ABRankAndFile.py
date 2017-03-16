def getMissingLst(lst):
    outLst = []
    for i in lst:
        if i in outLst:
            outLst.remove(i)
        else:
            outLst.append(i)
    return sorted([int(i) for i in outLst])

inputNb, sizeNb, caseNb = None, 0, 0
lst = []
case = 'large'
outputFile = open(r'C:\Users\Remi\Code\Data\1A\B-%s.out' % case, 'w')
for line in open(r'C:\Users\Remi\Code\Data\1A\B-%s.in' % case):
    if line.strip() == '':
        break

    if not inputNb:
        inputNb = int(line)
        continue
    if sizeNb == 0:
        sizeNb = 2*int(line)-1
        caseNb += 1
        continue

    lst.extend(line.strip().split(' '))
    sizeNb -= 1
    if sizeNb == 0:
        #print(getMissingLst(lst))
        outputFile.write('Case #%s: %s\n' % (caseNb, ' '.join([str(i) for i in getMissingLst(lst)])))
        lst = []
outputFile.close()