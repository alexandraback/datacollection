# code jam qualifier 2013 problem D

# treasure

def feasible(keys, chests):
    for i, chest in enumerate(chests):
        possible = False
        unlock = chest[1]
        if unlock in keys:
            possible = True
        if not possible:
            for j in range(len(chests)):
                if i!=j and unlock in chests[j][3]:
                    possible = True
                    break
        if not possible:
            return False
    return True
                               
        

def solve(keys, chests, solution):
    if len(chests)==0:
        return solution
    if len(keys)==0:
        return "IMPOSSIBLE"
    if not feasible(keys, chests):
        return "IMPOSSIBLE"

##    print solution
##    print keys
##    print chests
##    print 
            
    for i, chest in enumerate(chests):
        typ = chest[1]
        if typ in keys:
            newKeys = keys + chest[3]
            newKeys.remove(typ)
            answer = solve(newKeys, chests[:i] + chests[i+1:], solution + str(chest[0]) + " ")
            if answer != "IMPOSSIBLE":
                return answer
    return "IMPOSSIBLE"
    
fin = open("D-small-1.in", "r")
fout = open("D-small-1.out", "w")

t = int(fin.readline())
for testCase in xrange(t):
    print testCase+1
    k,n = map(int, fin.readline().split())

    startKeys = map(int, fin.readline().split())
    chests = []
    for i in range(n):
        keys = map(int, fin.readline().split())
        typ = keys[0]
        nkeys = keys[1]
        keys = keys[2:]
        chests.append([i+1, typ, nkeys, keys])

##    if testCase+1!=16:
##        continue
##    print startKeys
##    print chests
##    
    answer = ""
    availableKeys = startKeys[:]
    for chest in chests:
        #print chest
        availableKeys += chest[3]
    neededKeys = [chest[1] for chest in chests]
    for key in neededKeys:
        if neededKeys.count(key) > availableKeys.count(key):
            answer = "IMPOSSIBLE"
            print "short circuit, problem", testCase+1,"not enough key#", key
            break

##    print sorted(neededKeys)
##    print sorted(availableKeys)
    
    if answer != "IMPOSSIBLE":
        answer = solve(startKeys, chests, "")
    
    fout.write( "Case #" + str(testCase+1) + ": " + answer + "\n")

    print( "Case #" + str(testCase+1) + ": " + answer + "\n")
    print    

fout.close()
