import math, collections

fin = open('/Users/alex/Desktop/codejam/d/D-small-attempt2.out.in', 'r')
fout = open('/Users/alex/Desktop/codejam/d/D-small-attempt2.out', 'w')

n =fin.readline().strip()
n = int(n)
def f(keys, chests):
    if chests ==[]:
        return []
    
    keysneeded = []
    possiblekeys = keys[:]
    for chest in chests:
        (number, key, keysin) = chest
        if len(keysin)>1:
            allones=False
        keysneeded.append(key)
        possiblekeys.extend(keysin)
    keysneeded = collections.Counter(keysneeded)
    possiblekeys = collections.Counter(possiblekeys)
    possiblekeys.subtract(keysneeded)
    for (i, j) in possiblekeys.items():
        if j<0:
            return False

    for chest in chests:
        (number, key, keysin) = chest
        if key in keysin and key not in keys:
            ok = False
            for chest2 in chests:
                if chest!=chest2:
                    (number2, key2, keysin2) = chest2
                    if key in keysin2:
                        ok = True
            if ok==False:
                return False



    for chest in chests:
        (number, key, keysin) = chest
        if key in keys:
            keyscopy = keys[:]
            chestcopy = chests[:]
            keyscopy.remove(key)
            keyscopy.extend(keysin)
            chestcopy.remove(chest)
            test = f(keyscopy, chestcopy)
            if not test==False:
                return [str(number)]+test

    return False

for i in range(n):
    k,n = fin.readline().strip().split(" ")
    k, n = int(k), int(n)
    keys = [int(k) for k in fin.readline().strip().split(" ")]
    chests = []
    for j in range(n):
        chestdata = [int(k) for k in fin.readline().strip().split(" ")]
        chests.append((j+1, chestdata[0], chestdata[2:]))

    answer = f(keys, chests)
    if answer:
        realanswer = "Case #"+str(i+1)+": " + " ".join(answer)+"\n"
    else:
        realanswer = "Case #"+ str(i+1) +": IMPOSSIBLE\n"
    print realanswer
    fout.write(realanswer)

fin.close()
fout.close()
