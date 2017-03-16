#!/usr/bin/env python

import sys

def SolveHelper(keyring, chests, specialkeys, keytypes, acc):
    #print acc
    if not keyring:
        pass
    for chest_num in sorted(chests.keys()):
        if chests[chest_num][0] in keyring:
            new_keyring = keyring.copy()
            new_keyring[chests[chest_num][0]] -= 1
            new_chests = chests.copy()
            x = new_chests[chest_num][1]
            for j in x:
                if j in new_keyring: new_keyring[j]+=1
                else: new_keyring[j]=1
            if new_keyring[chests[chest_num][0]] == 0:
                del new_keyring[chests[chest_num][0]]
            del new_chests[chest_num]
            new_specialkeys = specialkeys.copy()
            new_keytypes = keytypes.copy()
            

            flag = True
            new_keytypes[chests[chest_num][0]] -= 1
            if new_keytypes[chests[chest_num][0]] == 0:
                del new_keytypes[chests[chest_num][0]]

            if chests[chest_num][0] in new_specialkeys:
                for y in x:
                    if chests[chest_num][0]==y: new_specialkeys[chests[chest_num][0]] -= 1
            if chests[chest_num][0] in new_specialkeys and new_specialkeys[chests[chest_num][0]] == 0:
                del new_specialkeys[chests[chest_num][0]]
            
            if chests[chest_num][0] in new_specialkeys:
                if (chests[chest_num][0] not in new_keyring and new_specialkeys[chests[chest_num][0]]==new_keytypes[chests[chest_num][0]]):
                    flag = False
                    #print "Upyachka for chest", chest_num, "key",chests[chest_num][0], new_specialkeys, new_keytypes
                    
                   
            if flag: SolveHelper(new_keyring, new_chests, new_specialkeys, new_keytypes, acc+str(chest_num)+' ')
    if not chests:
        #print acc
        raise NameError(acc)
            
def Solve(keyring, chests, specialkeys, keytypes):
    #print keyring
    #print chests
    x = 'IMPOSSIBLE '
    try:
        SolveHelper(keyring, chests, specialkeys, keytypes, '')
    except NameError as e:
        x = e.args[0]
    #print "RESULT", x
    return x[:-1]

def main():
    infile = open(sys.argv[1], 'r')
    inp = infile.readlines()
    T = int(inp[0])
    strn = 1
    for i in range(T):
        #sys.stderr.write("Processing case "+str(i+1)+"\n")
        (K, N) = map(int, inp[strn].split())
        strn += 1
        keyring = {}
        x = map(int, inp[strn].split())
        for j in x:
            if j in keyring: keyring[j]+=1
            else: keyring[j]=1
        keytypes = keyring.copy()
        locktypes = {}
        specialkeys = {}
        strn += 1
        chests = {}
        for j in range(1, N+1):
            x = map(int, inp[strn].split())
            chests[j] = [x[0], x[2:]]
            
            for key in x[2:]:
                if key in keytypes: keytypes[key]+=1
                else: keytypes[key]=1
                if key == x[0]:
                    if key in specialkeys: specialkeys[key]+=1
                    else: specialkeys[key]=1
                    
            if x[0] in locktypes: locktypes[x[0]] += 1
            else: locktypes[x[0]] = 1

            strn += 1

        #print "keytypes", keytypes
        #print "locktypes", locktypes
        for key in locktypes:
            if key not in keytypes or keytypes[key] < locktypes[key]:
                #print "Upyachka", key, "is not enough"
                keyring={}
                break
        print 'Case #'+str(i+1)+': '+Solve(keyring, chests, specialkeys, keytypes)



if __name__=='__main__':
    main()
