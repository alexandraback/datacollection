from util import *
"""
def go_2():
    can = l2[t2]
    flag = False
    while True: 
        if can <= score:
            while True:
                for i in need2[can]:
                    if i >   
"""
 


def run():
    attempt = 0
    score = 0
    done_level = 0
    l1 = sorted(list(need1.keys()))
    t1 = 0
    s1 = set(range(1, levels + 1))
    #index in level1
    l2 = sorted(list(need2.keys()))
    t2 = 0
    s2 = set(range(1, levels + 1))
    # index in leve2
    
    while len(s2) != 0:
        #first attemp level 2
        can = l2[t2]
        if can <= score:
            for k in need2[can]:
                if k in s1:
                    score += 2
                else:
                    score += 1
                s2.discard(k)
                attempt += 1
                #print("level2 {0}".format(k))
            t2 += 1
            continue
        else:
            if t1 >= len(l1):
                #print(score)
                #exit()
                return "Too Bad"
                """print(s1)
                print(s2)
                print(i)
                print(need1)
                print(need2)
                print(t1)
                print(t2)
                print(score)
                exit()"""
            can = l1[t1]
            if can > score:
                return "Too Bad"
            else:
                while need1[can] != []:
                    try_level = need1[can][0]
                    if not(try_level in s2):
                        need1[can].pop(0)
                        continue
                    else:
                        score += 1
                        s1.discard(try_level)
                        need1[can].pop(0)
                        attempt += 1
                        #print("level1 {0}".format(try_level))
                        break
                if need1[can] == []:
                    t1 += 1
    return attempt


f = input()
t = int(f)
for i in range(t):
    f = input()
    levels = int(f)
    #done = list(list(False for x in range(0, levels + 1)) for y in range(3))
   # need = list(list(-1 for x in range(0, levels + 1)) for y in range(3))
    need1 = {}
    need2 = {}
    for j in range(1, levels +1):
        f = input()
        l = [int(x) for x in f.split()]
        if l[0] in need1.keys():
            need1[l[0]].append(j)
        else:
            need1[l[0]] = [j]
        if l[1] in need2.keys():
            need2[l[1]].append(j)
        else:
            need2[l[1]] = [j] 
    #print(need1)
    #print(need2)
    result = run()
    if result == "Too Bad":
        print('Case #{0}: '.format(i+1) + result)
    else:
        print('Case #{0}: {1}'.format(i+1, result))
    


